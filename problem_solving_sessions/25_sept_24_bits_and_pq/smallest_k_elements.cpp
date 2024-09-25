#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }
    int k;
    cin >> k;
    while(k--){
        cout << pq.top() <<" ";
        pq.pop();
    }
    return 0;
}