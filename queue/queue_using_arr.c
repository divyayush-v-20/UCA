#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

int* array = NULL;
int N = 0;
int max_size = 1;
int front;

void resize_array(int new_size){
	int* new_array = (int*)malloc(new_size* sizeof(int));
	for(int i = 0; i < N; i++) new_array[i] = array[i];
	free(array);
	array = new_array;
	front = 0;
}

void push(int item){
	if(N == 0){
		resize_array(max_size);
	}
	else if(N == max_size){
		max_size *= 2;
		resize_array(max_size);
	}
	array[(front + N) % max_size] = item;
	N++;
}

int pop(){
	if(isEmpty()) return INT_MIN;
	int item = array[front];
	front = (front + 1) % max_size;
	N--;
	if(size() > 0 && size() == max_size / 4){
		max_size /= 2;
		resize_array(max_size);
	}
	return item;
}

int size(){
	return N;
}

bool isEmpty(){
	return (N == 0);
}

int getFront(){
	if(N == 0) return INT_MIN;
	return array[front];
}

int main(){
	push(1);
        push(2);
        push(3);
        push(4);

        assert(size() == 4);

        assert(getFront() == 1);
        assert(pop() == 1);

        assert(getFront() == 2);
        assert(pop() == 2);
	return 0;
}
