/*
Problem statement
Design a data structure to implement deque of size ‘N’. It should support the following operations:

pushFront(X): Inserts an element X in the front of the deque. Returns true if the element is inserted, otherwise false.

pushRear(X): Inserts an element X in the back of the deque. Returns true if the element is inserted, otherwise false.

popFront(): Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

popRear(): Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.

getFront(): Returns the first element of the deque. If the deque is empty, it returns -1.

getRear(): Returns the last element of the deque. If the deque is empty, it returns -1.

isEmpty(): Returns true if the deque is empty, otherwise false.

isFull(): Returns true if the deque is full, otherwise false.
*/

#include <bits/stdc++.h> 
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode* prev;
    ListNode(int x){
        val = x;
        next = NULL;
        prev = NULL;
    }
};

class Deque
{
    private:

    ListNode* front;
    ListNode* rear;
    int size;
    int capacity;

    public:
    // Initialize your data structure.
    
    Deque(int n)
    {
        // Write your code here.
        front = NULL;
        rear = NULL;
        size = 0;
        capacity = n;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // Write your code here.
        if(size == capacity){
            return false;
        }
        if(!front){
            front = new ListNode(x);
            rear = front;
            size++;
            return true;
        }
        else{
            ListNode* newNode = new ListNode(x);
            newNode -> next = front;
            front -> prev = newNode;
            front = newNode;
            size++;
            return true;
        }
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // Write your code here.
        if(size == capacity){
            return false;
        }
        if(!front){
            front = new ListNode(x);
            rear = front;
            size++;
            return true;
        }
        else{
            rear -> next = new ListNode(x);
            rear -> next -> prev = rear;
            rear = rear -> next;
            size++;
            return true;
        }
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // Write your code here.
        if(size == 0){
            return -1;
        }
        int ret = front -> val;
        ListNode* del = front;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            front = front -> next;
            front -> prev = NULL;
        }
        delete del;
        size--;
        return ret;

    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // Write your code here.
        if(size == 0){
            return -1;
        }
        int ret = rear -> val;
        ListNode* del = rear;
        if(front == rear){
            front = NULL;
            rear = NULL;
        }
        else{
            rear = rear -> prev;
            rear -> next = NULL;
        }
        delete del;
        size--;
        return ret;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        // Write your code here.
        if(size == 0){
            return -1;
        }
        return front -> val;
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        // Write your code here.
        if(size == 0){
            return -1;
        }
        return rear -> val;
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        // Write your code here.
        return size == 0;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        // Write your code here.
        return size == capacity;
    }
};

int main(){
    Deque q1 = Deque(10);

    assert(q1.isEmpty() == 1);
    
    for(int i = 1; i <= 10; i++){
        assert(q1.pushRear(i));
    }

    assert(q1.isFull() == 1);

    int front = 0;

    while(!q1.isEmpty()){
        assert(q1.popFront() == ++front);
    }

    assert(q1.isEmpty() == 1);

    return 0;
}