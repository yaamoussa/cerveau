#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#define BUFFER_SIZE 80
int main(int argc, char ** argv) {
	pid_t pid_fils1;
	pid_t pid_fils2;
	int tube1[2];
	int tube2[2];
	int  bufferR1[80], bufferW1[80];
	int  bufferR2[80], bufferW2[80];
	int origin,j,k,i=1;
	j=k=0;
/* pour le premier fils */
	
	if (pipe(tube1) != 0) {/* pipe */

		fprintf(stderr, "Erreur dans pipe\n");
		exit(1);
	}
	puts( " création d’un tube 1 " );
	if (pipe(tube2) != 0) {/* pipe */

			fprintf(stderr, "Erreur dans pipe\n");
			exit(1);
		}
		puts( " création d’un tube 2 " );

	pid_fils1 = fork(); /* fork */
	if (pid_fils1 == -1)
	{
		fprintf(stderr, "Erreur dans fork\n");
		exit(1);
	}

	 if (pid_fils1 == 0) /* processus fils1 */
	{
		printf("Fermeture entree dans le fils1 (pid = %d)\n", getpid());
		close(tube1[1]);

		read(tube1[0], bufferR1, BUFFER_SIZE);
		int i=0;
		int som=0;
        while(i<=j)
        	     som+=bufferR1[i++];
        	 bufferW1[0]=som;
       close(tube1[0]);
       write(tube1[1], bufferW1, 2*sizeof(int));
	
	}
	else {
		   pid_fils2 = fork(); /* fork */
			if (pid_fils2 == -1)
				{
					fprintf(stderr, "Erreur dans fork\n");
					exit(1);
				}
	
	       if (pid_fils2 == 0) /* processus fils2 */
		       {
				printf("Fermeture entree dans le fils2 (pid = %d)\n", getpid());
				close(tube2[1]);

				read(tube2[0], bufferR1, BUFFER_SIZE);
				int i=0;
				int som=0;
		        while(i<=j)
		        	      som+=bufferR2[i++];
		        	 bufferW2[0]=som;
		       close(tube2[0]);
		       write(tube2[1], bufferW2, 2*sizeof(int));
			}
			else
			/* processus pere */
			{
			
				printf("Fermeture sorNe dans le pere (pid = %d)\n", getpid());
				close(tube1[0]);
				close(tube2[0]);
		   		 /*recuperation des entiers */
				while(argv[i]!=NULL){
			    	if (sscanf(argv[i], "%d", &origin) != 1) {
				        printf("Error, %s is not an int", argv[1]);
				        return EXIT_FAILURE;
			   		 }
		         	/*  copiers des entiers */
			   		 if (origin<0){
			  		   bufferW1[j]=origin;
			  		   j++;
			  		}
			  		else {
			  			bufferW2[k]=origin;
			  			k++;
			  		}
			  		i++;
				}
				/*envoie aux deux fils*/
				write(tube1[1], bufferW1, BUFFER_SIZE*sizeof(int));
				write(tube2[1], bufferW2, BUFFER_SIZE*sizeof(int));
		        wait(NULL);
		        close(tube1[1]);
				close(tube2[1]);
				read(tube1[0],bufferR1,2*sizeof(int));
				read(tube2[0],bufferR2,2*sizeof(int));

				printf("le result du pere :%d\n",bufferR1[0]+bufferR2[0] );
  
			}
		}
return 0;
}

