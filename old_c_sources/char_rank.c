#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
int * b_array( int );     //建立存储字符的动态数组
void sortchar( int * ,int);    //字符排序函数
void pri( int * ,int);         //字符输出函数

int main(  )
{
	int num;
	int * pch;
	printf( "\n请输入需要比较的字符的个数：" );
	while(scanf("%d",&num)!=1)
	{
		printf( "\n你的输入有误！\n请重新输入：" );
		getchar();
	}
	pch=b_array( num );
	sortchar( pch ,num);
	pri( pch ,num);
	
	return 0;
}



int * b_array( int num )               //建立存储字符的动态数组
{
	int i;
	int * pch=( int * )malloc( num*sizeof( int ) );
	if(NULL==pch)
	{
		printf("存储数组构造失败！按任意键退出程序！");
		getchar();
		exit(0);
	}
	printf( "\n请输入需要排序的字符：" );
	getchar();
	for( i=0;i<num;i++ )
	{
		*( pch+i )=getchar(  );
	}
	
	return pch;
}

void sortchar( int * pch,int num)    //字符排序函数
{
	int i,j,tem;
	
	for( i=0;i<(num-1);i++ )              //冒泡排序
	{
		for( j=0;j<(num-i-1);j++ )
		{
			if( *( pch+j ) > *( pch+j+1 ) )
			{
				tem = *( pch+j );
				*( pch+j ) = *( pch+j+1 );
				*( pch+j+1 ) = tem;
			}

		}
	}
}
	
void pri( int * pch,int num)               //字符输出函数
{
	int i;
	printf( "\n字符经过排序之后得到从小到大的排序如下：\n" );
	for( i=0;i<num;i++ )
	{
		printf( "%-c",*( pch+i ) );
	}
	printf( "\n" );
}
