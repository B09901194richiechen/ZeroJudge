#include <stdio.h>
int main (void) {
	long long int x;
	int i = 1;
	long long int sum = 0;
	
	scanf("%lld", &x);
	for ( ; x != 0; i = i * 9) {
		sum += (x % 10) * i;
		x = x / 10;
	}
	printf("%lld", sum);
	return 0;
}

// tip: §ä¤½¦¡ 
