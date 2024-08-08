#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "queue.h"

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* front = NULL;
Node* rear = NULL;
int N = 0;

void push(int item){
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode -> val = item;
	newNode -> next = NULL;
	if(rear){
		rear -> next = newNode;
	}
	else{
		front = newNode;
	}
	rear = newNode;
	N++;
}
int pop(){
	if(!front) return INT_MIN;
	Node* del = front;
	int item = del -> val;
	front = front -> next;

	if(!front) rear = NULL;

	free(del);
	N--;
	return item;
}
int size(){
	return N;
}
bool isEmpty(){
	return (front && rear);
}
int getFront(){
	if(!front) return INT_MIN;
	return front -> val;
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
