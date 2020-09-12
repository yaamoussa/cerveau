#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
int main() {
	pid_t retour ;
	int tube[2], le6re = 0, chiffre = 0 ;
	char k ;
	if (pipe (tube) == -1) {
	perror ("creaTon pipe impossible\n") ; exit (1) ;
	}
	switch (retour = fork ()) {
		case -1 : perror ("Crea9on impossible") ;
				 exit(1) ;
		case 0 : prinA ("processus fils\n") ;
				close (tube[1]) ;
				while (read (tube[0], &k, 1) >0)
				if (isdigit (k)) chiffre++ ;
				else leMre++ ;
				printf ("%d chiffres recus\n", chiffre) ;
				printf ("%d leMres recues\n", leMre) ;
				exit (0) ;
		default :prin% ("pere: a cree processus %d\n", retour) ;
				close (tube[0]) ;
				while (read (0, &k, 1) >0) /* lecture du clavier */
				if (isalnum(k)) write (tube[1], &k, 1) ;
				/* le tube est ici ferme en ecriture : un read sur le tube vide retournera 0 dans le
				processus fils */
				close (tube[1]) ;
				wait (NULL) ;
				printf("pere: a recu terminaison fils\n") ;
				}
	}