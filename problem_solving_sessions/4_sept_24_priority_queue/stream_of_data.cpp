#include <bits/stdc++.h>
using namespace std;

class Solution
{
    
    private:
    
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;
    
    
    public:
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxheap.size() == 0 || x <= maxheap.top()){
            maxheap.push(x);
        }
        else{
            minheap.push(x);
        }
        balanceHeaps();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxheap.size() > minheap.size() + 1){
            minheap.push(maxheap.top());
            maxheap.pop();
        }
        else if(minheap.size() > maxheap.size()){
            maxheap.push(minheap.top());
            minheap.pop();
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxheap.size() == minheap.size()){
            return (maxheap.top() + minheap.top()) / 2;
        }
        else{
            return maxheap.top();
        }
    }
};

int main(){
    vector<int> input = {5, 15, 1, 3};
    vector<int> ans;
    Solution s1;
    for(int i : input){
        s1.insertHeap(i);
        ans.push_back(s1.getMedian());
    }
    return 0;
}