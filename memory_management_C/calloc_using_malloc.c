#include <stdio.h>
#include <stdlib.h>
void* customCalloc(int n){
	char* array = (char *)malloc(n);
	for(int i = 0; i < n; i++) array[i] = 0;
	return (void *)array;
}
int main(){
	int n;
	scanf("%d", &n);
	int* array = (int *)customCalloc(n);
	for(int i = 0; i < n; i++) printf("%d ", array[i]);
	printf("\n");
}
