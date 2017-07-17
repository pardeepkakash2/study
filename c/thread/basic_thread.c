#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
 
#define N 10
sem_t sem1, sem2, sem3;
int a1[N], a2[N], a3[N];
 
void * thread1(void *arg) {
    int i;
    for (i = 0; i< N; i++) {
        sem_wait(&sem1);
        printf("%d, ", a1[i]);
        sem_post(&sem2);
    }
    pthread_exit(0);
}
 
void * thread2(void *arg) {
    int i;
    for (i = 0; i< N; i++) {
        sem_wait(&sem2);
        printf("%d, ", a2[i]);
        sem_post(&sem3);
    }
    pthread_exit(0);
}
 
void * thread3(void *arg) {
    int i;
    for (i = 0; i< N; i++) {
        sem_wait(&sem3);
        printf("%d, ", a3[i]);
        sem_post(&sem1);
    }
    pthread_exit(0);
}
 
int main() {
    pthread_t threads[3];
    int i;
 
   int no = 0;
    for (i = 0; i < N; i++) {
        a1[i] = no++;
        a2[i] = no++;
        a3[i] = no++;
    }
 
    sem_init(&sem1, 0, 1);
    sem_init(&sem2, 0, 0);
    sem_init(&sem3, 0, 0);
 
    pthread_create(&threads[0], NULL, thread1, NULL);
    pthread_create(&threads[1], NULL, thread2, NULL);
    pthread_create(&threads[2], NULL, thread3, NULL);
 
    for (i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);
    printf("\n");
 
    sem_destroy(&sem1);
    sem_destroy(&sem2);
    sem_destroy(&sem3);
 
    return 0;
}
