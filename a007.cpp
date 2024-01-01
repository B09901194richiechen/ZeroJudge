#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

// use Miller–Rabin primality test, also helped by sympy.isprime() function
// reference: https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test
// reference: https://github.com/sympy/sympy/blob/d2be7bacd2604e98a642f74028e8f0d7d6084f78/sympy/ntheory/primetest.py#L499-L674

bool isprime(int x);

int main (void) {
	int x;
	bool prime;

	while (scanf("%d", &x) != EOF) {
		prime = isprime(x);
		if (prime) printf("質數\n");
		else       printf("非質數\n");
	}
	return 0;
}

bool isprime(int x) {
	if (x == 2 || x == 3 || x == 5) return 1;
	if ((x % 2) == 0 || (x % 3) == 0 || (x % 5) == 0) return 0;
	if (x < 49) return 1;
	if ((x %  7) == 0) return 0;
	if ((x % 11) == 0) return 0;
	if ((x % 13) == 0) return 0;
	if ((x % 17) == 0) return 0;
	if ((x % 19) == 0) return 0;
	if ((x % 23) == 0) return 0;
	if ((x % 29) == 0) return 0;
	if ((x % 31) == 0) return 0;
	if ((x % 37) == 0) return 0;
	if ((x % 41) == 0) return 0;
	if ((x % 43) == 0) return 0;
	if ((x % 47) == 0) return 0;
	if (x < 2809) return 1;
	if ((x < 31417) && (x != 7957 && x != 8321 && x != 13747 && x != 18721 && x != 19951 && x != 23377))
		return
}
