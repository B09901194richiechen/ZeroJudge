#include <stdio.h>

bool check(char c);

int main(void) {
// big: 65~90; small: 97~122

    int k;
    char c;
    bool big, big_prev;   // 1 => big; 0 => small
    bool satisfy_k_prev; // 1 => the number of the previous consecutive letters is k
    int ctr = 0;
    int group_now = 0, group_max = 0;


    scanf("%d/n", &k);
    c = getchar();
    big_prev = big = check(c);
    ctr++;

    while(c = getchar()) {
        big = check(c);
        if (big == big_prev) ctr++;   // have the same capital as the previous one
        else {
            
        }
    }
    
    return 0;
}

bool check(char c) {
    return (c <= 90 ? 1 : 0);
}