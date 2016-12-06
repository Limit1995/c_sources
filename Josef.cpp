#include <stdio.h>  
int josephus(int n, int m) {  
	int x;
    if(n == 1) {  
        return 0;  
    }  
    else {  
        x = (josephus(n-1, m) + m) % n;  
	return x;
    }  
}  
  
int main() {  
    int n, m;  
    while (scanf("%d", &n) == 1) {  
        if (!n) {  
            break;  
        }  
        scanf("%d", &m);  
        int result = josephus(n, m);  
        printf("%d\n", result+1);  
    }  
    return 0;  
}  
