
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<wait.h>
#include<string.h>
sem_t  max_UFR;
sem_t mutex;
 int entre1=0;
 int entre2=0;
 int entre3=0;
 int entre4=0;//file d attante des etudiants

void *UFR1(void *arg) {
	
	while(1){
		int i;
		 entre1++;
	   if(entre1==1)	sem_wait(&max_UFR);
	  //  sem_wait(&mutex);
		printf("etudiant de UFR1 entre\n");
		printf("l etudiant s entraine \n");
		 for(i=0; i<1000;i++);
		printf("sortie de l etudiant de UFR1\n");
		entre1--;
	//	sem_post(&mutex);
	  if(entre1==0)	sem_post(&max_UFR);
	}
		
}



void *UFR2(void *arg) {
	
	while(1){
		int i;
		  entre2++;
	if(entre2==1)	sem_wait(&max_UFR);
	//	sem_wait(&mutex);
		printf("etudiant de UFR2 entre\n");
		printf("l etudiant s entraine \n");
	     for(i=0; i<1000;i++);
		printf("sortie de l etudiant de UFR2\n");
	    entre2--;
	  //  sem_post(&mutex);
  if(entre2==0)		sem_post(&max_UFR);
   }
	
}


void *UFR3(void *arg) {
	
	while(1){
		int i;
		entre3++;
		if (entre3==1) sem_wait(&max_UFR);
	//	sem_wait(&mutex);
		printf("etudiant de UFR3 entre\n");
		printf("l etudiant s entraine \n");
		 for(i=0; i<1000;i++);
		printf("sortie de l etudiant de UFR3\n");
		entre3--;
	//	sem_post(&mutex);
		if (entre3==0)sem_post(&max_UFR);
    }	
}



void *UFR4(void *arg) {

	while(1){
		int i;
        entre4 ++;
		if (entre4==1) sem_wait(&max_UFR);
	//	sem_wait(&mutex);
		printf("etudiant de UFR4 entre\n");
		printf("l etudiant s entraine\n ");
		 for(i=0; i<1000;i++);
		printf("sortie de l etudiant de UFR4\n");
		entre4--;
		//sem_post(&mutex);
        if (entre4==0)	sem_post(&max_UFR);
        
	}
		
}



int main(int argc, char const *argv[])
{
	sem_init(&mutex,0,1);
	sem_init(&max_UFR,0,3);
	pthread_t t1,t2,t3,t4;
	pthread_create(&t2,	NULL,UFR2,NULL);
	pthread_create(&t4,	NULL,UFR4,NULL);
	pthread_create(&t1,	NULL,UFR1,NULL);
	pthread_create(&t3,	NULL,UFR3,NULL);
	if (entre1==0){ printf("*****************************************************");
			         printf(" l' etudiant de l' UFR1 en attante \n"); 
			       }
    if (entre2==0){printf("*****************************************************");
		            printf(" l' etudiant de l' UFR2 en attante \n"); 
		            }
	if (entre3==0){printf("*****************************************************");
			        printf(" l' etudiant de l' UFR3 en attante \n"); 
			       }
	if(entre4==0){ printf("*****************************************************");
		           printf(" l' etudiant de l'  UFR4 en attante \n");  
		          }
	
	pthread_join(t4, NULL);
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t3, NULL);
	
	/* code */
	return 0;
}