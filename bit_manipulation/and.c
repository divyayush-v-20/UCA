#include <stdio.h>
int and_op(int a, int b){
	return ~(~a | ~b);
}
int main(){
	//implement & using ~ and |
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", and_op(a, b));
	return 0;
}
