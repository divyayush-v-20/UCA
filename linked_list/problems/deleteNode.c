#include <stdio.h>
#include "../linked_list.h"
#include <stdlib.h>

struct Node* deleteNode(struct Node* head, int del){
    struct Node* tmp = head;
    while(getValue(tmp) != del){
        tmp = getNext(tmp);
    }
    struct Node* delNode = getNext(tmp);
    setValue(tmp, getValue(getNext(tmp)));
    setNext(tmp, getNext(getNext(tmp)));
    free(delNode);
    return head;
}
int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x == -1) break;
        push(x);
    }
    int del;
    scanf("%d", &del);
    struct Node* head = getHead();
    head = deleteNode(head, del);
    printList();   
    return 0;
}