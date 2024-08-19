#include "operations.h"
#include <stdlib.h>
#include <limits.h>

struct Node{
	int item;
	struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
int SIZE = 0;

void push(int item){
	Node* ref = head;
	head = (Node *)malloc(sizeof(Node));
	head -> item = item;
	head -> next = ref;
	ref = head;
	SIZE++;
}

int pop(){
	int ret = head -> item;
	Node* del = head;
	head = head -> next;
	free(del);
	SIZE--;
	return ret;
}

bool isEmpty(){
	return !SIZE;
}

int size(){
	return SIZE;
}

int FIRST_OUT(){
	if(SIZE <= 0) return INT_MIN;
	return head -> item;
}