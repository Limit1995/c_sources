#include<stdio.h>
#include<stdlib.h>
#include"varArray.h"
//  typedef struct
//  {
//      int size;
//      double * varArr;
//  }varray;

varray varArray_cre( int init_size )
{
    varray a;
    a.size = init_size;
    a.varArr = malloc(sizeof( double ) * init_size);
    return a;
}

double varArray_get( varray * a, int index )
{
    if( index < a->size )
	return a->varArr[ index ];
    else
	return -1 ;
}

void varArray_assign( varray * a, int index , double number  )
{
    int block = 20 ;
    int larger ; 
    larger = ( index/block +1 ) * block ;
    if( index >= a->size )
	varArray_inflate( a, larger );
    a->varArr[ index ] = number;
}

int varArray_size( varray * a )
{
    return a->size;
}
    
void varArray_inflate( varray *a , int larger )
{
    int i;
    double *p =malloc( sizeof( double ) * ( a->size + larger ) );
    for ( i = 0 ; i < a->size ; i++ )
	p[ i ] = varArray_get( a,i );
    free( a->varArr );
    a->varArr = p;
    a->size = a->size + larger ; 
}

void varArray_free( varray *a )
{
    free( a->varArr );
    a->varArr=NULL;
    a->size=0;
}


int main(  )
{
    int i=0;
    double tem=0;
    varray table;

    table = varArray_cre ( 10 );

    while( tem != -1 )
    {
	scanf( "%lf",&tem );
	varArray_assign( &table , i , tem );
	i++;
    }

    for( i=0 ; i < varArray_size ( &table ) ; i++ )
	printf("%lf\n", varArray_get( &table ,i ) );

    varArray_free ( &table );
    
    return 0;
}
