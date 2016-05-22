//求矩阵对角线和四周元素但和
#include<stdio.h>

int main( )
{
	int sum1 = 0 ;   //对角线之和
	int sum2 = 0 ;   //四周之和
	int i ;
	int a[5][5] = {
		{1,2,3,4,5},	
		{1,2,3,4,5},	
		{1,2,3,4,5},
		{1,2,3,4,5},	
		{1,2,3,4,5},	
	};

	for (i = 0; i < 5; i++ )
	{
		sum1 = sum1 + a[i][i] + a[4-i][i];
	}
	sum1 = sum1 - a[2][2] ;

	for (i = 0; i < 5 ; i++ )
	{
		sum2 = sum2 + a[0][i] +a[4][i] + a[i][0] + a[i][4] ; 
	}
	sum2 = sum2 - a[0][0] - a[0][4] - a[4][0] - a[4][4] ;


	printf("sum1=%d\n", sum1 );
	printf("sum2=%d\n", sum2 );

	
	return 0;
}
