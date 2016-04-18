#include<stdio.h>

int main(  )
{
	int num , j , tem , sum , n;

	for( num=1;num<=1000;num++ )
		{
			sum = 0;

			for( j=1;j<num ;j++ )                               //寻找因子
				{
					tem=num % j;
					if( tem == 0 )
						sum = sum + j ;                          //对因子求和
				}

			if( sum == num )
				{
					printf("%d its factors are ", num );          //输出完数

					for( j=1;j<num ;j++ )                         //重新寻找因子并输出
					{
						tem=num % j;
						if( tem == 0 )
						{
							printf("%d ", j );
						}
					}

					printf("\n");
				}
		}
	
    return 0;
}
