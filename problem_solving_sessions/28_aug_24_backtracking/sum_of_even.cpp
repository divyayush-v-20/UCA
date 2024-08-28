// given a number n, return the sum of all even fibonacci numbers till n
#include <bits/stdc++.h>
using namespace std;

int get_fib_sum_backtrack(int f1, int f2, int n){
	int f3 = f1 + f2;
	if(f3 > n) return 0;

	int cur_sum = (f3 % 2) ? 0 : f3;
	return cur_sum + get_fib_sum_backtrack(f2, f3, n);
}

int get_fib_sum_tabulation(int n){
	//using tabulation
	int f1 = 0, f2 = 1;
	int sum = 0;
	int i = 3;
	while(true){
		int f3 = f1 + f2;
		if(f3 > n) break;
		if(!(f3 % 2)) sum += f3;
		f1 = f2;
		f2 = f3;
	}
	return sum;
}

int main(){
	int n;
	cin>>n;
	//int sum = get_fib_sum_backtrack(0, 1, n);
	int sum = get_fib_sum_tabulation(n);
	cout<<sum;
	return 0;
}
