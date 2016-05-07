#include<stdio.h>

int main( )
{
	int n,i;
	int a[ n ] ;                                                 //C99  new standard
	scanf ( "%d" , &n ) ; 
	for ( i = 0 ; i < n ; i++ )
	{
		scanf( "%d" , &a[ i ] ) ;
	}
	for (i = 0; i < n ; i++)
	{
		printf ( "%d" , a[ i ] ) ;
	}

	return  0;
}


//´íÎó³ÌĞò
/*
#include<stdio.h>



int main(  )
{
	int n,i;
    int array[ n ];
	for( i=0;array[ i-1 ]!='\n';i++ )
		scanf( "%d",&array[ i ] );
	for( i=0;array[ i-1 ]!='\n';i++ )
		printf ( "%d",array[ i ] );
	
    return 0;
}
*/
