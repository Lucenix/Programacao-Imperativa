#include <stdio.h>

void triangulo (int x) {
    for (int i = 1; i<x; i++) {
        for (int j = 1; j <= i; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    for (int i = x-1; i > 0; i--) {
        for (int j = i; j>0; j--) {
            putchar('#');
        }
        putchar('\n');
    }
}