#include <string.h>
#include <malloc.h>
#include <stdio.h>
#include <ctype.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

char *strcpymine(char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

void strnoV(char s[]) {
    int i, w;
    for (i = 0, w = 0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'e')
            s[w++] = s[i];
    }
}

int dumpAbin(ABin a, int v[], int N) {
    int i = 0;
    if (a && N) {
        i += dumpAbin(a->esq, v, N);
        if (i<N) {
            v[i++] = a->valor;
            i += dumpAbin(a, v+i, N-i);
        }
    }
    return i;
}

int lookupAB (ABin a, int x) {
    int r = 0;
    while (a && !r) {
        if (a->valor == x)
            r = 1;
        else if (a->valor > x)
            a = a->esq;
        else
            a = a->dir;
    }
    return r;
}

typedef struct listaP{
    char *pal;
    int cont;
    struct listaP *prox;
} Nodo, *Hist;

int inc(Hist *h, char *pal) {
    int r;
    while (*h && strcmp(pal, (*h)->pal) < 0) {
        h = &(*h)->prox;
    }
    if (!(*h)) {
        Hist new = malloc(sizeof(Nodo));
        new->pal = pal;
        r = new->cont = 1;
        new->prox = NULL;
        (*h) = new;
    } else if (strcmp((*h)->pal, pal) == 0) {
        r = ++((*h)->cont);
    } else {
        Hist new = malloc(sizeof(Nodo));
        new->pal = pal;
        r = new->cont = 1;
        new->prox = (*h);
        (*h) = new;
    }
    return r;
}

char *remMaisFreq(Hist *h, int *count) {
    Hist *maxNodo = h;
    int max = (*h)->cont;
    for (h = &(*h)->prox; (*h); h = &(*h)->prox) {
        if (max < (*h)->cont) {
            max = (*h)->cont;
            maxNodo = h;
        }
    }
    *count = max;
    char *r = (*maxNodo)->pal;
    Hist temp = *maxNodo;
    (*maxNodo) = (*maxNodo)->prox;
    free(temp);
    return r;
}

int main () {
    char *token, line[10240];
    fgets(line, 10240, stdin);
    Hist storage;
    char *delim = " \t\n";
    for(token = strtok(line,delim);token != NULL; token = strtok(NULL, delim)) {
        int i,w;
        for(i = 0, w = 0; token[i] != '\0'; i++) {
            if (isalpha(token[i])) {
                token[w] = tolower(token[i]);
                w++;
            }
        }
        token[w] = '\0';
        inc(&storage, token);
    }

    int i=0, count;
    char buff[60];
    while(i<10 && storage) {
        strcpymine(buff,remMaisFreq(&storage, &count));
        if(strlen(buff) > 3) {
            printf("%s\n", buff);
            i++;
        }
    }

    return 0;
}