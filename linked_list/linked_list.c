#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "linked_list.h"

typedef struct Node{
	int val;
	struct Node* next;
}Node;

Node* head = NULL;
Node* tail = NULL;

void push(int item){

	Node* newNode = (Node *)malloc(sizeof(Node));
	newNode -> val = item;
	newNode -> next = NULL;
	
	if(tail) tail -> next = newNode;

	else head = newNode;

	tail = newNode;

}
void printList(){
	Node* tmp = head;
	while(tmp != NULL){
		printf("%d ", tmp -> val);
		tmp = tmp -> next;
	}
	free(tmp);
}

struct Node* getHead(){
	return head;
}

void setNext(struct Node* cur, struct Node* nxt){
	cur -> next = nxt;
}

struct Node* getNext(struct Node* cur){
	return cur -> next;
}

void cout(struct Node* node){
	printf("%d ", node -> val);
}