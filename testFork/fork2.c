#include<stdio.h>
#include<unistd.h>

int main(){
	int i=0;
    for(i=0;i<3;i++){
        int pid = fork();
        printf("%d",pid);
        printf("hello\n");
    }
    return 0;
}
