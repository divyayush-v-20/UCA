// given a rod of length n, and segment sizes x, y, z
// cut the rod in x, y, z sized segments in such a way that 
// you obtain the maximum no. of segments
// eg, len = 7, x, y, z = {3, 2, 2}
// segments = 2, 2, 3

#include <bits/stdc++.h>
using namespace std;

int maxSegments(int n, int x, int y, int z){
    if(n < 0){
        return INT_MIN;
    }
    if(n == 0) return 0;

    int first = maxSegments(n - x, x, y, z);
    int second = maxSegments(n - y, x, y, z);
    int third = maxSegments(n - z, x, y, z);

    return max(first, max(second, third)) + 1;
}

int main(){
    int n, x, y, z;
    cin>>n;
    cin>>x>>y>>z;
    cout<<maxSegments(n, x, y, z);
    return 0;
}