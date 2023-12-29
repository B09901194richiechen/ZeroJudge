#include <stdio.h>
#include <string.h>
#include <math.h>
int main (void) {
	char a[1000];
	int x, i;
	
	while(1) {
		scanf ("%s", a);
		if (a[0] == '#')
			break;
		x = 0;
		for (i = 0; i < strlen(a); i++) {
			if (a[i] == 'M')
				x += 1000;
			else if (a[i] == 'D')
				x += 500;
			else if (a[i] == 'C' && (a[i + 1] == 'D' || a[i + 1] == 'M'))
				x -= 100;
			else if (a[i] == 'C')
				x += 100;
			else if (a[i] == 'L')
				x += 50;
			else if (a[i] == 'X') {
				if (a[i + 1] == 'L' || a[i + 1] == 'C')
					x -= 10;
				else
					x += 10;		
			}
			else if (a[i] == 'V')
				x += 5;
			else {
				if (a[i + 1] == 'V' || a[i + 1] == 'X')
					x -= 1;
				else
					x += 1;	
			}
		}
		scanf("%s", a);
		for (i = 0; i < strlen(a); i++) {
			if (a[i] == 'M')
				x -= 1000;
			else if (a[i] == 'D')
				x -= 500;
			else if (a[i] == 'C' && (a[i + 1] == 'D' || a[i + 1] == 'M'))
				x += 100;
			else if (a[i] == 'C')
				x -= 100;
			else if (a[i] == 'L')
				x -= 50;
			else if (a[i] == 'X') {
				if (a[i + 1] == 'L' || a[i + 1] == 'C')
					x += 10;
				else
					x -= 10;		
			}
			else if (a[i] == 'V')
				x -= 5;
			else {
				if (a[i + 1] == 'V' || a[i + 1] == 'X')
					x += 1;
				else
					x -= 1;	
			}
		}
		x = abs(x);
		if (x == 0)	printf("ZERO");
		else {
		for (i = 0; i < x / 1000; i++)	printf("M");
		x %= 1000;
		switch (x / 100) {
			case 1: printf("C"); 	break;
			case 2: printf("CC"); 	break;
			case 3: printf("CCC"); 	break;
			case 4: printf("CD"); 	break;
			case 5: printf("D"); 	break;
			case 6: printf("DC"); 	break;
			case 7: printf("DCC"); 	break;
			case 8: printf("DCCC"); break;
			case 9: printf("CM"); 	break;
		}
		x %= 100;
		switch (x / 10) {
			case 1: printf("X");	break;
			case 2: printf("XX"); 	break;
			case 3: printf("XXX");	break;
			case 4: printf("XL"); 	break;
			case 5: printf("L"); 	break;
			case 6: printf("LX"); 	break;
			case 7: printf("LXX"); 	break;
			case 8: printf("LXXX"); break;
			case 9: printf("XC"); 	break;
		}
		x %= 10;
		switch (x) {
			case 1: printf("I"); 	break;
			case 2: printf("II"); 	break;
			case 3: printf("III"); 	break;
			case 4: printf("IV"); 	break;
			case 5: printf("V"); 	break;
			case 6: printf("VI"); 	break;
			case 7: printf("VII"); 	break;
			case 8: printf("VIII"); break;
			case 9: printf("IX");  	break;
		}
	}
		printf("\n");
	}
	return 0;
}
