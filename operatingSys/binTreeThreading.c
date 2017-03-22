#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#define MAX_DEPTH 4 



void main(void)
{
	pid_t childLeft, childRight;
	int i=1,threadingDepth=0;

	printf("grand...parent pid = %d\n", getpid());
	while(i++)
	{
		switch(i)
		{
		case(2):
			childLeft = fork();
			if(0 == childLeft)
			{
				threadingDepth++;
				i=1;
				sleep(2);
				printf("pidLeft  = %0d | pidParent = %0d\n", getpid()%1000,getppid()%1000);
				if(threadingDepth>=MAX_DEPTH)
					exit(EXIT_SUCCESS);
			}
			break;
		case(3):
			childRight = fork();
			if(0 == childRight)
			{
				threadingDepth++;
				i=1;
				sleep(2);
				printf("pidRight = %0d | pidParent = %0d\n", getpid()%1000,getppid()%1000);
				if(threadingDepth>=MAX_DEPTH)
					exit(EXIT_SUCCESS);
			}
			break;
		}
		if(3<=i)
			break;
	}
	
	waitpid(childLeft,NULL,0);
	waitpid(childRight,NULL,0);


	exit(EXIT_SUCCESS);

}
