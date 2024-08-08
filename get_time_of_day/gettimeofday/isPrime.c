#include <stdio.h>
#include <math.h>

int isPrime(int n){
	if(n <= 1) return 0;

	if(n == 2) return 1;

	for(int i = 2; i <= sqrt(n); i++){
		if(n % i == 0) return 0;
	}
	
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);

	if(isPrime(n)) printf("prime");
	else printf("not prime");

	return 0;
}
