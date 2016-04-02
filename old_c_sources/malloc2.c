#include<stdio.h>
#include<malloc.h>

void ec(int *);
int main(void)
{
	int * p=(int *)malloc(sizeof(int));
	*p=23;
	ec(p);
	printf("%d",*p);

	return 0;
}

void ec(int * q)
{
	*q=33;
	free(q);

}
