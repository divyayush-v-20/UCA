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
int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x == -1) break;
        push(x);
    }
    struct Node* head = getHead();
    cout(getMiddle(head));
    return 0;
}