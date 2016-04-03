//输入数字n和k，然后求n的阶乘，接着把n的阶乘值后的0全去掉；
//最后就输出去掉尾0后的数的后k数
//2016.3.14

#include<stdio.h>
#define unlint unsigned long int 

unlint fac(int n);
void ks(unlint tem1 ,int k);
void del0(unlint f,int k);

int main()
{
	 int n,k;
	 unlint f; 

	 printf("n=");
	 while (scanf("%d",&n)!=1)                     //判断输入是否合法
	 {
		 getchar(  );
		 printf("\n请重新输入：\n n=" ); 
	 }
	 
	 printf("k=");
	 while (scanf("%d",&k)!=1)                     //同上一
	 {
		 getchar(  );
		 printf("\n请重新输入：\n k=" ); 
	 }

	 if( n==0 )                                      //处理n等于0的情况
	 {
		 printf("\n阶乘为：0");
		 printf("\n去除尾0后的值为空");
		 printf("\n去除尾0后的后k位数为空\n");
	 }
	 else                                               //n!=0的情况
	 {
		f=fac(n);
		del0(f,k);
	 }

	 return 0;
}


unlint fac(int n)                                        //求阶乘函数
{
	int i;
	unlint f=1;
	
	for(i=1;i<=n;i++)
		f=f*i;
	
	printf("阶乘为：%ld",f);

	return f;
}

void ks(unlint tem1,int k)                            //把去尾0后的数的后k位输出
 {
	int tem2,i;
	
	tem2=tem1 ;
	printf("\n去除尾0后的后k位数为：" );
	
	while(k--)
	{
		i=k;
		while(i--)
			tem2=tem2/10;
		tem2=tem2%10;
		printf("%d",tem2);
		tem2 = tem1 ;
	}
	
	printf("\n");
}

void del0(unlint f,int k)                            //把尾零去除
{
	 int i,j;
	 unlint tem1,tem;
	 
	 tem = f;
	 for(i=0;i<10000;i++)
	 {
		j=i;
		
		while(j--)
			tem=tem/10;
		
		tem1=tem;
		tem=tem%10;
		
		if(tem!=0)
		{
			printf("\n去除尾0后的值为：%ld",tem1);
			ks(tem1,k);

			return;
		}
		
		tem = f;
	 }

}
