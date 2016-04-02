#include<stdio.h>

int main()
{
	int sco,a=5;
	while(a--)
	{
		printf("\n请输入成绩：");
		while( !(scanf("%d",&sco)) ||((sco<0)||(sco>100)))
		{
			printf("\n输入错误，请重新输入!");
			getchar();
		}
		
		if(sco>=90)
			printf("\nA");
		else if(sco>=80&&sco<=89)
			printf("\nB");
		else if(sco>=70&&sco<=79)
			printf("\nC");
		else if(sco>=60&&sco<=69)
			printf("\nD");
		else
			printf("\nF");
	}
	
	return 0;
}
