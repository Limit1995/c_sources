#include<stdio.h>
int fac( int );
int sum( int);
int main(  )
{
	int s,f;
	printf( "请输入：" );
	scanf( "%d",&f);
	s=sum(f);
	printf( "\n阶层和为：%d",s);
	printf( "\n" );

	return 0;
}

int fac(int f)
{
	int i;
	int prod =1;
	for( i=1;i<=f;i++ )
		prod=prod*i;

	return prod;
}

int sum( int f )
{
	int i;
	int s=0;
	for( i=1;i<=f;i++ )
		s=s+fac( i );

	return s;
}
