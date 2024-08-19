#include <stdlib.h>
#include <limits.h>
#include "operations.h"

struct Node{
	int item;
	struct Node* next;
};

typedef struct Node Node;

Node* front = NULL;
Node* rear = NULL;

int SIZE = 0;

void push(int item){
	if(!SIZE){
		rear = (Node *)malloc(sizeof(Node));
		rear -> item = item;
		front = rear;
		SIZE++;
	}
	else{
		Node* tmp = rear;
		rear = (Node *)malloc(sizeof(Node));
		rear -> item = item;
		tmp -> next = rear;
		tmp = rear;
		SIZE++;
	}
}

int pop(){
	if(!SIZE){
		return INT_MIN;
	}
	int item = front -> item;
	Node* del = front;
	front = front -> next;
	free(del);
	SIZE--;
	return item;
}

int FIRST_OUT(){
	if(!SIZE) return INT_MIN;
	return front->item;
}

int size(){
	return SIZE;
}

bool isEmpty(){
	return !SIZE;
}