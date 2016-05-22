#include<stdio.h>


int main( )
{
	int i ;
	char a[] = {"abc"} ;
	char d[] = {"def"} ;
	char g[] = {"ghijklm"} ;
	char * c[] = { a , d , g } ;
	//char * c[] = { "abc" , "def" , "ghijklmn" } ;
	for (i = 0; i < 3 ; i++ )
	{
		printf("%s\n", c[i] );    //输出地址所指向的字符串
		printf("%x\n", c[i] );  //输出地址
	}
	
	return 0;
}
