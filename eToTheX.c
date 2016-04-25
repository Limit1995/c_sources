#include<stdio.h>
#include<math.h>

int main()
{
	double sinx,quot,x,j,fac;
	int i;

	j=1;
	i=1;
	fac=1;
	sinx=0;
	scanf("%lf",&x);
	

	while(i<100)
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

	printf("%lf\n",sinx);
	
	return 0;
}
