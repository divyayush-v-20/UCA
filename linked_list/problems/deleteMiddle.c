#include <stdio.h>
#include "../linked_list.h"
struct Node* getMiddle(struct Node* head){
    struct Node* fast = head;
    struct Node* slow = head;
    while(fast && getNext(fast)){
        fast = getNext(getNext(fast));
        slow = getNext(slow);
    }
    return slow;
}
struct Node* deleteMiddle(struct Node* head){
    if(!head || !getNext(head)) return NULL;
    if(!getNext(getNext(head))){
        setNext(head, NULL);
        return head;
    }
    struct Node* middle = getMiddle(head);
    setValue(middle, getValue(getNext(middle)));
    setNext(middle, getNext(getNext(middle)));
    return head;
}

int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x == -1) break;
        push(x);
    }
    struct Node* head = getHead();
    head = deleteMiddle(head);
    while(head){
        cout(head);
        head = getNext(head);
    }
    return 0;
}