// 消费者进程
//生成两个进程，用于显示缓冲区内的信息，这两个进程并发读取缓冲区信息后将缓冲区清空
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/ipc.h>

#define SIZE 1000                //共享内存字节数
#define POOLSIZE 5                //缓冲池的大小 
#define BOXSIZE 20                //缓冲池中每一个单元的大小

typedef struct shm_struct      //共享数据结构体
{
	char pool[POOLSIZE][BOXSIZE];
	pthread_mutex_t mux;
	sem_t  fullBox,emptyBox;         //fullBox被填满的单元个数，emptyBox空单元个数
	int producerPtr,customerPtr;
}mystruct;


consume(mystruct *share)
{
	int index;
	char str[BOXSIZE];

	while(1)
	{
		sleep(2);
		if(share->producerPtr==share->customerPtr)
			printf("The pool is empty! >> from pid=%d\n",getpid());

		sem_wait(&share->fullBox);
		pthread_mutex_lock(&share->mux);
			
		index=share->customerPtr%POOLSIZE;
		strcpy(str,share->pool[index]);
		strcpy(share->pool[index],"");
		printf("%s >>from pid=%d\n",str,getpid());
		share->customerPtr++;
			
		pthread_mutex_unlock(&share->mux);
		sem_post(&share->emptyBox);

	}
		
}

int main()
{
	int key , shm_id;
	char * shm_buff;
	pid_t pid;

	pid = fork();
	if(0==pid)                    //消费者并发进程之一
	{
/***********************共享内存初始化***********************/
		key = ftok("./producer.c",0);
		shm_id = shmget(key,SIZE,IPC_CREAT|0666);
		shm_buff = (char *)shmat(shm_id,NULL,0);
		mystruct *share = (mystruct *)shm_buff;
		printf("pid=%d\n",getpid());
/***********************读取缓冲池数据并清空***********************/
		consume(share);
		exit(EXIT_SUCCESS);
	}

	else                         //消费者并发进程之一
	{
/***********************共享内存初始化***********************/
		key = ftok("./producer.c",0);
		shm_id = shmget(key,SIZE,IPC_CREAT);
		shm_buff = (char *)shmat(shm_id,NULL,0);
		mystruct *share = (mystruct *)shm_buff;

		printf("pid=%d\n",getpid());
/***********************读取缓冲池数据并清空***********************/
		consume(share);
		waitpid(pid,NULL,0);
		exit(EXIT_SUCCESS);
	}




	return 0;
}
