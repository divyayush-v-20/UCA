#include <stdio.h>
#include <stdlib.h>
#include "sortFunc.h"

int main(){
	int size;
	scanf("%d", &size);
	
	int* array = (int *)malloc(size * sizeof(int));
	for(int i = 0; i < size; i++) scanf("%d", &array[i]);

	sort(array, size);

	for(int i = 0; i < size; i++) printf("%d ", array[i]);
	return 0;
}
