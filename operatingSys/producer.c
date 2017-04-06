//生产者进程
//从客户端读入按键信息，一次将“一整行”按键信息保存到一个共享存储的缓冲区内并等待读取进程将数据读走，不断重复上面的操作
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

void init(mystruct * share)        //初始化参数
{
	pthread_mutex_init(&share->mux,NULL);
	sem_init(&share->emptyBox,1,POOLSIZE);
	sem_init(&share->fullBox,1,0);
	share->producerPtr=0;
	share->customerPtr=0;
}

produce(mystruct * share)
{
	int index;
	char str[BOXSIZE];
	while(1)
	{
		scanf("%[^\n]", str);//输入一整行数据
		getchar();
		if(share->producerPtr==POOLSIZE+share->customerPtr)
			printf("The pool is full!\n");

		sem_wait(&share->emptyBox);
		pthread_mutex_lock(&share->mux);//上锁

		index=share->producerPtr%POOLSIZE;//计算生产者在缓冲池的位置
		strcpy(share->pool[index] , str);//把读到的数据写入缓冲池 
		share->producerPtr++;

		pthread_mutex_unlock(&share->mux);//开锁
		sem_post(&share->fullBox);
		
	}
}

int main()
{
	int key , shm_id;
	char * shm_buff;

/***********************共享内存初始化***********************/
	key = ftok("./producer.c",0);
	shm_id = shmget(key,SIZE,IPC_CREAT|0666);
	shm_buff = (char *)shmat(shm_id,NULL,0);
	mystruct *share = (mystruct *)shm_buff;

/***********************参数初始化***********************/
	init(share);

/***********************循环读出数据并写到缓冲池，池满时阻塞***********************/
	produce(share);
		


	return 0;
}
