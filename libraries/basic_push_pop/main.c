#include <stdio.h>
#include "operations.h"

int main(){
	int arr[] = {3, 1 ,2, 5, 4};
	for(int i = 0; i < 5; i++){
		push(arr[i]);
		printf("inserted %d, current size : %d\n", FIRST_OUT(), size());
	}
	while(!isEmpty()){
		printf("popped %d, current size : %d\n", pop(), size());
	}
}
