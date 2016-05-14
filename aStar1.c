#include<stdio.h>

long int f ( int n )
{
	long int a ;
	if ( 1==n )
		a = 1 ;
	else if ( 2==n )
		a = 2 ;
	else
		a = f( n-1 ) + f( n-2 ) ;

	return a ;
}

int main( )
{
	int i = 0 ;
	int array[ 200 ] ;

	while ( 1 == scanf( "%d" , &array[i] ) )
	{
		getchar( ) ;
		printf ( "%ld\n" , f( array[i] ) ) ;
		i++ ;
	}	
	
	return 0;
}


/*
Problem Description
度熊面前有一个全是由1构成的字符串，被称为全1序列。你可以合并任意相邻的两个1，从而形成一个新的序列。对于给定的一个全1序列，请计算根据以上方法，可以构成多少种不同的序列。

Input
这里包括多组测试数据，每组测试数据包含一个正整数NN，代表全1序列的长度。

1\leq N \leq 2001≤N≤200

Output
对于每组测试数据，输出一个整数，代表由题目中所给定的全1序列所能形成的新序列的数量。

Sample Input
1
3
5
Sample Output
1
3
8

Hint

如果序列是：(111)。可以构造出如下三个新序列：(111), (21), (12)。

 */
