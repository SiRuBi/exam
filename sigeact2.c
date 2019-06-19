#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signo){
	int ndx;

	printf("CTRL C 를 누르셨군요\n");
	printf("5초간 대기하겠습니다. 이때 Ctrl-Z키를 눌러주세요.\n");

	for(ndx=5; 0<ndx; ndx--){
		printf("%d초 남았습니다.\n",ndx);
		sleep(1);
	}
}

int main(void){
	struct sigaction act;

	act.sa_handler = sigint_handler; //시그널 핸들러 지정
	sigfillset(&act.sa_mask);//모든 시그널을 블록
	
	sigaction(SIGINT, &act,NULL);

	while(1){
		printf("signal handler registered fo SIGINT\n");
		sleep(1);
	}
	return(0);

}
