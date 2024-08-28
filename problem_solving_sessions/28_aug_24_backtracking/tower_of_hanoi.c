#include <stdio.h>

void solve_tower_of_hanoi(int n, char src, char hlp, char dest){
	if(n == 1) {
		printf("move disk %d from %c to %c\n", n, src, dest);
		return;
	}
	solve_tower_of_hanoi(n - 1, src, dest, hlp);
	printf("move disk %d from %c to %c\n", n, src, dest);
	solve_tower_of_hanoi(n - 1, hlp, src, dest);
}

int main(){
	int n;
	scanf("%d", &n);
	
	char source = 'A';
	char helper = 'B';
	char destination = 'C';

	solve_tower_of_hanoi(n, source, helper, destination);

	return 0;
}
