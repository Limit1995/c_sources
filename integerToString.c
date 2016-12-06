//递归法将一个整数化为字符串输出 


#include<stdio.h>


void intToStrings( long number )
{
	long consult;
	int remainder ; 
	consult = number / 10 ;

	if ( 0 != consult )
		intToStrings( consult ) ;

	remainder = number%10 ;
	printf("%d ", remainder );
}

void deleteMinus( long int *pnumber )
{
	if( *pnumber < 0 )
	{
		printf("- ");
		*pnumber = -(*pnumber) ;
	}
}

int main( )
{
	long int number ;

	scanf( "%ld" , &number ) ;

	deleteMinus( &number ) ;
	intToStrings( number ) ;

	printf("\n") ;

	
	return 0;
}
