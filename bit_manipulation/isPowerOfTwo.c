#include <stdio.h>
#include <stdbool.h>

bool isPowerOfTwo(int n){
	return (n & (n - 1)) == 0;
}

int main(){
	int n;
	scanf("%d", &n);
	(isPowerOfTwo(n)) ? printf("yes") : printf("no");
	return 0;
}
