#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main (int argc, char * argv[]) {
	int tubeDesc[2];
	pid_t pid_fils;
	if (pipe (tubeDesc) == -1) {
	perror ("pipe");
	exit (1);
	}

	if ( (pid_fils = fork ( )) == -1 ){
	perror ("fork");
	exit (1);
	}
	if (pid_fils == 0) { /* fils */
		dup2(tubeDesc[1],STDOUT_FILENO); /* lier l’entrée à stdout */
		close (tubeDesc[1]);
		close (tubeDesc[0]); /* fermeture en lecture */
		if (execl ("/bin/cat", "cat", "file1.dat",NULL) == -1) {
		perror ("execl");
		exit (1);
		}

		else {
	/* père */
				dup2(tubeDesc[0],STDIN_FILENO); /* lier la sorEe à stdin */
				close (tubeDesc[0]);
				close (tubeDesc[1]); /* fermeture en écriture */
				if (execl ("/bin/wc", "wc", "-l", NULL) == -1) {
				perror ("execl");
				exit (1);
				}
		 }
				return (EXIT_SUCCESS);
	}
}