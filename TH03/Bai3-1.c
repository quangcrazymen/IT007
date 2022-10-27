#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>


// int n = 2;

void *threadFunc(){
    // while(n==2);
    printf("Hello world");
}
void main(){
    //Create a thread with the detached attribure
    pthread_t thr;
    pthread_attr_t attr;
    int s;
    int detachstate;;
    /* initialize an attribute to the default value */
    s= pthread_attr_init(&attr);
    // s = pthread_attr_destroy(&attr); 
    // if(s!=0)
        // errExitEN(s,"pthread_attr_init");

    s= pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);
    pthread_attr_getdetachstate(&attr,&detachstate);
    printf("%d",detachstate);
     s= pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
    pthread_attr_getdetachstate(&attr,&detachstate);
    printf("%d",detachstate);
    // if(s!=0)
        // errExitEN(s,"pthread_attr_setdetachstate");
    // s=pthread_attr_getschedparam()

    /* bound thread */
    s= pthread_attr_setscope(&attr, PTHREAD_SCOPE_SYSTEM);

    /* unbound thread */
    s= pthread_attr_setscope(&attr, PTHREAD_SCOPE_PROCESS);

    /* set the scheduling policy to SCHED_RR */
    s= pthread_attr_setschedpolicy(&attr, SCHED_RR);

    int size = (PTHREAD_STACK_MIN + 0x4000);

    /* setting a new size */
    s = pthread_attr_setstacksize(&attr, size);

    s = pthread_create(&thr, &attr, &threadFunc, (void *) 1);
    // pthread_join((long)&thr,NULL);
    // if(s!=0)
        // errExitEN(s,"pthread_create");     
    // printf("Hello");
    // s = pthread_attr_destroy(&attr);
}