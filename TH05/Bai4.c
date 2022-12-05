#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
sem_t sem_1, sem_2;
int x = 0;
pthread_mutex_t mutex;
void* PROCESS1()
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		x++;
		if (x == 20)
		{
			x = 0;
		}
		printf("PA: x = %d\n", x);
		pthread_mutex_unlock(&mutex);
		
	}
}
void* PROCESS2()
{
	while (1)
	{
		pthread_mutex_lock(&mutex);
		x++;
		if (x == 20)
		{
			x = 0;
		}
		printf("PB: x = %d\n", x);
		pthread_mutex_unlock(&mutex);
	}
}
void main()
{
	pthread_mutex_init(&mutex, NULL);
	pthread_t th1, th2;
	pthread_create(&th1, NULL, &PROCESS1, NULL);
	pthread_create(&th2, NULL, &PROCESS2, NULL);
	while (1);
}