#include <bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int x){
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* tmp = new ListNode(-1);
        ListNode* head = tmp;

        while(list1 && list2){

            if(list1 -> val <= list2 -> val){
                tmp -> next = new ListNode(list1 -> val);
                list1 = list1 -> next;
                tmp = tmp -> next;
            }

            else{
                tmp -> next = new ListNode(list2 -> val);
                list2 = list2 -> next;
                tmp = tmp -> next;
            }

        }

        while(list1){

            tmp -> next = new ListNode(list1 -> val);
            list1 = list1 -> next;
            tmp = tmp -> next;

        }

        while(list2){

            tmp -> next = new ListNode(list2 -> val);
            list2 = list2 -> next;
            tmp = tmp -> next;
            
        }

        return head -> next;
    }
};