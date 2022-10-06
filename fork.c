#include <stdio.h>
#include <unistd.h>
int main()
{
	int i;
	fork();
	for (i = 0; i < 3; i++)
	{
		int k = fork();
		if (k > 0)
		{
			printf("hello\n");
		}
	}
	return 0;
}
