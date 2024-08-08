#include <stdio.h>
void insertion_sort(int* arr, int n){
	for(int i = 0; i <= n - 1; i++){
		int j = i;
		while(j > 0 && arr[j - 1] > arr[j]){
			int tmp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = tmp;
			j--;
		}
	}
}
int main(){
	int arr[] = {3, 1, 2, 4, 5};
	insertion_sort(arr, 5);
	for(int i = 0; i < 5; i++) printf("%d ", arr[i]);
	return 0;
}
