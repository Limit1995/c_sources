#ifndef variable_array
#define variable_array 

typedef struct
{
    int size;
    int * varArr;
}varray;

varray varArray_cre( int init_size );
int varArray_get( varray * a, int index );
void varArray_assign( varray * a , int index , int number );
int varArray_size( varray * a );
void varArray_inflate( varray *a , int more_size );
void varArray_free( varray *a );

#endif
