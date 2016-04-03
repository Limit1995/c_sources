#include<stdio.h>

int main(  )
{
	int num , counter ,sum=0;
	counter =0;
    while (1)
	{
		scanf( "%d",&num );
		getchar(  );
		sum = sum + num ;
		if( num == 0 )
		{
			printf("%d %d\n", sum,counter);
			break;
		}
		counter++;
	}
	
    return 0;
}
