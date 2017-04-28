#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

int balance = 1000;
sem_t s;
	

void * thread1(void *arg)
{
	int i;
	for (i = 0; i< 50; ++i)
	{
		sem_wait(&s);
			balance = balance + 50;
		sem_post(&s);	
	}
}

void * thread2(void *arg)
{
	int i;
	for (i = 0; i< 20; ++i)
	{
		sem_wait(&s);
			balance = balance +20; 
		sem_post(&s);	
	}	
}

int main()
{
	pthread_t pid1, pid2;
	pthread_create(&pid1, NULL, thread1, NULL);
	pthread_create(&pid2, NULL, thread2, NULL);
	sem_init(&s, 0, 1);
	//pthread_exit(NULL);
	pthread_join(&pid1, NULL);
	pthread_join(&pid2, NULL);
	//printf("final balance is %d", bal);
	return 0;
}
