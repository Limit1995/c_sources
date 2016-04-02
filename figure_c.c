#include<stdio.h>

int main(  )
{
    int a,b,c,d;
	a=1;
	b=2;
	c=3;
	printf("%d %d %d\n",a,b,c );
	d= ((a=4) || (b=5) )&& (c=6);
	printf("%d %d %d   %d\n",a,b,c,d );
	d= (a=7) && (b=1) || (c=9);
	printf("%d %d %d   %d\n",a,b,c,d );
	
    return 0;
}
