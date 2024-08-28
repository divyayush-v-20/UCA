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

    ListNode* recursiveReversal(ListNode* cur, ListNode* prev){

        if(!cur) return prev;

        ListNode* fwd = cur -> next;
        cur -> next = prev;

        return recursiveReversal(fwd, cur);

    }    

    ListNode* iterativeReversal(ListNode* head){

        ListNode* cur = head;
        ListNode* prev = NULL;

        while(cur){

            ListNode* fwd = cur -> next;
            cur -> next = prev;
            prev = cur;
            cur = fwd;

        }

        return prev;

    }

    ListNode* reverseList(ListNode* head) {

        if(!head || !head -> next) return head;

        // return iterativeReversal(head);

        ListNode* cur = head;
        ListNode* prev = NULL;
        return recursiveReversal(cur, prev);
        
    }
};

int main(){

    //TC1 - 1 -> 2 -> 3 -> 4 -> 5
    //O/P - 5 -> 4 -> 3 -> 2 -> 1

    vector<int> list1 = {1, 2, 3, 4, 5};

    ListNode* l1 = new ListNode(-1);
    ListNode* a1 = new ListNode(-1);

    for(int i = 0; i < 5; i++){
        l1 -> next = new ListNode(list1[i]);
        l1 = l1 -> next;

        a1 -> next = new ListNode(list1[5 - i - 1]);
        a1 = a1 -> next;
    }

    Solution s1;
    l1 = s1.reverseList(l1 -> next);

    a1 = a1 -> next;

    while(l1 && a1){
        assert(l1 -> val == a1 -> val);
        l1 = l1 -> next;
        a1 = a1 -> next;
    }
    
    assert(a1 == l1);

    return 0;
}