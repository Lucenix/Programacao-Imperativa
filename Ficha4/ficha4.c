//
// Created by andre on 22/03/2021.
//
#include <stdio.h>
#include <string.h>
#define NUMERO_VOGAIS 10

//1.1
int contaVogais(char *s) {
    int conta = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'
            || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            conta++;
    //char casos[NUMERO_VOGAIS] = "AEIOUaeiou";
    //for (int i = 0; s[i]!='\0';i++)
    //    for (int j = 0; j<NUMERO_VOGAIS; j++)
    //        if (s[i] == casos[j]) {
    //            conta++;
    //            j = NUMERO_VOGAIS;
    //        }
    return conta;
}

//1.2
int retiraVogaisRep (char *s) {
    char casos[NUMERO_VOGAIS] = "AEIOUaeiou";
    int conta = 0;
    for (int i = 0; s[i]!='\0'; i++) {
        for (int j = 0; j<NUMERO_VOGAIS && s[i+1] != '\0'; j++) {
            if (s[i] == casos[j] && s[i+j]==s[i]) {
                for (int k = i+1; s[k]!='\0'; k++)
                    s[k] = s[k+1];
                conta++;
                j = NUMERO_VOGAIS;
            }
        }
    }
    return conta;
}

//1.3
int duplicaVogais (char *s) {
    int conta = 0;
    char casos[NUMERO_VOGAIS] = "AEIOUaeiou";
    for (int i = 0; s[i]!='\0';i++){
        for (int j = 0; j<NUMERO_VOGAIS; j++) {
            if (s[i] == casos[j]) {
                for (int k = strlen(s); k>=i ; k--)
                    s[k+1] = s[k];
                j=NUMERO_VOGAIS;
                i++;
                conta++;
            }
        }
    }
    return conta;
}

//2.1
int ordenado (int v[], int N) {
    int r = 1;
    for(int i = 0; i<N-1; i++)
        if (v[i]>v[i+1]) r = 0;
    return r;
}

//2.2
void merge (int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0;
    while(i<na&&j<nb) {
        if (a[i] < b[j]) {
            r[i+j] = a[i];
            i++;
        } else {
            r[i+j] = b[j];
            j++;
        }
    }
    if (j==nb) {
        while(i<na) {
            r[i+j] = a[i];
            i++;
        }
    } else {
        while(j<nb) {
            r[i+j] = b[j];
            j++;
        }
    }
}

//2.3
int partition(int v[], int N, int x) {
    int sp=0;
    for (int i = 0; i<N; i++) {
        if (v[i]<=x)
            sp++;
    }
    for (int i = 0; i<sp; i++) {
        if (v[i]>x) {
            for (int j = sp; j<N; j++) {
                if (v[j]<=x) {
                    int temp = v[i];
                    v[i] = v[j];
                    v[j] = temp;
                }
            }
        }
    }
}

int main () {
    char s[100] = "Esta e uma string com duplicados";
    printf("%s\n", s);
    duplicaVogais(s);
    printf("%s\n",s);
    return 0;
}