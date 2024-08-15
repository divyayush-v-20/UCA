#include <bits/stdc++.h>
using namespace std;

void swap(int* arr, int i, int j){
    int tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

void quickSelect(int* arr, int k, int &ans, int left, int right){
    if(left >= right){
        ans = arr[left];
        return;
    }
    int i = left + 1;
    int pivot = arr[left];
    for(int j = left + 1; j <= right; j++){
        if(arr[j] > pivot){
            swap(arr, j, i++);
        }
    }
    swap(arr, left, --i);

    int count = i - left + 1;

    if(k == count){
        ans = arr[i];
    }
    else if(k < count){
        quickSelect(arr, k, ans, left, i - 1);
    }
    else{
        quickSelect(arr, k - count, ans, i + 1, right);
    }
}

int main(){
    int arr1[] = {3,2,1,5,6,4};
    int k1 = 2;
    int ans1 = -1;
    quickSelect(arr1, k1, ans1, 0, 5);
    
    int arr2[] = {3,2,3,1,2,4,5,5,6};
    int k2 = 4;
    int ans2 = -1;
    quickSelect(arr2, k2, ans2, 0, 8);

    assert(ans1 == 5);
    assert(ans2 == 4);
    return 0;
}