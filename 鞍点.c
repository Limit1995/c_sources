//鞍点：行最大列最小的点

#include<stdio.h>

int main( )
{
	int i , j , k , dot , column , counter ;
	int a[6][5]= {
		{4,7,0,0,4},
		{2,0,0,-1,2},
		{2,2,1,1,2},
		{4,5,3,3,8},
		{5,6,3,0,4},
		{5,6,3,0,4},
	};

	for( i=0 ; i<6 ; i++ )
	{
		dot = a[i][0] ;

		for( j=0 ; j<5 ; j++ )
			if( dot <= a[i][j] )
			{
				column = j ; 
				dot = a[i][j] ;
			}

		for( j=0 ; j<=column ; j++ )   //对同一行的多个最大值分别判断是否是鞍点
		{ 
			counter = 0 ;
			if( dot == a[i][j])
			{
				for( k=0 ; k<6 ; k++ )           //算出同一列大于等于dot的元素个数
					if( dot <= a[k][j] )
						counter++ ;

				if( 6 == counter )               //判断dot是否是同一列的最小值
					printf( "a[%d][%d] = %d\n" , i , j , dot ) ;
			}
		}
	}
	

	return 0 ;
}
