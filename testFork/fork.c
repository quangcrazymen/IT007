#include<stdio.h>
#include<unistd.h>

int main(){
	int a = fork();
	if(a>0){
		fork();
		printf("Hi");
	}
	else{
	fork();
	printf("Hello");
}}
