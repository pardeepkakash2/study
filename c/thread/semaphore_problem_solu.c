#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
  
 
 
#define SIZE 10
#define NUMB_THREADS 10
#define PRODUCER_LOOPS 2
#define CONSUMER_LOOPS 2
  
#define TRUE 1
#define FALSE 0
 
typedef int buffer_t;
buffer_t buffer[SIZE];
int buffer_index;
  
pthread_mutex_t buffer_mutex;
/* initially buffer will be empty.  full_sem
   will be initialized to buffer SIZE, which means
   SIZE number of producer threads can write to it.
   And empty_sem will be initialized to 0, so no
   consumer can read from buffer until a producer
   thread posts to empty_sem */
sem_t full_sem;  /* when 0, buffer is full */
sem_t empty_sem; /* when 0, buffer is empty. Kind of
                    like an index for the buffer */
  
/* sem_post algorithm:
    mutex_lock  sem_t->mutex
    sem_t->value++
    mutex_unlock sem_t->mutex
  
   sem_wait algorithn:
    mutex_lock sem_t->mutex
    while (sem_t->value > 0) {
        mutex_unlock sem_t->mutex
        sleep... wake up
        mutex_lock sem_t->mutex
    }
    sem_t->value--
    mutex_unlock sem_t->mutex
*/
  
  
void insertbuffer(buffer_t value) {
    if (buffer_index < SIZE) {
        buffer[buffer_index++] = value;
    } else {
        printf("Buffer overflow\n");
    }
}
  
buffer_t dequeuebuffer() {
    if (buffer_index > 0) {
        return buffer[--buffer_index]; // buffer_index-- would be error!
    } else {
        printf("Buffer underflow\n");
    }
    return 0;
}
  
  
int isempty() {
    if (buffer_index == 0)
        return TRUE;
    return FALSE;
}
  
int isfull() {
    if (buffer_index == SIZE)
        return TRUE;
    return FALSE;
}
 
void *producer2(void *thread_n) {
    int thread_numb = *(int *)thread_n;
    buffer_t value;
    int i=0;
    while (i++ < PRODUCER_LOOPS) {
        sleep(rand() % 10);
        value = rand() % 100;
        pthread_mutex_lock(&buffer_mutex);
        do {
            // cond variables do the unlock/wait and wakeup/lock atomically,
            // which avoids possible race conditions
            pthread_mutex_unlock(&buffer_mutex);
            // cannot go to slepp holding lock
            sem_wait(&full_sem); // sem=0: wait. sem>0: go and decrement it
            // there could still be race condition here. another
            // thread could wake up and aqcuire lock and fill up
            // buffer. that's why we need to check for spurious wakeups
            pthread_mutex_lock(&buffer_mutex);
        } while (isfull()); // check for spurios wake-ups
        insertbuffer(value);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&empty_sem); // post (increment) emptybuffer semaphore
        printf("Producer %d added %d to buffer\n", thread_numb, value);
    }
    pthread_exit(0);
}
  
void *consumer2(void *thread_n) {
    int thread_numb = *(int *)thread_n;
    buffer_t value;
    int i=0;
    while (i++ < PRODUCER_LOOPS) {
        pthread_mutex_lock(&buffer_mutex);
        do {
            pthread_mutex_unlock(&buffer_mutex);
            sem_wait(&empty_sem);
            pthread_mutex_lock(&buffer_mutex);
        } while (isempty()); //check for spurios wakeups
        value = dequeuebuffer(value);
        pthread_mutex_unlock(&buffer_mutex);
        sem_post(&full_sem); // post (increment) fullbuffer semaphore
        printf("Consumer %d dequeue %d from buffer\n", thread_numb, value);
   }
    pthread_exit(0);
}
  
int main(int argc, int **argv) {
    buffer_index = 0;
  
    pthread_mutex_init(&buffer_mutex, NULL);
    sem_init(&full_sem, // sem_t *sem
             0, // int pshared. 0 = shared between threads of process,  1 = shared between processes
             SIZE); // unsigned int value. Initial value
    sem_init(&empty_sem,
             0,
             0);
    /* full_sem is initialized to buffer size because SIZE number of
       producers can add one element to buffer each. They will wait
       semaphore each time, which will decrement semaphore value.
       empty_sem is initialized to 0, because buffer starts empty and
       consumer cannot take any element from it. They will have to wait
       until producer posts to that semaphore (increments semaphore
       value) */
    pthread_t thread[NUMB_THREADS];
    int thread_numb[NUMB_THREADS];
    int i;
    for (i = 0; i < NUMB_THREADS; ) {
        thread_numb[i] = i;
        pthread_create(thread + i, // pthread_t *t
                       NULL, // const pthread_attr_t *attr
                       producer2, // void *(*start_routine) (void *)
                       thread_numb + i);  // void *arg
        i++;
        thread_numb[i] = i;
        // playing a bit with thread and thread_numb pointers...
        pthread_create(&thread[i], // pthread_t *t
                       NULL, // const pthread_attr_t *attr
                       consumer2, // void *(*start_routine) (void *)
                       &thread_numb[i]);  // void *arg
        i++;
    }
  
    for (i = 0; i < NUMB_THREADS; i++)
        pthread_join(thread[i], NULL);
  
    pthread_mutex_destroy(&buffer_mutex);
    sem_destroy(&full_sem);
    sem_destroy(&empty_sem);
  
    return 0;
}
