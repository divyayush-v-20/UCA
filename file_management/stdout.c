#include <stdio.h>

int main(){
	int integer = 24;
	float pi = 3.14;

	FILE* output = fopen("output.txt", "w");

	fprintf(output, "%d\n", integer);
	fprintf(output, "%.2f\n", pi);

	fclose(output);

	char buffer[50];

	output = fopen("output.txt", "r");
	
	while(fgets(buffer, sizeof(buffer), output)){
		printf("%s", buffer);
	}

	return 0;
}
