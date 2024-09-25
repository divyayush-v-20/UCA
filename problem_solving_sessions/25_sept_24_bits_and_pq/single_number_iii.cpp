/*
Given an integer array nums, in which exactly two elements appear only once and all the other elements appear
exactly twice. Find the two elements that appear only once. You can return the answer in any order.

You must write an algorithm that runs in linear runtime complexity and uses only constant extra space
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> singleNumber(vector<int>& nums) {
        int x = 0;
        for(int i : nums) x ^= i;

        int j = 0;
        while(((x >> j) & 1) == 0) j++;

        int a = 0, b = 0;

        for(int i : nums){
            if(((i >> j) & 1) == 0) a ^= i;
            else b ^= i;
        }

        return {a, b};
}
