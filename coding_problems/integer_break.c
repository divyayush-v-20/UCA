//was asked in round 2 of UCA qualification
//given an integer n, return the maximum product of k numbers(k >= 2), which sum up to n

#include <stdio.h>
int integerBreak(int n){
    if(n < 4) return n - 1;
    int prod = 1;
    while(n > 4){
        n -= 3;
        prod *= 3;
    }
    return n * prod;
}
int main(){
    int n;
    scanf("%d", &n);
    int ans = integerBreak(n);
    printf("%d", ans);
    return 0;
}