/* gcc -E macro.c -o macro.i
 * gcc -S macro.c -o macro.i
*/

#include <stdio.h>

#define SINGLE_RELEASE(ci_prefix_) \
int ci_prefix_ ## open(inode, file)\
{\
	int res = single_release(inode, file);\
	return res;\
}

static int single_release(int inode, int file)
{
	printf("%s : %d : %d\n", __func__, inode, file);
	return 0;
}
int main()
{
	

	int num = 02, file = 01;
	printf("%s\n", __func__);
	SINGLE_RELEASE(ci_phy_tx_ctrl_);	

	return 0;
}
