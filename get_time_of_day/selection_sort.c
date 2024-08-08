#include <stdio.h>
#include <assert.h>
#include<sys/time.h>
#include<stdlib.h>
#include<time.h>

void sort(int arr[], int n) {
	for(int i = 0; i < n - 1; i++){
		int min_idx = i;
		for(int j = i + 1; j < n; j++){
			if(arr[min_idx] > arr[j]) {
				min_idx = j;
			}
		}
		int swap = arr[i];
		arr[i] = arr[min_idx];
		arr[min_idx] = swap;
	}
}

long long calculate_runtime(int arr[],int n){
	struct timeval before;
	gettimeofday(&before, NULL);

	long long before_millis = before.tv_sec*1000LL + before.tv_usec/1000;

	sort(arr, n);

	struct timeval after;
	gettimeofday(&after, NULL);

	long long after_millis = after.tv_sec*1000LL + after.tv_usec/1000;

	return after_millis - before_millis;
}

void test_sample_input(){
	int arr[] = {3, 1, 5, 2, 4};
	int expected_output[] = {1, 2, 3, 4, 5};

	sort(arr, 5);

	for(int i = 0; i < 5; i++){
		assert(arr[i] == expected_output[i]);
	}
}

int main() {
	//int arr[] = {3, 1, 5, 2, 4};
	//int n = 5;

	//sort(arr, n);

	//for(int i = 0; i < n; i++){
	//	printf("%d ", arr[i]);
	//}
	
	//test_sample_input();

	//generate 32000 random nums
	
	srand(time(NULL));

	int* arr = (int*) malloc(sizeof(int)*32000);

	for(int i = 0; i < 32000; i++) arr[i] = rand();
	
	long long t1 = calculate_runtime(arr,32000);

	int* nums = (int*) malloc(sizeof(int)*64000);

	for(int i = 0; i < 64000; i++) nums[i] = rand();

	long long t2 = calculate_runtime(nums,64000);
	
	printf("%lf",t2*1.0/t1);

	return 0;
}
