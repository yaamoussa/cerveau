#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

 void init (int *tab)
 {
 	int i;
 	srandom (time (NULL));
 	for (int i = 0; i <100; ++i)
 	{
 		/* code */
 		tab[i]=random();

 	}
 }

 void show_t(int * tb){
 	int i;
 	for (int i = 0; i < 100; ++i)
 	{
 		/* code */
 		printf("%d\n", tb[i]);

 	}
 }

 void feed_f(char *fn,int * tb)
 {
 	int fd_dst=open (fn,O_CREAT|O_EXCL|O_RDWR,S_IRUSR|S_IWUSR|S_IRGRP);
 	if ( fd_dst==-1)
 	{
 		/* code */
 		perror ("Errror ");return ;

 	}

 	int result=write (fd_dst,tb,100*sizeof(int));
 	close(fd_dst);
 }

void show_f(char *fn, int *tb )
{
	int fd_src=open(fn,O_RDONLY);
	if ( fd_src==-1)
	{
		
		perror ("Errror	")	;return ;

	}
	int i;
	read(fd_src,tb,100*sizeof(int));
	for (int i = 0; i <100; ++i)
	{
		
		fprintf("tab [%d]=%d \n",i,tb[i] );

	}
}
extern char * optarg;
extern int optind,opterr,optopt;

int main (){
	int opt;
	int tab [100];
	printf("I was just testing"); 
	init (tab);feed_f(optarg,tab);
	    show_f(optarg,tab); 
}