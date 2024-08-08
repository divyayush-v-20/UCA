// you are given an integer array with different types of fruits, fruits[i] denotes the type of fruit, 
// you have to return the maximum number of fruits you can pick such that at most 2 different types of
// fruits in allowed, also the fruits should be from consecutive trees
#include <stdio.h>
int maxFruits(int* arr, int n){
	int one = -1;
	int two = -1;
	int last_change = 0;
	int left = 0, right = 0;
	int ans = -1;
	while(right < n){
		if(arr[right] != one && arr[right] != two){
			one = arr[last_change];
			two = arr[right];
			left = last_change;
		}
		if(right > 0 && arr[right] != arr[right - 1]) last_change = right;

		int cur_len = right - left + 1;
		ans = (cur_len > ans) ? cur_len : ans;
		right++;
	}
	return ans;
}
int main(){
	int fruits[] = {1, 2, 2, 3, 2, 2, 1};
	printf("%d", maxFruits(fruits, 7));
	return 0;
}
