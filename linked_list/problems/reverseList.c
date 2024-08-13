#include <stdio.h>
#include <stdlib.h>
#include "../linked_list.h"

struct Node* recursiveReverse(struct Node* cur, struct Node* prev){
    if(!cur) return prev;

    struct Node* fwd = getNext(cur);
    setNext(cur, prev);
    return recursiveReverse(fwd, cur);
}

struct Node* reverseList(struct Node* head){
    // struct Node* cur = head;
    // struct Node* prev = NULL;
    // while(cur){
    //     struct Node* fwd = getNext(cur);
    //     setNext(cur, prev);
    //     prev = cur;
    //     cur = fwd;
    // }
    // return prev;
    return recursiveReverse(head, NULL);
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        push(x);
    }
    struct Node* head = getHead();
    head = reverseList(head);
    while(head){
        cout(head);
        head = getNext(head);
    }
    return 0;
}