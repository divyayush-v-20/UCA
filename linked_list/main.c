#include <stdio.h>
#include "linked_list.h"
int main(){
	push(1);
	push(2);
	push(3);
	push(4);
	// printList();
	struct Node* head = getHead();
	struct Node* temp = getNext(head);
	return 0;
}
