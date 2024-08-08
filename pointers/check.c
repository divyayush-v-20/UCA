#include <stdio.h>

int main(void) {
	unsigned int a = 623534;
	
	int *b = &a;
	char *c = &a;
	
	printf("%d\n", *b);
	printf("%d\n", *c);
	

}
