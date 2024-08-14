#include <stdio.h>
#include <stdlib.h>
#include "../stack.h"

int* nextGreater(int* arr, int n){
    int* ans = (int *)malloc(n* sizeof(int));
    for(int i = 0; i < n; i++) ans[i] = -1;

    for(int i = n - 1; i >= 0; i--){
        while(!isEmpty() && arr[i] >= top()){
            pop();
        }
        if(!isEmpty()) ans[i] = top();
        push(arr[i]);
    }
    return ans;
}

int main(){
    int n;
    scanf("%d", &n);

    int* arr = (int *)malloc(n* sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int* ans = nextGreater(arr, n);
    for(int i = 0; i < n; i++) printf("%d ", ans[i]);

    return 0;
}