#include <stdio.h>
int main(){
	int a = 5;

	int* p1 = &a;
	int** p2 = &p1;

	printf("%d\n", *p1);
	printf("%d", **p2);

	return 0;
}
