#include <stdio.h>
#include <assert.h>
#include <string.h>

void one() {
    int max=0,r;
    do{
        assert(scanf("%d", &r) ==1);
        if (max < r)
            max = r;
    }while(r!=0);
    printf("%d",max);
}

void two() {
    int r, soma = 0,count = 0;
    do {
        assert(scanf("%d", &r) ==1);
        soma += r;
        count++;
    }while(r!=0);
    printf("%f", (double) soma / (double) count);
}

void three() {
    int r, max, max2;
    assert(scanf("%d", &r) == 1);
    max = r;
    while (r!=0) {
        assert(scanf("%d", &r) == 1);
        if (r >= max) {
            max2 = max;
            max = r;
        } else if (r > max2) {
            max2 = r;
        }
    }
    printf("%d", max2);
}

int bitsUm (unsigned int n) {
    int r = 0;
    while (n!=0) {
        if (n%2 == 1)
            r++;
        n/=2;
    }
    return r;
}

int trailingZ (unsigned int n) {
    int r = 0;
    unsigned int a;
    while (n!=0 && a!=1) {
        a = n%2;
        if (a == 0)
            r++;
        n/=2;
    }
    return r;
}

int qDig (unsigned int n) {
    int i = 1;
    while (n!=0) {
        n/=10;
        i++;
    }
    return i;
}

char *strcatt (char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i]!='\0'; i++);
    for (j = 0; s2[j]!='\0'; j++) {
        s1[i+j] = s2[j];
    }
    s1[i+j] = '\0';
    return s1;
}

char *strcpyy (char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

int strcmpp (char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}

char *strstrr (char s1[], char s2[]) {
    int i = 0, j, k;
    char *r = NULL;

    do {
        for (j = 0, k = i; s1[k] != '\0' && s1[k] == s2[j]; j++, k++);
        if (s2[j] == '\0')
            r = s1 + i;
        i++;
    }while(s1[i] != '\0' && r == NULL);

    return r;
}

void strrevv (char s[]) {
    int i,j;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void strnoV(char s[]) {
    int i, w;
    for (i=0, w=0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'e')
            s[w++] = s[i];
    }
}

void truncW (char t[], int n) {
    char delim = ' ';
    int i, conta = 0, w;
    for (i = 0, w = 0; t[i] != '\0'; i++) {
        if (t[i] == delim){
            t[w++] = delim;
            conta = 0;
        } else if (conta < n) {
            t[w++] = t[i];
            conta++;
        }
    }
    t[w] = '\0';
}

char charMaisFreq (char s[]) {
    char r;
    if (!s) r = 0;
    else {
        char aux[strlen(s)];
        strcpy(aux, s);
        int i, w = 1, j;
        for (i = 1; s[i] != '\0'; i++) {
            for (j = 0; j<w && s[i] != aux[j]; j++);
            if (j == w) aux[w++] = s[i];
        }
        aux[w] = '\0';
        int max = 0, conta;
        for (i = 0; aux[i] != '\0'; i++) {
            conta = 0;
            for (j = 0; s[j] != '\0'; j++)
                if (s[j] == aux[i]) conta++;
            if (conta > max) {
                max = conta;
                r = aux[i];
            }
        }
    }
    return r;
}

int iguaisConsecutivos (char s[]) {
    int i,j, r = 0, conta;
    for (i = 0; s[i] != '\0'; i++){
        conta = 0;
        for (j = i; s[j] != '\0' && s[i] == s[j]; j++) {
            conta++;
        }
        if (r<conta) r = conta;
    }
    return r;
}

int compPrefixoSemRep (char s[]) {
    int i, j, r = 0;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; s[j] != s[i]; j++);
        if (j!=i) return r;
        else r++;
    }
    return r;
}

int difConsecutivos (char s[]) {
    int r=0, i, j;
    for (i = 0; s[i] != '\0'; i++) {
        j = compPrefixoSemRep(s + i);
        if (r<j) r = j;
    }
    return r;
}

int maiorPrefixo (char s1 [], char s2 []) {
    int i,r=0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    if (s1[i]!=s2[i]) r = i;
    else r = i+1;
    return r;
}

int maiorSufixo (char s1[], char s2[]) {
    int i, j, r=0;

    for(i=0; s1[i]!='\0'; i++); i--; // strlen()
    for(j=0; s2[j]!='\0'; j++); j--; // strlen()

    while (s1[i] == s2[j] && (i>=0 || j>=0)) {
        i--;
        j--;
        r++;
    }

    return r;
}

int sufPref (char s1[], char s2[]) {
    int i,j;
    for(i=0, j=0; s1[i]!='\0'; i++) {
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }
    return j;
}

int elimRepOrd (int v[], int n) {
    int r, w;
    for (r = 0, w = -1; r < n; r++) {
        if (v[w] != v[r]) {
            v[++w] = v[r];
        }
    }
    if (n==0) w--;
    return w+1;
}

int main() {
    return 0;
}
