#ifndef variable_array
#define variable_array 

typedef struct
{
    int size;
    double * varArr;
}varray;

varray varArray_cre( int init_size );
double varArray_get( varray * a, int index );
void varArray_assign( varray * a , int index , double number );
int varArray_size( varray * a );
void varArray_inflate( varray *a , int more_size );
void varArray_free( varray *a );

#endif
