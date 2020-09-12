#include <stdio.h>
#include <stdlib.h>
  
int main(int argc, char **argv)
{
    char origin;
    int i=1;
    while(argv[i]!=NULL){
    	if (sscanf(argv[i], "%c", &origin) != 1) {
	        printf("Error, %s is not an int", argv[1]);
	        return EXIT_FAILURE;
	    }
    /* ... */
	  printf("%c\n",origin );
	  i++;
	}
    return 0;
}