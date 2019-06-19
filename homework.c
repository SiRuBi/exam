#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>

sem_t s;
sem_t t;

char a;
int b;
int c;

void *thread1()
{
	sem_wait(&s);
	a = a+c-b;
	b = a+b+c;
	c = b-a+c;
	sem_post(&s);
	sem_post(&t);


}

void *thread2()
{
	sem_wait(&t);
	sem_wait(&s);
	a = b+c;
	b = b-a+c;
	c = b+a+c;
	sem_post(&s);

}

int main()
{
	sem_init(&s,0,1);
	sem_init(&t,0,0);
	while(1){
		a = 65;
		b = 1;
		c = 2;

		pthread_t th1;
		pthread_t th2;

		pthread_create(&th1, NULL, thread1, NULL);
		pthread_create(&th2, NULL, thread2, NULL);

		pthread_join(th1, NULL);
		pthread_join(th2, NULL);

	    printf("%c %d %d \n",a,b,c);

		sleep(0.7);
	}
	return(0);

}
