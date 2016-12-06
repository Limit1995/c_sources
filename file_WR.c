#include<stdio.h>

int main( )
{
	FILE *fp = fopen("a.txt", "r");

	char str[100] ;

	if( fp )
	{
		int i ;
		for( i=0 ; i<100 ; i++ )
			fscanf( fp , "%c" , &str[i] ) ;

		for( i=0 ; i<100 ; i++ )
			printf( "%c" , str[i] ) ;

		fclose( fp ) ;
	}
	else
		printf("no such file\n") ;

	
	return 0;
}
