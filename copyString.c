//把字符串s2中的字符串复制到s1后面
#include<stdio.h>

int main()
{
	int i ;
	char c ;
	char s1[30]="abc" ;
	char s2[30]="defghijk" ;
	
	printf(s1) ;
	printf("\n") ;
	printf(s2) ;
	printf("\n") ;
	
	c = '1' ;
	for( i=0 ; c != '\0' ; i++ )
	{
		s1[i+3]=s2[i] ;
		c = s2[i] ;
	}

	printf(s1) ;
	printf("\n") ;

	return 0 ;
}

