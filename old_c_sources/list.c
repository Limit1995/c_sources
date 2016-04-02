//构建一个链表并且存入数据和输出数据
//2016.2.19

#include<stdio.h>
#include<malloc.h>
struct node
{
	int data;
	struct node * next; 
};

void clist(struct node * ph);
void tsee(struct node * ph);

int main(void)
{
	struct node * phead=(struct node *)malloc(sizeof(struct node));
	clist(phead);
	tsee(phead);	

	return 0;
}


void clist(struct node * ph)
{
	int leg,val,i,a;
	struct node * tem=ph;
	
	printf("请输入你要构建的链表的长度:");

	while(scanf("%d",&leg)!=1)
	{
		printf("你的输入不合法!\n请重新输入一个非零自然数:");
		getchar();
		printf("\n");
	}
	
	for(i=0;i<leg;i++)
	{
		struct node * pnew=(struct node *)malloc(sizeof(struct node));
		printf("\n请输入第%d个节点的数据:",i+1);
		getchar();
		scanf("%d",&val);

		tem->next=pnew;   //画
		pnew->data=val;   //  示意
		pnew->next=NULL;  //      图
		tem=pnew;         //        理解
	}
}

void tsee(struct node * ph)	
{
	int i;
	struct node * tem=ph->next;
	for(i=0;tem!=NULL;i++)
	{
		
		printf("\n第%d个节点数据为:%d",i+1,tem->data);
		tem=tem->next;

	}
}
