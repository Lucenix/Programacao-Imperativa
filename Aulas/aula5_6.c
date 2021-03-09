//
// Created by andre on 09/03/2021.
//

#include <stdio.h>

int sum(int pInt[10], int n);

int main() {
    int a[10] = {1,2,3,4,5,6,7,8,9,0};

    int s;

    int *b;
    long int *c;

    b = a; //a operação inversa não é possível
    b = a + 3; //aritmética de endereços -> salta 3 para a frente

    c = a;
    c = a + 3;

    s = sum (b,10);

    printf("%d\n", *a);
    printf("%d\n", *b);
    printf("%d\n", *c);
    printf("%d",s);

    return 0;
}

int sum(int pInt[10], int n) {
    int i,x;
    for(i=x=0; i<n; i++) {
        x += pInt[i];
    }
    return x;
}

