#include <stdio.h>
#include <stdlib.h>
  
int main(int argc, char **argv)
{
    int origin;
    int i=1;
    while(argv[i]!=NULL){
    	if (sscanf(argv[i], "%d", &origin) == 1) {
	        printf("Error, %s is an int or char", argv[i]);
	        return EXIT_FAILURE;
	    }
    /* ... */
	  printf("%s\n",argv[i]);
	  i++;
	}
    return 0;
}