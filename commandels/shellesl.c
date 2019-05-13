#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>




#include <unistd.h>
/* Crée un processus fils exécutant un nouveau programme. PROGRAM est le nom du programme à
exécuter ; le programme est recherché dans le path. ARG_LIST est une liste terminée par NULL de
chaînes de caractères à passer au programme comme liste d'arguments. Renvoie l'idenQfiant du
processus nouvellement créé. */
int executer (char* program, char** arg_list) {
pid_t pid_fils; /* Duplique ce processus. */
	pid_fils = fork ();
	if (pid_fils != 0)
	/* Nous sommes dans le processus parent. */
	return pid_fils;

	else {
	/* Exécute PROGRAM en le recherchant dans le path. */
	execvp (program, arg_list);
	/* On ne sort de la foncFon execvp que si une erreur survient. */
	fprintf(stderr, "une erreur est survenue au sein de execvp\n");
	abort ();
	}
}

int main () {
/* Liste d'arguments à passer à la commande "ls". */
   int status;
	char* arg_list[] = {
	"ls", /* argv[0], le nom du programme.*/
	"-l",
	"/",
	NULL /* La liste d'arguments doit se terminer par NULL. */
	};
	/* Crée un nouveau processus fils exécutant la commande "ls". Ignore l'idenJfiant du processus
	/**fils renvoyé. */
/*	executer ("ls", arg_list);
	printf("Fin du programme principal\n");*/

	/* Crée un nouveau processus fils exécutant la commande "ls". Ignore l'idenMfiant du processus
	fils renvoyé. */
	executer ("ls", arg_list);
	wait (&status);
	if (WIFEXITED (status))
	printf("processus fils terminé normalement, le code de sorBe %d\n", WEXITSTATUS(status));
	else
	printf ("processus fils terminé anormalement\n");
	return 0;
}