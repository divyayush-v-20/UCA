#include <stdio.h>
#include <stdlib.h>

void sort(int* arr, int size, int(*compare)(int, int)){
	for(int i = 0; i < size - 1; i++){
		for(int j = i + 1; j < size; j++){
			if(compare(arr[i], arr[j])){
				int tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}
int asc(int a, int b){
	return (a > b) ? 1 : 0;
}
int desc(int a, int b){
	return (a > b) ? 0 : 1;
}
void printArr(int* arr, int size){
	for(int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("\n");
}
int main(){
	int size;
	scanf("%d", &size);

	int* arr = (int *)malloc(size* sizeof(int));
	for(int i = 0; i < size; i++) scanf("%d", &arr[i]);

	printf("sorting in ascending order : ");
	sort(arr, size, asc);
	printArr(arr, size);
	printf("sorting in descending order : ");
	sort(arr, size, desc);
	printArr(arr, size);

	free(arr);

	return 0;
}
