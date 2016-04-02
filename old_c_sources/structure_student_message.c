//时间:2016.02.11
//[学生信息录入排序]
#include<stdio.h>
#include<malloc.h>
struct stud        //定义学生信息结构体变量类型
{
	char name[20];
	char sex;
	int age;
	float score;
};

void input(struct stud * pstc,int leg);
void sort(struct stud * pstc1,int leg);
void output(struct stud * pstc2,int leg);
int main()
{
	int num;
	printf("请输入你要录入信息的学生个数:");
	scanf("%d",&num);
	printf("你将输入%d个学生的信息\n",num);
	struct stud * pst;
	pst=(struct stud *)malloc(num*sizeof(struct stud));	//构造学生动态数组
	
	input(pst,num);		//输入信息
	sort(pst,num);       //按分数排降序
	output(pst,num);	//输出排序后的信息
		
	return 0;
}

void input(struct stud * pstc,int leg)
{
	int i;
	for(i=0;i<leg;i++)
	{
		printf("\n请输入第%d个学生的\nname:",i+1);
		scanf("%s",pstc[i].name);

		printf("sex:");
		getchar();
		scanf("%c",&pstc[i].sex);
		
		printf("age:");
		getchar();
		scanf("%d",&pstc[i].age);
		
		printf("score:");
		getchar();
		scanf("%f",&pstc[i].score);
		
		printf("\n");
	}
}


void sort(struct stud * pstc1,int leg)
{
	int i,j;
	struct stud t;
	for(i=0;i<leg-1;i++)
	  for(j=0;j<leg-1-i;j++)
	  {
		  if(pstc1[j].score<pstc1[j+1].score)
		  {
			  t=pstc1[j];
			  pstc1[j]=pstc1[j+1];
			  pstc1[j+1]=t;
		  }
	  }
}

void output(struct stud * pstc2,int leg)
{
	int i;
	for(i=0;i<leg;i++)
	{
		printf("\n第%d名学生:\n",i+1);
		printf("name:%s	sex:%c	age:%d	score:%f\n\n",pstc2[i].name,pstc2[i].sex,pstc2[i].age,pstc2[i].score);
	}
}
