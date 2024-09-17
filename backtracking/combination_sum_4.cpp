/*
Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.
*/

#include <bits/stdc++.h>
using namespace std;

int solve(vector<int>& nums, int target, vector<int>& dp){
    // init -> dp(target + 1, -1)
    if(target < 0) return -1;
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];
    
    int ways = 0;

    for(int i : nums){
        if(i <= target){
            ways += solve(nums, target - i, dp);
        }
    }
    return dp[target] = ways;
}

int main(){
    // vector<int> a1 = {1, 2, 3};
    // int t1 = 4;
    // assert(solve(a1, t1) == 7);
    // vector<int> a2 = {9};
    // int t2 = 3;
    // assert(solve(a2, t2) == 0);
    return 0;
}