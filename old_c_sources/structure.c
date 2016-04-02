#include<stdio.h>

struct stud
{
	char name[20];
	char sex;
	int score;
};

int main()
{
	struct stud st1={"limit",'m',32};
	struct stud * pst1=&st1;
	printf("%s	%c	%d\n",pst1->name,pst1->sex,pst1->score);
	printf("%s	%c	%d\n",st1.name,st1.sex,st1.score);
	return 0;
}
