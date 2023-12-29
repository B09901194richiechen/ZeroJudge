#include <stdio.h>
#define R 0    // rock
#define S 2    // seissor
#define P 5    // paper

int comparison(int b, int s);  // brother and sister

int main (void) {
    int F, N;
    int y[10];
    int i;
    int flag = 0;     // 0: draw; 1: win; 2: lose
    int time = 0;
    scanf("%d", &F);
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%d", &y[i]);
    
    // first round
    flag = comparison(F, y[0]);
    time++;
    printf("%d ", F);
    
    // second round
    if (!flag && N > 1) {
        time++;
        flag = comparison(y[0], y[1]);
        printf("%d ", y[0]);
    }

    for (i = 2; i < N && !flag; i++) {
        time++;
        if (y[i - 1] == y[i - 2]) {
            if (y[i - 1] == R)      F = P;
            else if (y[i - 1] == S) F = R;
            else                    F = S;
        }
        else                        F = y[i - 1];
        printf("%d ", F);
        flag = comparison(F, y[i]);
    }
    if (flag == 0)      printf(": Drew at round %d", time);
    else if (flag == 1) printf(": Won at round %d", time);
    else                printf(": Lost at round %d", time);
    return 0;
}





int comparison(int b, int s) {
    int flag = 0;
    if (b == R) {
        if (s == S)      flag = 1;
        else if (s == P) flag = 2;
        else             flag = 0;
    }
    else if (b == S) {
        if (s == R)      flag = 2;
        else if (s == P) flag = 1;
        else             flag = 0;
    }
    else {
        if (s == R)      flag = 1;
        else if (s == S) flag = 2;
        else             flag = 0;
    }
    return flag;
}