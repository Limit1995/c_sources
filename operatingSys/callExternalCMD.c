#include<unistd.h>
#include<stdarg.h>
#include<time.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

int tprintf(const char * fmt,... );

int main(void)
{
	pid_t pid;
	pid = fork();

	if(pid==0)           //child process
	{
		sleep(5);
		tprintf("Hello from Child process !\n");
		tprintf("I am calling exec.\n");
		execl("/bin/ps","-a",NULL);
		//execl("/bin/ls","-l","/etc",NULL);
		tprintf("You should never see this because the child is already gone.\n");

	}
	else if(pid!=1)         //parent process
	{
		tprintf("Hello from Parent,pid %d .\n",getpid() );
		sleep(1);
		tprintf("Parent forked process %d .\n",pid);
		sleep(1);
		tprintf("Parent is waiting for child to exit .\n");
		waitpid(pid,NULL,0);
		tprintf("Parent had exited.\n");

	}
	else
		tprintf("Everything was done without error.\n");


	return 0;
}




int tprintf(const char*fmt,...)
{
	va_list args;
	struct tm *tstruct;
	time_t tsec;
	tsec = time(NULL);
	tstruct = localtime(&tsec);
	printf("%02d:%02d:%02d:%5d|",tstruct->tm_hour,tstruct->tm_min,tstruct->tm_sec,getpid() );
	va_start(args,fmt);

	return vprintf(fmt,args);
}
