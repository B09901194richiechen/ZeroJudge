#include <stdio.h>
#define INTMAX 0x7FFFFFFFFFFFFFFF

long long int find_gcd (long long int, long long int);
long long int find_multi (long long int, long long int, long long int);

int main (void) {
	long long int a, b, x1, y1, gcd, sum;

	scanf("%lld %lld %lld %lld", &a, &b, &x1, &y1);
	if (x1 == 0 && y1 == 0 && a <= 0 && b >= 0) printf("1\n");
	else if (x1 == 0 && y1 == 0)				printf("0\n");
	else {
		if (x1 < 0) x1 = -x1;
		if (y1 < 0) y1 = -y1;
		if (x1 == 0) x1 = y1;
		if (y1 == 0) y1 = x1;
		gcd = find_gcd (x1, y1);
		sum = find_multi (a, b, x1) + find_multi (a, b, y1) - find_multi (a, b, gcd);
		printf("%lld\n", sum);
	}
	return 0;
}

long long int find_gcd (long long int x1, long long y1) {
	long long int temp, x = x1, y = y1;
	
	if (x < y) {
		temp = y;
		y = x;
		x = temp;
	}
	while (y) {
		temp = y;
		y = x % y;
		x = temp;
	}
	return ((x1 / x) > (INTMAX / y1)) ?  INTMAX : x1 / x * y1;
}

long long int find_multi (long long int a, long long int b, long long int ftr) {
	long long int sum;
	
	if (a <= 0 && b >= 0)
		sum = b / ftr - a / ftr + 1;
	else if (b < 0)
		sum = (b - 1) / ftr - a / ftr;
	else
		sum = b / ftr - (a - 1) / ftr;
	return sum;	
}

