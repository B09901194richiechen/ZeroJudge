#include <stdio.h>

int main(void)
{
	int n, w;
	int a[200000][3];
	int time[200000] = {0};
	int i, j, max = 0, own = 0, flag = 0;
	
	scanf("%d %d", &n, &w);
	for (i = 0; i < n; i++) {
		scanf("%d %d %d", &a[i][0], &a[i][1], &a[i][2]);
		for (j = a[i][0] + 1; j <= a[i][1]; j++)
			time[j] += a[i][2];
		if (a[i][1] > max)
			max = a[i][1];	
	}
	for (i = 0; i < max && time[i] <= w; i++);
	if (i < max)	printf("No\n");
	else			printf("Yes\n");
	return 0;
}
