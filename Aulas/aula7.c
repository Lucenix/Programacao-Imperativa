//
// Created by andre on 11/03/2021.
//
#include "stdio.h"
int comprimento (char s[]) {
    int i=0;
    for (; *s != '\0'; s++, i++);
    return i;
}

char *concat (char *s1, char *s2) {
    int c1 = comprimento(s1),
        c2 = comprimento(s2),
        i;
    for (i=0;i<=c2; i++) {
        s1[c1+i] = s2[i];
    }
    s1[c1+i] = '\0';
    return s1;
}

int main() {
    char s[20] = "ola mundo cruel",
         sa[10] = ", sqn lmao",
         *c;
    c = concat(s, sa);
    for (int i = 0; i< comprimento(c); i++) {
        putchar(c[i]);
    }
    return 0;
}

