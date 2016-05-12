#include<stdio.h>

int main( )
{
	int i,j,l,t,k,n,m ;
	char s[300];
	

	scanf("%d" , &t ) ;
	for ( i = 0 ; i < t ;  i++ )
	{
		getchar( ) ;
		for( j = 0 ; s[j-1] != '\n' ; j++ )
			s[j] = getchar( ) ;

		scanf( "%d" , &k ) ;
		n = j / k ;

		printf( "Case #%d\n" , i+1 ) ;
		for ( m = 0; m < k ; m++)
		{
			for (l = 0 ; l <= n; l++)
			{
				if( (j-1) > ( m+l*k ) )
					printf("%c", s[ m+l*k ] ) ;
			}
		}
		printf( "\n" ) ;
	}

	return 0;
}


/*
列变位法是古典密码算法中变位加密的一种方法，具体过程如下 将明文字符分割成个数固定的分组（如5个一组，5即为密钥），按一组一行的次序整齐排列，最后不足一组不放置任何字符，完成后按列读取即成密文。

比如：

原文：123456789

密钥：4

变换后的矩阵：

1234

5678

9xxx

（最后的几个x表示无任何字符，不是空格，不是制表符，就没有任何字符，下同）

密文：159263748

再比如：

原文：Hello, welcome to my dream world!

密钥：7

变换后的矩阵：

Hello,

welcome

to my

dream w

orld!xx

密文：

Hw doeetrrlloellc adoomm!,my e w

实现一个利用列变位法的加密器对Bob来说轻而易举，可是，对Bob来说，想清楚如何写一个相应的解密器似乎有点困难，你能帮帮他吗？

Input
第一行一个整数TT，表示TT组数据。

每组数据包含22行

第一行，一个字符串s(1 \leq |s| \leq 1e5)s(1≤∣s∣≤1e5)，表示经过列变位法加密后的密文

第二行，一个整数K(1 \leq K \leq |s|)K(1≤K≤∣s∣)，表示原文在使用列变位法加密时的密钥

输入保证密文字符串中只含有ASCII码在[0x20,0x7F)[0x20,0x7F)范围内的字符

Output
对于每组数据，先输出一行

Case #i:

然后输出一行，包含一个字符串s_decrypt，表示解密后得到的明文

Sample Input
4
159263748
4
Hw doeetrrlloellc adoomm!,my  e w
7
Toodming is best
16
sokaisan
1
Sample Output
Case #1:
123456789
Case #2:
Hello, welcome to my dream world!
Case #3:
Toodming is best
Case #4:
sokaisan

*/
