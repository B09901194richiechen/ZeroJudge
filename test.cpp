#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h> 

void delay(int seconds);
void print(void);
void putfood(void);

int w = 25, s = 25, len = 3; // width, speed, length
int foodx, foody;            // x, y position of food
	
struct snake {
	int p[100][100]; // position
};

int main(void)
{
	int dead = 0;
	
	while (!dead) {
		print();
		putfood();
		delay(1); 
		system("cls");
	};
	
	
	return 0;
}

void delay(int seconds)
{
	int milli_seconds = 1000 * seconds; 
    clock_t start_time = clock();    // Storing start time 
    while (clock() < start_time + milli_seconds);  // looping till required time is not achieved 
	return ;
}

void print(void){
	int i, j;
	
	for (j = 0; j < w; j++)	printf("―");
	for (i = 1; i < w - 1; i++) {
		printf("―");
		for (j = 1; j < w - 1; j++)
			if(i == foody && j == foodx)
				printf("*");
			else printf("  ");		
		printf("―\n");
	}
	for (j = 0; j < w; j++)	printf("―");
	return ;
}

void putfood(void) {
	int r;
	
	srand(time(NULL));
	r = rand();
	foodx = (r % (w * w)) / w + 1;
	foody = (r % (w * w)) % w + 1;
	return ;	
}
