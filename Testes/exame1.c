#include <ctype.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct celula {
    char *palavra;
    int comp;
    struct celula *prox;
} *Palavras;

int daPalavra (char *s, int *e) {
    int read, r;
    for(read = 0, *e = 0; s[read] != '\0' && isspace(s[read]); read++, (*e)++)
        ;
    for(read; s[read] != '\0' && s[read] != ' '; read++, r++)
        ;
    return r;
}

Palavras words (char *texto) {
    int read = 0;
    Palavras newS, *sitio = &newS;
    while (texto[read] != '\0') {
        (*sitio) = malloc(sizeof(Palavras));
        int len = daPalavra(texto, &read);
        (*sitio)->comp = len;
        (*sitio)->palavra = texto+read;
        read += len;
        sitio = &(*sitio)->prox;
    }
    return newS;
}

Palavras daLinha (Palavras t, int n) {
    int tamanhoTotal = 0;
    Palavras ant;
    for(; t && tamanhoTotal<=n;t = t->prox) {
        tamanhoTotal += t->comp + 1;
        if (tamanhoTotal > n)
            break;
        ant = t;
    }
    t = ant->prox;
    ant->prox = NULL;
    return t;
}

int tamLinha(Palavras p, int *nesp) {
    int len = 0;
    *nesp = 0;
    while (p) {
        len += p->comp;
        if (p->prox) (*nesp)++;
        p = p->prox;
    }
    return len;
}

void escreveLinha (Palavras p, int n) {
    if (p->comp > n)
        printf("%s\n", p->palavra);
    else {
        int nesp, len, ncada;
        len = tamLinha(p, &nesp);
        ncada = (n-len)/nesp;
        printf("%s", p->palavra);
        for(int i = 0; i<ncada; i++)
            putchar(' ');
        while(p) {
            Palavras temp = p;
            p = p->prox;
            free(temp);
        }
        putchar('\n');
    }
}

void formata(char texto[], int largura) {
    Palavras temp = words(texto), resto;
    while (temp) {
        resto = daLinha(temp, largura);
        escreveLinha(temp, largura);
        temp = resto;
    }
}