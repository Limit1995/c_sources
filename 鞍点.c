//鞍点：行最小列最大的点
#include<stdio.h>

int main( )
{
	int i , j , dot , column , counter ;
	int a[5][5]= {
		{6,7,0,0,4},
		{2,3,0,1,2},
		{3,4,0,1,1},
		{4,5,3,3,8},
		{5,6,3,0,4},
	};

	for( i=0 ; i<5 ; i++ )
	{
		dot = a[i][0] ;
		counter = 0 ;

		for( j=0 ; j<5 ; j++ )
			if( dot >= a[i][j] )
			{
				column = j ; 
				dot = a[i][j] ;
			}

		for( j=0 ; j<5 ; j++ )
			if( dot >= a[j][column] )
				counter++ ;
				
		if( counter == 5 )
			printf( "%d\n" , dot ) ;

	}
	

	return 0 ;
}
