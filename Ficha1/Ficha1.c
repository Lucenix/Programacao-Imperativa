#include <stdio.h>
void triangulo (int n);

void quadroDim(int d);

main () 
{
    /*1.1
    int x, y;
    x = 3; y = x+1;
    x = x*y; y = x + y;
    printf("%d %d\n", x, y);
    R. 12 16*/

    /*1.2
    int x, y;
    x = 0;
    printf("%d %d\n", x, y);
    R. 0 16*/

    /*1.3
    65, 48, 32, 97
    char a, b, c;
    a = 'A'; b = ' '; c = '0';
    printf ("%c %d\n", a, a); - A 65
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c); - B 66 2 50
    c = a + b; 
    printf ("%c %d\n", c, c); b 98
    */
    
    /*1.4
    int x,y;
    x = 200; y = 100;
    x = x+y; y = x-y; x = x-y;
    printf("%d %d\n", x, y); 100 200 
    */

    /*2.1a
    int x, y;
    x = 3; y = 5;
    if (x>y)
        y=6;
    printf("%d %d\n", x, y); 3 5
    */

    /*2.1b
    int x, y;
    x = y = 0;
    if (x != 11) {
        x = x+1; y += x;
    }
    printf("%d %d\n", x, y); 1 1*/

    /*2.1c
    int i;
    for (i=0; (i<20) ; i++)
        if (i%2 == 0) putchar ('_');
        else putchar ('#');
        _#_#_#_#_#_#_#_#_#_#
    */

    /*2.1d
    void f (int n) {
       while (n>0) {
           if (n%2 == 0) putchar ('0');
           else putchar ('1');
           n = n/2;
        }
        putchar ('\n');
    }
    int main () {
        int i;
        for (i=0; (i<16); i++)
            f(i);
        return 0;
    }
    "
    1
    01
    11
    001
    101
    011
    111
    0001
    1001
    0101
    1101
    0011
    1011
    0111
    1111"

    */

    quadroDim(5);
    return 0;
}

void quatroUm (int x) {
    for (int i = 0; i<x; i++) {
        for (int j = 0; j<x; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}

void quatroDois (int x) {
    for (int i = 0; i<x; i++) {
        for (int j = 0; j<x; j++) {
            if (((i+j)%2) == 0)
                putchar('#');
            else 
                putchar('_');
        }
        
        putchar('\n');
    }
}

int checkCirculo(int i, int j, int r);

void quatroQuatro (int r) {
    int conta=0;
    for (int i = 0; i < 2*r+1; i++) {
        for (int j = 0; j < 2*r+1; j++) {
            if (checkCirculo(i, j, r))
                if (j < r) {
                    putchar('(');
                    conta++;
                } else if (j == r) {
                    putchar('|');
                    conta++; 
                } else {
                    putchar(')');
                    conta++; }
            else
                putchar(' ');
        }
        putchar('\n');
    }
    
        printf("%d", conta);
        putchar('\n');
}

void quadroDim (int d) {
    for (int i = 1; i<=d; i++) {
        for (int j = 1; j<=d; j++) {
            if (j == 1 || i == 1 || j == d || i == d)
                putchar('#');
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

int checkCirculo (int i, int j, int r) {
    if ((i-r)*(i-r) + (j-r)*(j-r) <= r*r)
        return 1;
    else
        return 0;
}