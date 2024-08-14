#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "stack.h"

int* array = NULL;
int N = 0;
int max_size = 1;

void resize_array(int new_size){
	int* new_array = (int *)malloc(new_size*sizeof(int));
	for(int i = 0; i < N; i++){
		new_array[i] = array[i];
	}
	int* tmp = array;
	array = new_array;
	free(tmp);
}

void push(int item){
	if(N == 0){
	       	resize_array(max_size);
	}
	else if(N == max_size) {
		resize_array(2*max_size);
		max_size *= 2;
	}
	array[N++] = item;
}

int pop(){
	if(isEmpty()) return INT_MIN;
	int item = array[--N];
	if(size() > 0 && size() == max_size/4){
		max_size /= 2;
		resize_array(max_size);
	}
	return item;
}

int size(){
	return N;
}

bool isEmpty(){
	return N == 0;
}

int top(){
	return array[N - 1];
}

int testStack(){
	push(3);
	push(5);
	push(9);

	assert(isEmpty() == false);
	assert(size() == 3);

	assert(pop() == 9);
	assert(size() == 2);

	assert(pop() == 5);
	assert(size() == 1);

	assert(pop() == 3);
	assert(size() == 0);

	assert(isEmpty());
}

// int main(){
// 	testStack();
// 	return 0;
// }


