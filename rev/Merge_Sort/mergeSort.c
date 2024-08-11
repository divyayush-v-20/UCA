#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

void merge(int* arr, int* aux, int left, int mid, int right){
	for(int k = left; k <= right; k++) aux[k] = arr[k];

	int i = left;
	int j = mid + 1;

	for(int k = left; k <= right; k++){
		if(i > mid) arr[k] = aux[j++];
		else if(j > right) arr[k] = aux[i++];
		else if(aux[i] <= aux[j]) arr[k] = aux[i++];
		else arr[k] = aux[j++];
	}
}

void mergeSort(int* arr, int* aux, int left, int right){
	if(left >=  right) return;

	int mid = left + (right - left) / 2;
	
	mergeSort(arr, aux, left, mid);
	mergeSort(arr, aux, mid + 1, right);
	merge(arr, aux, left, mid, right);
}

void mergeSort_init(int* arr, int n){
	int* aux = (int *)malloc(n* sizeof(int));
	mergeSort(arr, aux, 0, n - 1);
}

bool isSorted(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		if(arr[i] > arr[i + 1]) 
			return false;
	}
	return true;
}

int main(){
	
	int arr1[] = {3, 1, 5, 4, 2};
	int arr2[] = {7, 1, 9, 6, 8, 5, 2, 4, 3};
	int arr3[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};


	mergeSort_init(arr1, 5);
	mergeSort_init(arr2, 9);
	mergeSort_init(arr3, 10);

	assert(isSorted(arr1, 5) == true);
	assert(isSorted(arr2, 9) == true);
	assert(isSorted(arr3, 10) == true);

	return 0;
}
