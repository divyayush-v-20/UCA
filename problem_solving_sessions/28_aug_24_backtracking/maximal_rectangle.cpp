#include <bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& arr){
	int n = arr.size();
	vector<int> res(n, n);
	stack<int> s;
	for(int i = n - 1; i >= 0; i--){
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			res[i] = s.top();
		s.push(i);
	}
	return res;
}

vector<int> prevGreaterElements(vector<int>& arr){
	int n = arr.size();
	vector<int> res(n, -1);
	stack<int> s;
	for(int i = 0; i < n; i++){
		while(!s.empty() && arr[s.top()] >= arr[i])
			s.pop();
		if(!s.empty())
			res[i] = s.top();
		s.push(i);
	}
	return res;
}

int largestRectangle(vector<int>& arr){
	vector<int> nge = nextGreaterElements(arr);
	vector<int> pge = prevGreaterElements(arr);
	int ans = INT_MIN;
	for(int i = 0; i < arr.size(); i++){
		ans = max(ans, (arr[i]) * (nge[i] - pge[i] - 1));
	}
	return ans;
}

int maximalRectangle(vector<vector<int>>& matrix){
	int m = matrix.size();
	int n = matrix[0].size();

	vector<int> res(n, 0);
	int ans = INT_MIN;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			(matrix[i][j] == 0) ? res[j] = 0 : res[j] += matrix[i][j];
		}
		ans = max(largestRectangle(res), ans);
	}
	return ans;
}

int main(){
	int m, n;
	cin>>m>>n;

	vector<vector<int>> matrix(m, vector<int>(n));

	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cin>>matrix[i][j];
		}
	}

	cout<<maximalRectangle(matrix);
	return 0;
}
