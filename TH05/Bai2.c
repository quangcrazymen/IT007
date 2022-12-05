#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<pthread.h>
#include<semaphore.h>
#include <unistd.h>

sem_t sem1, sem2;
int n;
int i = 0;
static int dem = 0;
int a[1000];
void* PROCESS1()
{
	while (1)
	{
		if (dem < n) {
			a[i++] = rand() % (n - 1);
			dem++;
			printf("\n[PUSH] Number of elements in array a: %2d", dem);	
			
		}
        // sleep to easily print of result
		int time_sleep = rand() % 2 + 1;
		sleep(time_sleep);
		
		sem_post(&sem1);
	}
}
void* PROCESS2()
{
	int j, b;
	while (1)
	{
		sem_wait(&sem1);

			
        if (dem == 0)
        {
            printf("\n[POP] Nothing in array a");
        }
        else
        {
            dem--;
            b = a[0];
            for (j = 0; j < dem; j++)
            {
                a[j] = a[j + 1];
            }
            
            printf("\n[POP] Number of elements in array a: %2d", dem);
        }
    
        // sleep to easily print of result
		int time_sleep = rand() % 2 + 1;
		sleep(time_sleep);
	}
}
void main()
{
	sem_init(&sem1, 1, 0);
	sem_init(&sem2, 0, 0);
	printf("\nEnter n: ");
	scanf("%d",&n);
	pthread_t th1, th2;
	pthread_create(&th1, NULL, PROCESS1, NULL);
	pthread_create(&th2, NULL, PROCESS2, NULL);
	while(1);

}