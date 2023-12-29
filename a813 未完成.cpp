#include <stdio.h>
int main (void) {
	long int n;
	long int h[100000];
	long int i, j = 1, k, x;
	long long int sum = 0;
	
	scanf("%ld\n", &n);
	scanf("%ld", &h[0]);
	for (i = 1; i < n; i++) {
		scanf("%ld", &x);
		if (h[j - 1] != x) {
			for ( ; j > 0 && ++sum && h[j - 1] <= x; j--);
			h[j++] = x;
		} else {
			for (k = j - 1; h[k] == x && k >= 0; k--, sum++);
			if (h[k] != x) sum++;
			h[j++] = x;
		}
	}	
	printf("%lld", sum * 2);
	return 0;
}
