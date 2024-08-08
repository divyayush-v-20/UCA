#include <stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* head = NULL;
int N = 0;

void push(int item){
    Node* oldHead = head;
    head = (Node *)malloc(sizeof(Node));
    head -> data = item;
    head -> next = oldHead;
    oldHead = head;
    N++;
}

int pop(){
    int item = head -> data;
    Node* tmp = head;
    head = head -> next;
    free(tmp);
    N--;
    return item;
}

int size(){
    return N;
}

bool isEmpty(){
    return (N == 0);
}

int top(){
    if(N == 0 && !head) return INT_MIN;
    return head -> data;
}