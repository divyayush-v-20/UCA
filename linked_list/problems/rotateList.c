#include <stdio.h>
#include "../linked_list.h"

struct Node* rotateList(struct Node* head, int k){
    if(!head) return head;
    int len = 0;
    struct Node* die = head;
    while(die){
        len++;
        die = getNext(die);
    }
    k %= len;
    while(k--){
        struct Node* cur = head;
        struct Node* first = head;
        while(getNext(getNext(cur))){
            cur = getNext(cur);
        }
        head = getNext(cur);
        setNext(cur, NULL);
        setNext(head, first);
    }
    return head;
}

int main(){
    while(1){
        int x;
        scanf("%d", &x);
        if(x == -1) break;
        push(x);
    }
    int k;
    scanf("%d", &k);
    struct Node* head = getHead();
    head = rotateList(head, k);
    while(head){
        cout(head);
        head = getNext(head);
    }
    return 0;
}