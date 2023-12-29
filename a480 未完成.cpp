#include <stdio.h>
int main (void) {
	long int x1, y1, x2, y2, x, y;
	long int r1 = 0, r2 = 0;
	long int n;
	long int i, a, b;
	long int c1, c2, d1, d2;
	
	scanf("%ld %ld", &x1, &y1);
	scanf("%ld %ld", &x2, &y2); 
	scanf("%ld", &n);
	for (i = 0; i < n; i++) {
		scanf("%ld %ld", &x, &y);
		a = (x - x1) * (x - x1) + (y - y1) * (y - y1);
		b = (x - x2) * (x - x2) + (y - y2) * (y - y2);
		if ((a < b) && (r1 < a) && (r2 < a)) {
			c1 = x;
			d1 = y;
			r1 = a;
		}
		else if ((a > b) && (r2 < b) && (r1 < a)) {
			c2 = x;
			d2 = y;
			r2 = b;
		}
		else if ((a == b) && (r1 < b) && (r2 < b)) {
			if (r1 < r2) r2 = a;
			else		 r1 = a;
		}
	}
	if ((c1 - x1) * (c1 - x1) + (d1 - y1) * (d1 - y1) < r2)	r1 = 0;
	if ((c2 - x2) * (c2 - x2) + (d2 - y2) * (d2 - y2) < r1)	r2 = 0;

	printf("%ld", r1 + r2);
	return 0;
}
