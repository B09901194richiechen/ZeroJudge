#include <stdio.h>

void change (int y);

int main (void) {
	int x;
	
	while (scanf("%d", &x) != EOF) {
		change (x);
		printf("\n");
	}
	return 0;
}

void change (int y) {
	if (y / 2 == 0) {
		printf("%d", y);		
		return ;
	}
	else
		change	(y / 2);
	printf ("%d", y % 2);	
}
