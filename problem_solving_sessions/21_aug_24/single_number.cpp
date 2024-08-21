// every element is present thrice in array except one, find that
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int single(vector<int>& arr){
        int n1 = 0, n2 = 0;
        for(int i : arr){
            n1 ^= (i & ~n2);
            n2 ^= (i & ~n1);
        }
        return n1;
    }
};
int main(){
    vector<int> nums1 = {0, 0, 0, 1, 1, 1, 2, 3, 3, 3};
    vector<int> nums2 = {7, 2, 1, 7, 2, 7, 2};
    
    Solution s1;
    Solution s2;

    assert(s1.single(nums1) == 2);
    assert(s2.single(nums2) == 1);

    return 0;
}