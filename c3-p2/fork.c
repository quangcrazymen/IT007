#include <stdio.h>
#include <unistd.h>
int main()
{
	int pid;
	printf("Tiến trình cha \n");
	pid = fork();
	if(pid > 0){
		fork();
		printf("Tiến trình cha \n");
	}
	else{
		printf("Tiến trình con \n");
		if(fork()>0)
			printf("Tiến trình cha \n");
		else
			printf("Tiến trình con \n");
	}
	return 0;
}
