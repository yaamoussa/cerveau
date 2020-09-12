# include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
   #include <sys/types.h>
       #include <sys/wait.h>


int main()
{
	int i,status ;
	pid_t newpid=fork();
	switch(newpid)
	{
		case -1: perror ("Error de reation du processus");
		          return -1;
		case  0: {  printf("%1d -> %1d\n",getppid(),getpid() );
		 for (int i = 0; i <3; ++i)		
		{
						/* code */
			newpid =fork();
			if (  newpid !=-1 && newpid!=0)
			{  
				/*/* code */
				//{wait(&status);}*/
                

			}
			else /*if ( newpid==0)*/
			{
				/* code */
				 printf("%1d -> %1d\n",getppid(),getpid() );
			         exit(-1);

			} 
		}
		return 0;}
		default :   {wait(&status);
		           printf("%1d -> %1d\n",getppid(),getpid() );}
		return 0;
	}	
	return 0;
}