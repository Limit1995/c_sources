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
