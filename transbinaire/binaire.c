#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>
#include <math.h>
int main() {
pid_t fils;
int tube[2];
double x, y, z;

puts("Créa+on d'un tube");
if (pipe(tube) != 0) /* pipe */
{
	fprintf(stderr, "Erreur dans pipe\n");
	exit(1);
}
switch(fils = fork()) /* fork */
{
case -1 : perror("Erreur dans fork\n"); exit(errno);
case 0 : /* processus fils */
		close(tube[1]);
		read(tube[0], &z, sizeof(double));
printf("Le fils (%d) a lu : %.2f\n", getpid(), z); break;
default : /* processus père */
		printf("Fermeture sor9e dans le père (pid = %d)\n", getpid());
		close(tube[0]);
		puts("Entrez x :");
		scanf("%lf", &x);
		y = sqrt(x);
		write(tube[1], &y, sizeof(double));
		wait(NULL); break;
}
return 0;
}