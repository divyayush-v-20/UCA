#include <stdio.h>
#include <stdlib.h>

int main(){
	/*
	char* str = "Hello Everyone";
	str[0] = 'e';
	printf("%s", str);
	
	
	int* var = NULL;
	*var = 20;
	printf("%d\n", *var);
	*/

	int* ptr = (int *)malloc(sizeof(int));
	*ptr = 10;
	free(ptr);
	*ptr = 5;

	printf("%d\n", *ptr);
	return 0;
}
