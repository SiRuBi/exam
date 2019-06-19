#include<stdio.h>
#include<signal.h>
#include<unistd.h>

struct sigaction act_new;
struct sigaction act_old;

void sigint_handler(int signo){
	printf("CTRL C 눌렀군요\n");
	printf("one more EXIT\n");
	sigaction(SIGINT, &act_old, NULL);
}
int main(void){
	
	act_new.sa_handler = sigint_handler; //시그널 핸들러 지정
	sigemptyset(&act_new.sa_mask);// 시그널 처리중 블록된 시그널은 없음
	//SIGINT를 지정하면서 act_old에 이전 정보를 구한다.
	sigaction(SIGINT, &act_new, &act_old);

	while(1){
		printf("sigaction\n");
		sleep(1);
	}

	return(0);

}
