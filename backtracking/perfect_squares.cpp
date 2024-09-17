// least no of perfect squares that sum upto n
#include <bits/stdc++.h>
using namespace std;

int perfectSquares(int n, vector<int>& dp){
    if(n < 0) return INT_MAX;
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int mini = INT_MAX;
    for(int i = 1; i <= sqrt(n); i++){
        int sq = i * i;
        if(sq <= n){
            int cur = perfectSquares(n - sq, dp) + 1;
            mini = min(cur, mini);
        }
    }
    return dp[n] = mini;
}

int main(){
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << perfectSquares(n, dp);
    return 0;
}