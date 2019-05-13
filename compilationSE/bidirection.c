#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
int main () {
	int pip1[2]; int pip2[2];
	pid_t pid_fils;
	char chaine1[7], chaine2[5];
/* Créa)on des tubes */
	if(pipe(pip1) == -1) {
	perror("pipe 1");
	exit(1);
	}

	if(pipe(pip2) == -1) {
	perror("pipe 2");
	exit(2);
	}
	/* créa9on processus */
	pid_fils = fork();
	if (pid_fils == -1) {
	perror ("Crea9on impossible") ;
	exit(3) ;
	}
	if (pid_fils > 0) {
	/* tube père vers fils */
	/* fermé en lecture */
	close (pip1[0]);
	/* second tube fils vers père */
	/* fermé en écriture */

	close (pip2[1]);

	/* envoi message au fils par le tube 1*/
	if(write(pip1[1],"hello",5)!=5) {
	fprintf(stderr,"père: erreur en écriture\n");
	exit(4);
	}
	/* ANente de la réponse du fils par le tube 2 */
	if(read(pip2[0],rep,7)!=7) {
	fprintf(stderr,"fils: erreur lecture\n");
	exit(5);
	}
	printf("message du fils: %s\n",rep);
	wait(&status);
	}


	else {
	/*fermeture du tube 1 en écriture */
	close(pip1[1]);
	/* fermeture du tube 2 en lecture */
	close(pip2[0]);
	/* a>ente d’un message du père */
	if(read(pip1[0],mesg,5)!=5) {
	fprintf(stderr,"fils: erreur lecture\n");
	exit(6);
	}
	printf("la chaine reçue par le fils est: %s\n",mesg);
	/* envoi d’un message au père */
	if(write(pip2[1],"bonjour",7)!=7) {
	fprintf(stderr,"fils: erreur ecriture\n"); exit(7);
	}
	exit(0);
}
}