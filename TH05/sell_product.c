#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;
int sells=0, products=0;

void *processA(){
	while(1){
		sem_wait(&sem);
		printf("sells = %d\n", sells);
		sells++;
	}
}

void *processB(){
	while(1){
		// MSSV: 20520720
		if(products<=sells+20+10){
			products++;
			printf("products = %d\n", products);
			sem_post(&sem);
		}
			
	}
}

void main()
{
	sem_init(&sem,0,0);     //pshare = 0 to share it with other process, and value = 0
	pthread_t th1, th2;
	pthread_create(&th1, NULL, &processA, NULL);
	pthread_create(&th2, NULL, &processB, NULL);
	while(1);
}