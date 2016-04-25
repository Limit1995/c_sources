//求e的x次方，精确到0.0001
//2016.4.25
#include<stdio.h>
#include<math.h>
#define ACCURACY 0.0001

int main()
{
	double ex,quot,x,fac;
	int i;
	
	printf("please enter x:");
	scanf("%lf",&x);
	fac=1;
	ex=1;
	quot=1;

	for(i=1;quot>=ACCURACY;i++)
	{
		fac=fac*i;
		quot=(pow(x,i))/fac;
		ex=ex+quot;
	}

	printf("e的%lf次方为%.4lf\n",x,ex);

	return 0;
}
