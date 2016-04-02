#include<stdio.h>

int main(  )
{
	int a, b, c,i;
	char cc[ 9 ];
    scanf( "%d%d",&a,&b );
	for (i = 0; i < a; i++)
	{
		cc[ i ]=getchar(  );
	}
	for (i = 0; i < a; i++)
	{
		printf("%c\n", cc[ i ]);
	}

	printf("%d\n", a);

	
	
    return 0;
}
