#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

/*******************************Child1 Process Function*******************************/
void child1Fun()
{
	sleep(4);
	printf("Hello from child1 pid = %d\n", getpid());
	exit(EXIT_SUCCESS);
}

/*******************************Child2 Process Function*******************************/
void child2Fun()
{
	printf("Hello from child2 pid = %d\n", getpid());
	sleep(5);
	exit(EXIT_SUCCESS);
}


void main(void)
{
	pid_t childPid1, childPid2, childPid3;

/*******************************Child1 Process*******************************/
	childPid1 = fork();
	if(0 == childPid1)
		child1Fun();

/*******************************Child2 Process*******************************/
	childPid2 = fork();
	if(0 == childPid2)
		child2Fun();


/*******************************Parent Process*******************************/
	printf("Hello from parent pid = %d\n", getpid());

	if(-1==childPid1||-1==!childPid2||-1==childPid3)
		printf("Fork ERROR!\n");

	sleep(1);
	printf("Waiting for children process to exit ...\n");
	if(childPid1 == waitpid(childPid1, NULL, 0))
		printf("child1 process has exited\n");
	if(childPid2 == waitpid(childPid2, NULL, 0))
		printf("child2 process has exited\n");

	printf("Parent process has exited\n");

	exit(EXIT_SUCCESS);

}









