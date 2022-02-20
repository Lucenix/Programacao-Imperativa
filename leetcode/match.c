#include "stdio.h"

int isMatch(char * s, char * p){
    int adv/*ance p*/ = 1; 
    if (*p == 0) return *s == 0; //se p for vazio então s também vai ter de ser
    if (*p && *(p+1) && *(p+1) == '*') { if (isMatch(s, p + 2)) return 1; adv = 0; } //ver se o '*' é útil ou não, se for, adv = 0
    if (*s && *p == '.' || *s == *p) return isMatch(s + 1, p + adv); //se forem iguais (ou for .), vemos o seguinte (ou talvez não :D)
    return 0;
}

int main () {
    char *s = "aa";
    char *p = "a*a";
    printf("%d", isMatch(s, p));
}