#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<wait.h>
#include<string.h>

sem_t s1;
sem_t s0;
sem_t mutex;


void *P(void *arg) {
	
	while(1){

		sem_wait(&s0);
		sem_wait(&mutex);
	    printf("%d\n",0 );
	    printf("%d\n", 0);
	    sem_post(&mutex);
	  	sem_post(&s1);
	}
		
}



void *Q(void *arg) {
	
	while(1){
		sem_wait(&s1);
		sem_wait(&mutex);
	    printf("%d\n",1 );
	    printf("%d\n",1);
	    sem_post(&mutex);
	  	sem_post(&s0);
	}
		
}


int main(int argc, char const *argv[])
{
	sem_init(&mutex,0,1);
	sem_init(&s1,0,0);
	sem_init(&s0,0,1);
	pthread_t t1,t2;
	pthread_create(&t1,	NULL,P,NULL);
	pthread_create(&t2,	NULL,Q,NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	
	/* code */
	return 0;
}