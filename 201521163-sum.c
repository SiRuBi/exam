#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void){
			pid_t pid;
			int i;
			int sum;
			printf("before fork(%d)\n",getpid());

			if((pid==fork())<0)
				perror("fork error");

			else
				for(i=1;i<100;i++){
				sum=sum+i;
				}
				
				printf("1+100=%d\n",sum);

				exit(EXIT_SUCCESS);
				}
