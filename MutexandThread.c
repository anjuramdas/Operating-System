#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
int val=0;
pthread_t tid;
pthread_mutex_t lock;
pthread_cond_t cond;
void* func(void *p)
{   pthread_mutex_lock(&lock);
    while(val==0)pthread_cond_wait(&cond,&lock);
    printf("\nEntered value is %d\n",val);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(void)
{
   
    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond,0);
    pthread_create(&(tid), NULL,&func,NULL);
    pthread_mutex_lock(&lock);
    printf("Enter any value:\n");
    scanf("%d",&val);
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    pthread_cond_destroy(&cond);
    pthread_mutex_destroy(&lock);
    sleep(1);
    return 0;
}
