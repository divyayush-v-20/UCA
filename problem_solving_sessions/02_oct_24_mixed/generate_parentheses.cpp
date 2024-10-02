#include <bits/stdc++.h>
using namespace std;

void solve(int open, int close, int total, string tmp){
    if(open == total && close == open){
        cout<<tmp<<endl;
        return;
    }
    if(open < total) solve(open + 1, close, total, tmp + '(');
    if(close < open) solve(open, close + 1, total, tmp + ')');
}
int main(){
    int total = 3;
    solve(0, 0, total, "");
    return 0;
}