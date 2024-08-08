#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

void swap(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void bubble_sort(int* arr, int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n ; j++){
			if(arr[j] < arr[i]) swap(arr, i, j);
		}
	}
}

long long calculate_runtime(int* arr, int n){
	struct timeval start;
	gettimeofday(&start, NULL);
	long long start_millis = start.tv_sec*1000LL + start.tv_usec/1000;

	bubble_sort(arr, n);

	struct timeval end;
	gettimeofday(&end, NULL);
	long long end_millis = end.tv_sec*1000LL + end.tv_usec/1000;

	return end_millis - start_millis;
}

int main(){
	/*
	int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
	int n = 8;

	bubble_sort(arr, n);

	for(int i = 0; i < 8; i++) printf("%d ", arr[i]);
	*/
	srand(time(NULL));
	int* arr1 = (int*)malloc(10000* sizeof(int));
	for(int i = 0; i < 10000; i++) arr1[i] = rand();

	int* arr2 = (int*)malloc(20000* sizeof(int));
	for(int i = 0; i < 20000; i++) arr2[i] = rand();

	long long t1 = calculate_runtime(arr1, 10000);
	long long t2 = calculate_runtime(arr2, 20000);

	printf("ratio of times = %lf\n", t2*1.0/t1); 
}
