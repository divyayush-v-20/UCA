#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <sys/time.h>

void swap(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void quick_sort_recursive(int* arr, int left, int right){
	if(left >= right) return;

	int pivot = arr[left];
	int i = left + 1;

	for(int j = left + 1; j <= right; j++){
		if(arr[j] < pivot) 
			swap(arr, i++, j);
	}
	swap(arr, left, --i);
	quick_sort_recursive(arr, left, i - 1);
	quick_sort_recursive(arr, i + 1, right);
}

void quickSort(int* arr, int n){
	quick_sort_recursive(arr, 0, n - 1);
}

long long calculate_runtime(int n){
	int* arr = (int *)malloc(n* sizeof(int));
	
	srand(time(NULL));

	for(int i = 0; i < n; i++) arr[i] = n - i;

	struct timeval start;
	gettimeofday(&start, NULL);

	long long start_mil = start.tv_sec*1000LL + start.tv_usec/1000;

	quickSort(arr, n);

	struct timeval end;
	gettimeofday(&end, NULL);

	long long end_mil = end.tv_sec*1000LL + end.tv_usec/1000;

	free(arr);

	return end_mil - start_mil;
}

int main(){
	long long t1 = calculate_runtime(3200);
	long long t2 = calculate_runtime(6400);

	printf("%lf", t2*1.0/t1);
	return 0;
}
