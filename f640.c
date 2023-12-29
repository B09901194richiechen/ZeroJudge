#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f(void);
int g1(void);
int g2(int);
int h1(void);
int h2(int);
int h3(int, int);

int main (void) {
    char s[50];
    int final;

    scanf("%s", s);
    if (!strcmp(s, "f"))      {final = f();}
    else if (!strcmp(s, "g")) final = g1();
    else if (!strcmp(s, "h")) final = h1();
    printf("%d", final);
    return 0;
}

int f(void) {
    char s[50];
    int tmp;

    scanf("%s", s);
    if (!strcmp(s, "f"))       tmp = f();
    else if (!strcmp(s, "g"))  tmp = g1();
    else if (!strcmp(s, "h"))  tmp = h1();
    else                return 2 * atoi(s) - 3;
    return 2 * tmp - 3;
}

int g1(void) {
    char s[50];
    int tmp;

    scanf("%s", s);
    if (!strcmp(s, "f"))      { tmp = f();  tmp = g2(tmp); }
    else if (!strcmp(s, "g")) { tmp = g1(); tmp = g2(tmp); }
    else if (!strcmp(s, "h")) { tmp = h1(); tmp = g2(tmp); }
    else                 tmp = g2(atoi(s));    // read x
    return tmp;
}

int g2(int x) {                      // g that already have x
    char s[50];
    int tmp;

    scanf("%s", s);
    if (!strcmp(s, "f")) tmp = f();
    else if (!strcmp(s, "g")) tmp = g1();
    else if (!strcmp(s, "h")) tmp = h1();
    else               return 2 * x + atoi(s) - 7;
    return 2 * x + tmp -7;
}

int h1(void) {
    char s[50];
    int tmp;
    
    scanf("%s", s);
    
    if (!strcmp(s, "f"))      { tmp = f();  tmp = h2(tmp); }
    else if (!strcmp(s, "g")) { tmp = g1(); tmp = h2(tmp); }
    else if (!strcmp(s, "h")) { tmp = h1(); tmp = h2(tmp); }
    else                 tmp = h2(atoi(s));    // read x
    return tmp;
}


int h2(int x) {
    char s[50];
    int tmp;
    
    scanf("%s", s);
    if (!strcmp(s, "f"))      { tmp = f();  tmp = h3(x, tmp); }
    else if (!strcmp(s, "g")) { tmp = g1(); tmp = h3(x, tmp); }
    else if (!strcmp(s, "h")) { tmp = h1(); tmp = h3(x, tmp); }
    else                 tmp = h3(x, atoi(s));    // read x
    return tmp;
}


int h3(int x, int y) {
    char s[50];
    int tmp;
    int n;

    scanf("%s", s);
    if (!strcmp(s, "f")) tmp = f();
    else if (!strcmp(s, "g")) tmp = g1();
    else if (!strcmp(s, "h")) tmp = h1();
    else return 3 * x - 2 * y + atoi(s);
    return 3 * x - 2 * y + tmp;
}