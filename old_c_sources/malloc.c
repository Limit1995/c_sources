#include<stdio.h>
#include<malloc.h>

int main()
{
	int * p;
	p=(int *)malloc(4);
	*p=88;
	printf("%d",*p);
	free(p);
	printf("   %d",*p);

	return 0;
}
