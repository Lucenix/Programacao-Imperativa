#include <stdio.h>

void triangulo (int x) {

    int blank = x-1;

    for (int i = 1; i<=x; i++) {
        int nCard = 2*i-1;
        for (int j = 0; j<blank; j++) {
            putchar(' ');
        }
        for (int k = 0; k<nCard;k++){
            putchar('#');
        }
        blank--;
        putchar('\n');
    }
}

int main() {
    triangulo(5);
    return 0;
}