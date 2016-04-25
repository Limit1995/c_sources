//求SIN（X），x为弧度,精确到0.001
//2016.4.25
#include<stdio.h>
#include<math.h>
#define ACCURACY 0.001

int main()
{
	double sinx,quot,x,j,fac;
	int i;

	j=1;
	i=1;
	fac=1;
	sinx=0;
	printf( "please enter x:" );
	scanf("%lf",&x);
	quot=x;

	while(quot>=ACCURACY)
	{
		fac=fac*i;
		if(i%2!=0)
		{
			quot=(pow(x,i))/fac;
			sinx=sinx+(j*quot);
			j=-j;
		}

		i++;
	}

	printf("sin( %lf )=%.3lf\n",x,sinx);
	
	return 0;
}
