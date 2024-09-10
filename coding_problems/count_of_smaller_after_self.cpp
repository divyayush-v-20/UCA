#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sorted_posi(vector<int>& arr, int key){
        int left = 0;
        int right = arr.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(arr[mid] < key){
                left = mid + 1;
            }
            else right = mid;
        }
        return left;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        vector<int> ans(n, 0);
        for(int i = n - 1; i >= 0; i--){
            int posi = sorted_posi(arr, nums[i]);
            ans[i] = posi;
            arr.insert(arr.begin() + posi, nums[i]);
        }
        return ans;
    }
};

int main(){
    int n;
    cin>>n;
    vector<int> array(n);
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }
    Solution s;
    vector<int> smaller_cnt = s.countSmaller(array);
    for(int i : smaller_cnt){
        cout<<i<<" ";
    }
    return 0;
}