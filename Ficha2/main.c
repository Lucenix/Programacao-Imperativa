#include <stdio.h>
#include "math.h"

float multInt1(int n, float m) {
    float r = 0;
    int conta = 0;
    for (int i = 0; i<n; i++){
        r += m;
        conta++;
    }
    printf("%d\n", conta);
    return r;
}

float multInt2(int n, float m, int *count) {
    *count = 0;
    float r = 0;
    while (n) {
        if (n%2)
            r += m;
        n/=2;
        m*=2;
        (*count)++;
    }
    return r;
}

void mdcTest (int a,int b,int *r) {
    for (int i = b; i>=1 && *r == 1; i--)
        if (a%i == 0 && b%i == 0)
            *r = i;
}

int mdc1 (int a, int b) {
    int r = 1;
    if (a>b)
        mdcTest(a,b,&r);
    else
        mdcTest(b,a,&r);
    return r;
}

int mdc2 (int a, int b) {
    while (a && b) {
        if (a > b)
            a -= b;
        else
            b -= a;
        }
    return (a+b);
}

int mdc3(int a, int b) {
    if(!(a*b))
        return a+b;

    while(a!=b) {
        if (a > b) {
            a%=b;
        }else{
            b%=a;
        }
    }
    return a;
}

int fib2 (int n) {
    if (!n)
        return 0;
    int n1 = 1, n2 = 1;
    while (n>2) {
        int aux = n1;
        n1 += n2;
        n2 = aux;
        n--;
    }
    return n1;
}

int fib1 (int n){
    if (n<2)
        return 1;
    else{
        return (fib1(n-1)+fib1(n-2));
    }
}

int main() {
    //printf("%f\n", multInt1(81,423));
    //printf("%f\n", multInt2(81, 423,&c));
    //printf("%d\n", mdc1(12,9));
    //printf("%d\n", mdc2(1000,992));
    //printf("%d\n", mdc2(1000,992));
    //printf("%d\n", fib1(2));
    //printf("%d\n", fib1(3));
    //printf("%d\n", fib1(10));
    //printf("%d\n", c);
    return 0;
}
