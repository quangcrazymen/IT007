#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid;
	pid = fork();
	printf(" so 1");
	printf(" so 2");
	fork();
	if(pid < 0){
		printf("hello");
		fork();
	}else{
		fork();
		printf("bye");
	}
	return 0;
}
