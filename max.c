#include<stdio.h>
int main(  )
{
	int a,b,c;
	printf( "\n请输入a的值:" );
	scanf( "%d",&a );
	printf( "\n请输入b值:" );
	scanf( "%d",&b );
	printf( "\n请输入c的值:" );
	scanf( "%d",&c );

	if( a>b )
	{
		if( a>c )
			printf( "\n最大值是：a=%d",a );
		else if( a<c ) 
			printf( "\n最大值是：c=%d",c );
		else
			printf( "\n最大值是：a=c=%d",a );
	}
	else if( a<b )
	{
		if( b>c )
			printf( "\n最大值是：b=%d",b );
		else if( b<c ) 
			printf( "\n最大值是：c=%d",c );
		else
			printf( "\n最大值是：b=c=%d",b );
	}
	else
	{
		if( a<c )
			printf( "\n最大值是：c=%d",c );
		else if( a>c )
			printf( "\n最大值是：a=b=%d",b );
		else
			printf( "\n最大值是：a=b=c=%d",b );
			

	}
	printf( "\n" );
		
	return 0;
}
