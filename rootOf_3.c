#include <stdio.h>
#include<math.h>

int main(  )
{
	double  x1 , x2 , quot , a , x ;

	printf("please enter a :");
	scanf( "%lf" , &a ) ;
	x1 = 10 ;
	quot = 1 ;
	x = 1 ;
	
	while( x > 0.001 )
	{
		quot = a / ( x1 *  x1 )  ;
		x2 =  ( 1/3.0 ) * ( 2 * x1 + quot ) ;
		x = fabs( x1 - x2 ) ;
		x1 = x2 ;
	}

	printf( "the cube root of %lf is %.3lf \n" , a , x2 );
	
	return 0;
}
