#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void){
	pid_t pid;

	printf("before fork(%d)\n", getpid ());
	if((pid=fork())<0)
			perror("fork error");
			
			else
			printf("hi (%d)\n",getpid());
			
			printf("201521163 KIMDONGHYUN (%d)\n", getpid());
			exit(EXIT_SUCCESS);
			}
