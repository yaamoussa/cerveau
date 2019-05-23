# include<stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
#include "common.h"


#include <unistd.h>

extern char * optarg;
extern int optind,opterr,optopt;


int main(int argc ,char * argv[],char arge[])
{
	int opt;
	int tab [100];
	while((opt=getopt(argc,argv,"i:s"))!=-1)
	{
		switch (opt)
		{
			case 'i':  printf("Debut du programme \n");
			init (tab);feed_f(optarg,tab);
			break;
			case 's':   printf("Debut du programme \n");
			          show_f(optarg,tab); break ;
			case ':': printf("Error l'option -%c\n  attend argument ",opt ); 
			          break;
			case '?':  printf("Error l'option -%c\n  attend argument ",opt ); 
			          break;
		}
	}

	return 0;
}