#include<stdio.h>
#include<stdlib.h>
#include"varArray.h"
//  typedef struct
//  {
//      int size;
//      int * varArr;
//  }varray;

varray varArray_cre( int init_size )
{
    varray a;
    a.size = init_size;
    a.varArr = malloc(sizeof(int)*init_size);
    
    return a;
}

int varArray_get( varray * a, int index )
{
    return a->varArr[ index ];
}

void varArray_assign( varray * a, int index , int number  )
{
    a->varArr[ index ] = number;
}

int varArray_size( varray * a )
{
    return a->size;
}
    
void varArray_inflate( varray *a , int more_size )
{
    int i;
    int *p =malloc( sizeof( a->size+more_size ) );
    for (i = 0; i<a->size; i++)
    {
	p[ i ] = varArray_get( a,i );
    }
    free( a );
    a->varArr=p;
    a->size=a->size + more_size;
}
void varArray_free( varray *a )
{
    free( a->varArr );
    a->varArr=NULL;
    a->size=0;
}


int main(  )
{
    int i;
    varray a;
    a = varArray_cre ( 4 );
    for (i = 0; i<varArray_size( &a ); i++)
    {
	varArray_assign( &a,i,i );
    }

    for( i=0;i<varArray_size( &a );i++ )
	printf("%d\n", varArray_get( &a,i ));
    
    return 0;
}
