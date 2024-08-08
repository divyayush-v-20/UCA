#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

void swap(int* arr, int i, int j){
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

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

void merge_sort_recursive(int* arr, int* aux, int left, int right){
	if(left >= right) return;

	int mid = (left + right) / 2;
	merge_sort_recursive(arr, aux, left, mid);
	merge_sort_recursive(arr, aux, mid + 1, right);
	merge(arr, aux, left, mid, right);

}

void merge_sort(int* arr, int n){
	int* aux = (int *)malloc(n* sizeof(int));

	merge_sort_recursive(arr, aux, 0, n - 1);
	free(aux);
}

long long calculate_runtine(int* arr, int n){
	struct timeval start;
	gettimeofday(&start, NULL);
	long long start_mil = start.tv_sec*1000LL + start.tv_usec/1000;
	merge_sort(arr, n);

	struct timeval end;
	gettimeofday(&end, NULL);
	long long end_mil = end.tv_sec*1000LL + end.tv_usec/1000LL;

	return end_mil - start_mil;
}

int main(){
	//int* arr = (int *)malloc(10* sizeof(int));

	srand(time(NULL));
	
	int* arr = (int *)malloc(32000* sizeof(int));
	for(int i = 0; i < 32000; i++) arr[i] = rand();

	int* nums = (int *)malloc(64000* sizeof(int));
	for(int i = 0; i < 64000; i++) nums[i] = rand();

	long long t1 = calculate_runtine(arr, 32000);
	long long t2 = calculate_runtine(nums, 64000);

	printf("%lf", t2*1.0/t1);

	return 0;
}
