#include<stdio.h>
void swap(int * p,int s);
int main()
{
	int table[4]={1,2,3,4};
	printf("%d",table[0]);
	swap(table,4);
	printf("%d",table[0]);

	return 0;
}

void swap(int * p,int s)
{
	int i;
	for(i=0;i<s;i++)
	  printf("%d   ",*(p+i));
	printf("\n");
	p[0]=99;

}
