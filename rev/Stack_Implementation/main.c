#include <stdio.h>
#include "stack.h"

int main(){
    int arr[] = {3, 1, 2, 5, 4};
    for(int i = 0; i < 5; i++){
        push(arr[i]);
        printf("pushed %d\n", top());
    }
    printf("\n");
    while(!isEmpty()){
        printf("popped %d\n", pop());
    }
    return 0;
}