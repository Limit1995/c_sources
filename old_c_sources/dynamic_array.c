#include<stdio.h>
#include<malloc.h>
int main()
{
	int i;
	int * tab;
	int leg;
	printf("请输入数组的长度:");
	scanf("%d",&leg);
	tab=(int *)malloc(4*leg);
	printf("请按顺序输入数组的元素以一个空格间隔区分 ");
	for(i=0;i<leg;i++)
	  scanf("%d ",&tab[i]);
	printf("\n数组tab的内容为:\n");
	for(i=0;i<leg;i++)
	  printf("%-d	",tab[i]);
 	
	

	return 0;
}
