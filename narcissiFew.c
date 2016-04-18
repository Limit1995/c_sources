#include<stdio.h>
#include<math.h>

int main(  )
{
	int num , few , ten , hundred , sum ;
	sum = 0;

	for( num=100;num<=999;num++ )
		{
			few = num % 10;
			ten = ( num / 10 ) % 10;
			hundred =num / 100;

			sum = pow(few,3) + pow(ten,3) + pow(hundred,3);

			if( sum == num )
					printf("%-4d", num );
		}

	printf("are narcissi fews\n");
	
    return 0;
}
