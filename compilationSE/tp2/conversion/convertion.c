#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <ctype.h>
#define BUFFER_SIZE 80
int main() {
	pid_t pid_fils;
	int tube[2];
	unsigned char bufferR[80], bufferW[80];
	puts( " création d’un tube " );
	if (pipe(tube) != 0) {/* pipe */

		fprintf(stderr, "Erreur dans pipe\n");
		exit(1);
	}
	pid_fils = fork(); /* fork */
	if (pid_fils == -1)
	{
		fprintf(stderr, "Erreur dans fork\n");
		exit(1);
	}
	if (pid_fils == 0) /* processus fils */
	{
		printf("Fermeture entree dans le fils (pid = %d)\n", getpid());
		close(tube[1]);

		read(tube[0], bufferR, BUFFER_SIZE);
		int i=0;
        while(bufferR[i]){
        	    bufferR[i]= toupper(bufferR[i]);
        	     i++;
        }
		printf("Le fils (%d) a lu : %s\n", getpid(), bufferR);
	}
	else
	/* processus pere */
	{
		printf("Fermeture sorNe dans le pere (pid = %d)\n", getpid());
		close(tube[0]);
		sprintf(bufferW, "Message du pere (%d) au fils", getpid());
		write(tube[1], bufferW, BUFFER_SIZE);
		wait(NULL);
	}
	return 0;
}