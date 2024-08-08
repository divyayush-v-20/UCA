#include <stdio.h>

int findPeak(int* arr, int n){
	int left = 0, right = n - 1;

	while(left < right){
		int mid = left + (right - left) / 2;
		if(arr[mid] < arr[mid + 1]) left = mid + 1;
		else right = mid;
	}

	return left;
}

int main(){
	int arr[] = {1, 2, 1, 3, 5, 4, 2, 3};
	printf("%d", findPeak(arr, 8));
	return 0;
}
