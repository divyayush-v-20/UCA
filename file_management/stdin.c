#include <stdio.h>

int main(){
	FILE* input = fopen("input.txt", "r");
	char buffer[100];
	while(fgets(buffer, sizeof(buffer), input)){
		printf("Input -> %s\n", buffer);
	}
	return 0;
}
