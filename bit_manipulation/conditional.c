#include <stdio.h>
int main(){
	int a;
	scanf("%d", &a);
	int b = 1, c = 2;
	// implement a?b:c, using -> !, <<, >>, ^, &, |, ~
	int res = ((!!a) & 1)*b + ((!a) & 1)*c;
	printf("%d", res);
	return 0;
}

