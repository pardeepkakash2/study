/*
 * Copyright (c) 2015 Oleksij Rempel <linux@rempel-privat.de>.
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/*
 * Notes:
 * - this driver uses pinned timer, so results will be different on
 *   on different starts. If cpu to wich the timer was pinned has less
 *   interrupts, it will produce less errors.
 */


#include <linux/init.h>
#include <linux/module.h>
#include <linux/hrtimer.h>
#include <linux/interrupt.h>
#include <linux/slab.h>

struct hrtimer_test_priv {
	struct hrtimer timer;
	struct tasklet_struct timer_tasklet;
	struct timer_list stat_timer;
	spinlock_t lock;

	/* start in the past counters */
	unsigned int pass;
	unsigned int fail;

	/* counters to big timout difference */
	unsigned int to_pass;
	unsigned int to_min_count;
	unsigned int to_max_count;

	s64 hrexp;
	s64 hrprep;

	int min_to;
	int max_to;
};

static struct hrtimer_test_priv *hr_priv;

static int timeout_us = 30;
static int latency_min_us = 10;
static int latency_max_us = 100;

module_param(timeout_us, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(timeout_us, "Timeout for hrtimer callback");
module_param(latency_min_us, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(latency_min_us, "Minimal expexted trigger dealy");
module_param(latency_max_us, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(latency_max_us, "Maximal expexted trigger dealy");

static void hrtest_print_stats(struct hrtimer_test_priv *priv)
{
	pr_info("hrtimer test stats: (start in the past) pass: %u, fail %u\n", priv->pass, priv->fail);
	pr_info("hrtimer test stats: (big timout errata) max to: %i, min to: %i, max count: %u, min count %u, to pass %u\n",
		priv->max_to, priv->min_to, priv->to_max_count, priv->to_min_count, priv->to_pass);
}

static int hrtest_stop_timer(struct hrtimer_test_priv *priv)
{
	hrtimer_cancel(&priv->timer);

	return 0;
}

static int hrtest_start_timer(struct hrtimer_test_priv *priv)
{
	ktime_t tout;
	unsigned long flags;

	/* just in case it is still running */
	hrtest_stop_timer(priv);

	tout = ktime_set(0, timeout_us * 1000);

	/* we are in interrupt context, so just locking should be enough */
	spin_lock_irqsave(&priv->lock, flags);
	hrtimer_start(&priv->timer, tout, HRTIMER_MODE_REL_PINNED);

        priv->hrexp = hrtimer_get_expires_ns(&priv->timer);
        priv->hrprep = ktime_to_ns(hrtimer_cb_get_time(&priv->timer));

	if (priv->hrexp < priv->hrprep) {
		priv->fail++;
		pr_warn("%s: warning! expiration time is in the past: now = %lld, exp = %lld. Stat: ok: %i, nok: %i\n",
			__func__, priv->hrprep, priv->hrexp, priv->pass, priv->fail);
	} else
		priv->pass++;

	spin_unlock_irqrestore(&priv->lock, flags);

	return 0;
}

static void hrtimer_test_tasklet_cb(unsigned long data)
{
	struct hrtimer_test_priv *priv = (struct hrtimer_test_priv *)data;

	hrtest_start_timer(priv);
}

static enum hrtimer_restart hrtimer_test_cb(struct hrtimer *timer)
{
	struct hrtimer_test_priv *priv =
			container_of(timer, struct hrtimer_test_priv, timer);
	int timeout =
		(int)(ktime_to_ns(hrtimer_cb_get_time(&priv->timer)) - priv->hrprep) / 1000;

	if (timeout < (timeout_us - latency_min_us)
			|| (timeout_us + latency_max_us) < timeout) {
		int min = timeout_us - latency_min_us;
		int max = timeout_us + latency_max_us;

		pr_warn("warning! timeout is: %i, expected: %i min: %i, max: %i\n",
			timeout, timeout_us, min, max);


		if (timeout < min)
			priv->to_min_count++;
		else
			priv->to_max_count++;

		if (timeout > priv->max_to)
			priv->max_to = timeout;
		else if (timeout < priv->min_to)
			priv->min_to = timeout;
	} else
		priv->to_pass++;

	tasklet_schedule(&priv->timer_tasklet);

	return HRTIMER_NORESTART;
}

static void hrtimer_test_stat_cb(unsigned long data)
{
	struct hrtimer_test_priv *priv = (struct hrtimer_test_priv *)data;

	hrtest_print_stats(priv);
	mod_timer(&priv->stat_timer, jiffies + (120 * HZ));
}

static int hrtimer_test_init(void)
{
	struct hrtimer_test_priv *priv;
	pr_info("%s\n",__func__);

	priv = kzalloc(sizeof(*hr_priv), GFP_KERNEL);
	if (!priv)
		return -ENOMEM;

	hr_priv = priv;

	priv->min_to = timeout_us;
	priv->max_to = timeout_us;
	spin_lock_init(&priv->lock);

	tasklet_init(&priv->timer_tasklet, hrtimer_test_tasklet_cb,
			(unsigned long)priv);

	hrtimer_init(&priv->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	priv->timer.function = hrtimer_test_cb;

	hrtest_start_timer(priv);

	setup_timer(&priv->stat_timer, hrtimer_test_stat_cb,
			(unsigned long)priv);
	mod_timer(&priv->stat_timer, jiffies + (1 * HZ));

	return 0;
}

static void hrtimer_test_exit(void)
{
	hrtest_stop_timer(hr_priv);
	tasklet_kill(&hr_priv->timer_tasklet);
	del_singleshot_timer_sync(&hr_priv->stat_timer);
	kfree(hr_priv);
	pr_info("%s\n",__func__);
}

module_init(hrtimer_test_init);
module_exit(hrtimer_test_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Oleksij Rempel <linux@rempel-privat.de>");
MODULE_DESCRIPTION("hrtimer test module");
