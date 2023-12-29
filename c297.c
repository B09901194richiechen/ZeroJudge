#include <stdio.h> 
#include <string.h>

int main (void) {
    int a;
    char s[2];
    int data[9][5] = {0};
    int b;
    int i, j, k;
    int score = 0;
    int out = 0, totalout = 0;
    int position[4] = {0};

    for (i = 0; i < 9; i++) {        // read data
        scanf ("%d", &a);
       // printf("here");
        for (j = 0; j < a; j++) {
            scanf("%s", s);
            if (!strcmp(s, "1B"))      data[i][j] = 1;
            else if (!strcmp(s, "2B")) data[i][j] = 2;
            else if (!strcmp(s, "3B")) data[i][j] = 3;
            else if (!strcmp(s, "HR")) data[i][j] = 4;
            else                       data[i][j] = 5;
        }
    }
    scanf("%d", &b);

    for (i = 0; i < 5 && totalout < b; i++) {
        for (j = 0; j < 9 && totalout < b; j++) {
            position[0] = 1;              // home pedal has batter
            if (data[j][i] == 5) {
                out++;
                totalout++;
                if (out == 3) {
                    position[0] = position[1] = position[2] = position[3] = out = 0;
                }
            }
            else {
                for (k = 3; k > 3 - data[j][i]; k--) {
                    if (position[k] == 1) {
                        score++;
                        position[k] = 0;
                    }
                }    
                for ( ; k >= 0; k--) {
                    if (position[k]) {
                        position[k] = 0;
                        position[k + data[j][i]] = 1; 
                    }
                }
            }
        }
    }
    printf("%d", score);
    return 0;
}