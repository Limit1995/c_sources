#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/***************************Child1 Process Function***************************/
void child1Fun()
{
	int i=3,child1Cnt=0;
	printf("Hello from child1 pid = %d\n", getpid());
	while(i--)
	{
		sleep(2);
		printf("child1Cnt=%d\n",child1Cnt++);
	}
	exit(EXIT_SUCCESS);
}

/***************************Child2 Process Function***************************/
void child2Fun()
{
	int i=3,child2Cnt=0;
	printf("Hello from child2 pid = %d\n", getpid());
	while(i--)
	{
		sleep(2);
		printf("child2Cnt=%d\n",child2Cnt++);
	}
	exit(EXIT_SUCCESS);
}

/***************************Child3 Process Function***************************/
void child3Fun()
{
	int i=3,child3Cnt=0;
	printf("Hello from child3 pid = %d\n", getpid());
	while(i--)
	{
		sleep(2);
		printf("child3Cnt=%d\n",child3Cnt++);
	}
	exit(EXIT_SUCCESS);
}

void main(void)
{
	pid_t childPid1, childPid2, childPid3;
	int i=3,parentCnt=0;

/*******************************Child1 Process*******************************/
	childPid1 = fork();
	if(0 == childPid1)
		child1Fun();

/*******************************Child2 Process*******************************/
	childPid2 = fork();
	if(0 == childPid2)
		child2Fun();

/*******************************Child3 Process*******************************/
	childPid3 = fork();
	if(0 == childPid3)
		child3Fun();

/*******************************Parent Process*******************************/
	printf("Hello from parent pid = %d\n", getpid());
	if(-1==childPid1||-1==!childPid2||-1==childPid3)
		printf("Fork ERROR!\n");

	while(i--)
	{
		sleep(2);
		printf("parentCnt=%d\n",parentCnt++);
	}

	printf("Waiting for children process to exit ...\n");
	if(childPid1 == waitpid(childPid1, NULL, 0))
		printf("child1 process has exited\n");
	if(childPid2 == waitpid(childPid2, NULL, 0))
		printf("child2 process has exited\n");
	if(childPid3 == waitpid(childPid3, NULL, 0))
		printf("child3 process has exited\n");

	printf("parent process has exited\n");

	exit(EXIT_SUCCESS);

}
