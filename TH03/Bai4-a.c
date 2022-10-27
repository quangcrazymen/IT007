#include <stdio.h>
#include <pthread.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

long id_thread;
int loop = 2;
void on_sigint(){
    if(loop == 1){
        loop--;
        printf("\nCTRL+C was pressed!Goodbye!\n");
    }
}
void on_sigint2(){
    if(loop == 2){
        loop--; 
        system("killall vim");
    }
}
void *open_vim(void *args){
    system("vim abcd.txt");
    signal(SIGINT,on_sigint2);
    while(loop!=1);
}
int main(){
    // Print Welcome message
    char *mssv = "20520720";
    printf("Welcome to IT007, I am %s\n",mssv); 
    // Open vi editor
    pthread_create(&id_thread,NULL,&open_vim,(void*)id_thread);
    pthread_join(id_thread,NULL);
    signal(SIGINT,on_sigint);
    while(loop!=0);
    printf("\n");
    return 0;
}