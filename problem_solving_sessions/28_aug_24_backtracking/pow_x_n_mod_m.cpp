#include <bits/stdc++.h>
using namespace std;

long long int pow_x_n_mod_m(long long int x, long long int n, long long int m){
	long long int res = 1;
	x %= m;
	while(n > 0){
		if(n % 2) res = (res * x) % m;
		x = (x * x) % m;
		n /= 2;
	}
	return res;
}

int main(){
	long long int x, n, m;
	cin>>x>>n>>m;
	cout<<pow_x_n_mod_m(x, n, m);
	return 0;
}
