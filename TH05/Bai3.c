#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
int x = 0;
void* A()
{
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("PA: x = %d\n", x);
	}
}
void* B()
{
	while (1)
	{
		x = x + 1;
		if (x == 20)
		{
			x = 0;
		}
		printf("PB: x = %d\n", x);
	}
	sleep(1);
}
void main()
{
	pthread_t th1, th2;
	pthread_create(&th1, NULL, &A, NULL);
	pthread_create(&th2, NULL, &B, NULL);;
	while (1);
}