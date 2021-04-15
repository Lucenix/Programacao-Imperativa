//
// Created by andre on 22/03/2021.
//
#include <stdio.h>
#include <string.h>
#define NUMERO_VOGAIS 10

int isVogal(char s) {
    char casos[NUMERO_VOGAIS] = "AEIOUaeiou";
    int r = 0;
    for (int i = 0; i<10; i++) {
        if (casos[i] == s) r =1;
    }
    return r;
}

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
    //char aux[strlen(s)];
    int w = 0, r;
    for (r = 0; s[r] != '\0'; r++) 
        if (s[r] != s[r+1] || !isVogal(s[r]))
            s[w++] = s[r];
            //aux[w++] = s[r];
    s[w] = '\0';
    //aux[w] = '\0';
    //for (int i = w; i>=0 ; i--) {
    //    s[i] = aux[i];
    //}
    return (r-w); 

    //for (int i = 0; s[i]!='\0'; i++) {
    //    for (int j = 0; j<NUMERO_VOGAIS && s[i+1] != '\0'; j++) {
    //        if (s[i] == casos[j] && s[i+j]==s[i]) {
    //            //escreve o restanto da string sem ser duplicado em cima do local onde está o duplicado
    //            for (int k = i+1; s[k]!='\0'; k++)
    //                s[k] = s[k+1];
    //            conta++;
    //            j = NUMERO_VOGAIS;
    //        }
    //    }
    //}
    //return conta;
}

//1.3
int duplicaVogais (char *s) {
    int vog = contaVogais(s);
    int r = strlen(s);
    int w  = r + vog;
    s[w] = '\0';
    for (r-=1; r>=0; r--) {
        if (isVogal(s[r])) s[w--] = s[r];
        s[w--] = s[r];
    }
    return (vog);
    //int conta = 0;
    //char casos[NUMERO_VOGAIS] = "AEIOUaeiou";
    //for (int i = 0; s[i]!='\0';i++){
    //    for (int j = 0; j<NUMERO_VOGAIS; j++) {
    //        if (s[i] == casos[j]) {
    //            for (int k = strlen(s); k>=i ; k--)
    //                s[k+1] = s[k];
    //            j=NUMERO_VOGAIS;
    //            i++;
    //            conta++;
    //        }
    //    }
    //}
    //return conta;
}

//2.1
int ordenado (int v[], int N) {
    int r = 1;
    for(int i = 0; i<N-1 && r == 1; i++)
        if (v[i]>v[i+1]) r = 0;
    return r;
}

//2.2
void merge (int a[], int na, int b[], int nb, int r[]) {
    int i = 0, j = 0;
    while(i<na&&j<nb) {
        if (a[i] < b[j]) {
            r[i+j] = a[i++];
        } else {
            r[i+j] = b[j++];
        }
    }
    while(i<na) {
        r[i+j] = a[i++];
    }
    while(j<nb) {
        r[i+j] = b[j++];
    }
}

void mergeSort() (int v[], int N) {
    if (N<2) {
        int m = N/2, aux [N], t2 = N-m, seg = v+m;
        mergeSort(v, m);
        mergeSort(seg, t2);
        merge (v, m, seg, t2, aux);
    }
    for (int i = 0; i<N; i++)
        v[i] = aux[i];
}

//2.3
void partition(int v[], int N, int x) {
    int i,r;
    for (i = r = 0; i<N; i++)
        if (v[i]<=x) {
            int temp = v[i];
            v[r++] = v[i];
            v[i] = temp;
        }
    return x;
}