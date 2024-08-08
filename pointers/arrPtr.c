#include <stdio.h>
int main(){
	int arr[] = {3, 1, 2, 4, 5};
	int* ptr = arr;
	for(int i = 0; i < 5; i++){
		printf("%d\n", *(arr + i)); 
	}
	printf("printing out of bounds\n");
	for(int i = 5; i < 7; i++){
		printf("%d\n", *(arr + i));
	}
}
