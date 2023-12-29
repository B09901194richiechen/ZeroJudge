#include <stdio.h>
#include <stdlib.h>

typedef struct sData {
	long long int digit;
	int num;
	struct sData *next;
} Data;

long long int read(void);
Data *create(long long int x);

int main(void)
{
	int n, max, i, repeat = 0;
	long long int x;
	Data *head, *p;

	while (1) {
		scanf("%d", &n);
		if (n == 0)
			break;
		max = 0;
		x = read();
		head = create(x);
		for (i = 1; i < n; i++) {
			x = read();
			for (p = head; p->next != NULL && x != p->digit; p = p->next);
			if (x == p->digit)	(p->num)++;
			else 				p->next = create(x);
		}
		for (p = head; p != NULL; p = p->next)
			if (p->num > max) {
				max = p->num;
				repeat = 1;
			} else if (p->num == max)
				repeat++;
		printf("%d\n", repeat * max);
	}	
	return 0;
}

Data *create(long long int x)
{
	Data *m;

	m = (Data *)malloc(sizeof(Data));
	m->digit = x;
	m->num = 1;
	m->next = NULL;
	return m;
}

long long int read(void)
{
	int a[5];
	int j, k, temp;
	long long int x;

	scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]);     // read numbers
	for (j = 5; j > 0; j--)                                         // sort
		for (k = 0; k < j - 1; k++)
			if (a[k] > a[k + 1]) {
				temp = a[k];
				a[k] = a[k + 1];
				a[k + 1] = temp;
			}
	x = (a[0] * 1e12) + (a[1] * 1e9) + (a[2] * 1e6) + (a[3] * 1000) + a[4];
	return x;
}	
