#include "sortFunc.h"

void swap(int* array, int i, int j){
	int val = array[i];
	array[i] = array[j];
	array[j] = val;
}
void quickSort(int* array, int left, int right){
	if(left >= right) return;
	int i = left + 1;
	int pivot = array[left];
	for(int j = left + 1; j <= right; j++){
		if(array[j] < pivot) swap(array, j, i++);
	}
	swap(array, left, --i);
	quickSort(array, left, i - 1);
	quickSort(array, i + 1, right);
}
void sort(int* array, int n){
	quickSort(array, 0, n - 1);
}
