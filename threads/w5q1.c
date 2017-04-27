
#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * executeThread(void *t)
{
	printf("thread running \n");
	int ctr = *((int *)t);
	printf("thread %d executing\n", ctr);
	pthread_exit(NULL);
}

int main()
{
	pthread_t ptids[5];
	int *t = (int *)malloc(sizeof(int));
	for(int i = 0; i<5; ++i)
	{
		*t = i+1;
		int rc = pthread_create(&ptids[i], NULL, executeThread, (void *)t);
		if(rc)
			printf("error creatinig thread %d\n", i);
		else
			printf("creating thread %d \n", i);
	}
	for(int i =0 ; i<5; ++i)
	{
		pthread_join(&ptids[0], NULL);
	}
	pthread_exit(NULL);								//to make sure that even after main exits, threads do run
	return 0;
}
