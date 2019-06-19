#include<stdio.h>
#include<unistd.h>
#include<signal.h>

int counter=0;

void sigint_handler(int signo){
	printf("알람 %d\n",counter++);
	alarm(1);
}

int main(void){
	int i=0;
	signal(SIGALRM, sigint_handler);
	alarm(5);
	while(i<10){
		printf("%d\n",i);
			i++;
	}

	return(0);

}
