#include <stdio.h>
int main(){
    int arr[] = {1, 1, 1, 2, 1, 2, 3, 3, 3, 4}; // ans -> 3,4
    for(int i = 0; i < 10; i++){
        arr[arr[i]] *= -1;
    }
    for(int i = 0; i < 10; i++){
        if(arr[i] < 0) printf("%d ", i);
    }
    return 0;
}