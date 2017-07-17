#include <stdio.h>;
#include <stdlib.h>;
#include <pthread.h>;
#include <semaphore.h>;
 
#include "linkedlist.h";
 
/* prototypes for functions executed by threads */
void fill_list(int *);
void empty_list(int *);
void show_list();
 
/* list */
NODE * headptr;
NODE head;
 
/* mutex to protect access to list */
pthread_mutex_t list_mutex;
 
/* semaphores for synchronizing fill_list and empty_list threads */
unsigned int threads_fill_done; /* count threads done filling list */
sem_t done_filling_list;        /* barrier to sync fill_list threads and empty_list threads */
sem_t filling_list;             /* to protect threads_fill_done */
 
 
int main()
{
    int i;
 
    /* initialize list */
    headptr = &head;
    headptr->next = NULL;
 
    /* initialize mutex */
    pthread_mutex_init(&list_mutex, NULL);
 
    /* initialize semaphores */
    int res = sem_init(&done_filling_list,  /* pointer to semaphore */
                       0 ,                  /* 0 if shared between threads, 1 if shared between processes */
                       0);                  /* initial value for semaphore (0 is locked) */
    if (res < 0)
    {
        perror("Semaphore initialization failed");
        exit(0);
    }
    if (sem_init(&filling_list, 0, 1)) /* initially unlocked */
    {
        perror("Semaphore initialization failed");
        exit(0);
    }
    threads_fill_done = 0;
 
 
    pthread_t threads[11]; /* used by pthread_create to return thread id */
    int param[5] = {0, 1, 2, 3, 4}; /* array used to pass parameter to thread functions */
 
    for (i = 0; i < 5; i++)
    {
        /* creating 5 threads. Each thread enters one number (0-4) in the list */
        pthread_create(&threads[i],    /* pointer to buffer used by pthread_create to return thread id */
                       NULL,           /* pointer to thread attribute object */
                       (void *)fill_list,      /* pointer to function to execute */
                       (void *)&param[i]);    /* pointer to parameter to pass to function */
    }
 
    for (i = 5; i < 10; i++)
    {
        /* creating 5 threads. Each thread removes one number (0-4) from the list */
        pthread_create(&threads[i],
                       NULL,
                       (void *)empty_list,
                       (void *)&param[i-5]);
    }
 
    for (i = 0; i < 10; i++)
        pthread_join(threads[i], NULL);
 
 
    pthread_mutex_destroy(&list_mutex);
    sem_destroy(&filling_list);
    sem_destroy(&done_filling_list);
 
    printf("All threads completed. List:\n");
    Traverse(headptr);
    return 0;
}
 
void fill_list(int *value)
{
    int i;
 
    /* using mutex before entering critical section */
    pthread_mutex_lock(&amp;amp;list_mutex);
    printf("Thread is inserting number %d in list\n", *value);
    InsertOrdered(headptr,*value);// i); /* critical section */
    pthread_mutex_unlock(&amp;amp;list_mutex);
 
    /* entering critical section with semaphore (could use mutex too) */
    sem_wait(&filling_list); // blocks is semaphore 0. If semaphore nonzero,
                             // it decrements semaphore and proceeds
    if (threads_fill_done == 4)
    {
        printf(&amp;quot;Done filling list. Lifting barrier for 5 empty_list threads.\n&amp;quot;);
 for (i = 0; i < 5; i++)
            sem_post(&done_filling_list); // sem_post increments semaphore. Incrementing it to 5
    }
    else
    {
        threads_fill_done++;
        sem_post(&filling_list);
    }
}
 
void empty_list(int *value)
{
    /* waiting for list to be filled up */
    printf("Thread is waiting for semaphore to be released to remove %d from list.\n",*value);
    sem_wait(&done_filling_list);
 
    /* list filled. Removing elements */
    pthread_mutex_lock(&list_mutex);
    printf("Thread is removing number %d from list\n", *value);
    Delete(headptr,*value);
    pthread_mutex_unlock(&list_mutex);
}
 
 
void show_list(int *thread_num)
{
    pthread_mutex_lock(&list_mutex);
    printf("Current list from thread %i:\n",*thread_num);
    Traverse(headptr);
    pthread_mutex_unlock(&list_mutex);
}
