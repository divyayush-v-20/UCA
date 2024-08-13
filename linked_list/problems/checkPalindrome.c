#include <stdio.h>
#include "../linked_list.h"

struct Node* reverse(struct Node* cur, struct Node* pre){
    if(!cur) return pre;
    struct Node* fwd = getNext(cur);
    setNext(cur, pre);
    return reverse(fwd, cur);
}

int isPalindrome(struct Node* head){
    struct Node* mid = head;
    struct Node* die = head;
    while(die && getNext(die)){
        die = getNext(getNext(die));
        mid = getNext(mid);
    }
    mid = reverse(mid, NULL);
    while(mid && head){
        if(getValue(mid) != getValue(head)) return 0;
        mid = getNext(mid);
        head = getNext(head);
    }
    return 1;
}

int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x == -1) break;
        push(x);
    }
    struct Node* head = getHead();
    isPalindrome(head) ? printf("yes") : printf("no");
    return 0;
}