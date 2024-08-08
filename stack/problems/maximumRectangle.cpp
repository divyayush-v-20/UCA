//maximum rectangle in histogram - leetcode-84

#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreater(vector<int>& arr){
	stack<int> s;
	int n = arr.size();
	vector<int> ans(n, n);

	for(int i = n - 1; i >= 0; i--){
		while(s.size() && arr[s.top()] >= arr[i]) s.pop();
		if(s.size()) ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

vector<int> prevGreater(vector<int>& arr){
	stack<int> s;
	int n = arr.size();
	vector<int> ans(n, -1);

	for(int i = 0; i < n; i++){
		while(s.size() && arr[s.top()] >= arr[i]) s.pop();
		if(s.size()) ans[i] = s.top();
		s.push(i);
	}
	return ans;
}

int maximumRectangle(vector<int>& arr){
	vector<int> nge = nextGreater(arr);
	vector<int> pge = prevGreater(arr);
	
	int ans = 0;

	for(int i = 0; i < arr.size(); i++){

		int ln = arr[i];
		int br = nge[i] - pge[i] - 1;
		
		ans = max(ans, abs(ln * br));
	}
	return ans;
}

int main(){
	int n;
	cin>>n;

	vector<int> v1(n);
	for(int i = 0; i < n; i++) cin>>v1[i];

	cout<<maximumRectangle(v1);

	return 0;
}

