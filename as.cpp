#include <stdio.h>

int main (void) {
	int n, a, i, big_neg = -1000, x = 1;
	int neg_num = 1;   // 1 means even number negative; -1 means odd number negative
	long long int sum = 1;
	
	while (scanf("%d", &n) != EOF) {
		for (i = 0, sum = 1, big_neg = -10000, neg_num = 1; i < n; i++) {
			scanf("%d", &a);
			sum *= a;
			if (a < 0) {
				neg_num = -neg_num;
				if (a > big_neg)
					big_neg = a;
			}
		}
		if (neg_num == 1)	printf("Case #%d: The maximum product is %lld.\n\n", x, sum);
		else 				printf("Case #%d: The maximum product is %lld.\n\n", x, sum / big_neg);
		x++;
	}
	return 0;
}
