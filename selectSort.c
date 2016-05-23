//选择排序法
#include<stdio.h>

int main ()
{
	int i , j , temp , min , n ;
	int array[10] ;
	
	printf("please enter 10 integers :\n");
	for ( i=0 ; i<10 ; i++ )
		scanf("%d" , &array[i] ) ;

	for ( i=0 ; i<9 ; i++ )
	{
	        min = array[i] ;
		for ( j=i ; j<10 ; j++ )
		{
			if( array[j] < min )
			{
				n = j ;
				min = array[j] ;
			}
		}
		temp = array[i] ;
		array[i] = min ;
		array[n] = temp ;
	}
	
	for( i=0 ; i<10 ; i++ )
		printf("%d " , array[i] ) ;
	printf("\n") ;

	

	return 0 ;
}
