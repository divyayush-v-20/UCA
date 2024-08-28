#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    int pivot_index(vector<int>& arr){
        int lo = 0, hi = arr.size() - 1;

        while(lo < hi){

            int mid = lo + (hi - lo) / 2;
            if(arr[mid] > arr[hi]) lo = mid + 1;
            else hi = mid;

        }
        return lo;
    }

    int binary_search(vector<int>& arr, int lo, int hi, int target){

        while(lo <= hi){
            
            int mid = lo + (hi - lo) / 2;

            if(arr[mid] == target) return mid;
            else if(arr[mid] > target) hi = mid - 1;
            else lo = mid + 1;

        }

        return -1;
    }

    int search(vector<int>& nums, int target) {

        if(!nums.size()) return -1;
        if(nums[0] <= nums[nums.size() - 1]){
            return binary_search(nums, 0, nums.size() - 1, target);
        }
        if(target == nums[0]) return 0;

        int pivot_ind = pivot_index(nums);

        if(target > nums[0]){
            return binary_search(nums, 0, pivot_ind - 1, target);
        }
        else{
            return binary_search(nums, pivot_ind, nums.size() - 1, target);
        }

        return -1;

    }
};

int main(){

    vector<int> nums1 = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    Solution s1;
    assert(s1.search(nums1, 4) == 6);

    vector<int> nums2 = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution s2;
    assert(s2.search(nums2, 3) == 2);

    vector<int> nums3 = {5, 6, 7, 8, 9, 10, 4};
    Solution s3;
    assert(s3.search(nums3, 10) == 5);

    return 0;
}