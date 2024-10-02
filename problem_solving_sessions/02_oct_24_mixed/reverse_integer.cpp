#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    bool isNegative = (x > 0) ? 0 : 1;
    x = (isNegative) ? -x : x;
    int res = 0;
    while(x){
        if(res > INT_MAX / 10 || res < INT_MIN / 10) return 0;
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return (isNegative) ? -res : res;
}
int main(){
    assert(reverse(1534236469) == 0);
    assert(reverse(-121) == -121);
    assert(reverse(INT_MAX) == 0);
    assert(reverse(31748) == 84713);
    return 0;
}
