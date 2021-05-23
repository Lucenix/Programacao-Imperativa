#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras l) {
    Palavras temp;
    while (l!= NULL) {
        temp = l;
        l = l->prox;
        free(temp->palavra);
        free(temp);
    }
    //if (l != NULL) {
    //    libertaLista(l->prox);
    //    free(l->palavra);
    //    free(l);
    //}
}

int quantasP (Palavras l) {
   int count = 0;
   while (l != NULL) {
       count++;
       l = l->prox;
   }
   //if (l != NULL) {
   //    count += quantasP(l->prox) + 1;
   //}
   return count;
}

void listaPal (Palavras l) {
    while(l != NULL) {
        printf("%s: %d\n", l->palavra, l->ocorr);
        l = l->prox;
    }
    //if (l != NULL) {
    //    printf("%s: ", l->palavra);
    //    printf("%d", l->ocorr);
    //    putchar('\n');
    //    listaPal(l->prox);
    //}
}

char *ultima (Palavras l) {
    char *r = NULL;
    if (l != NULL) {
        while (l->prox!=NULL)
            l = l->prox;
        r = l->palavra;
    }
    //if (l->prox != NULL)
    //    r = ultima(l->prox);
    //else
    //    r = l->palavra;
    return r;
}

Palavras acrescentaInicio (Palavras l, char *p) {
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = strdup(p);
    new->ocorr = 1;
    new->prox = l;
    return new;
}

Palavras acrescentaFim (Palavras l, char *p) {
    Palavras new = acrescentaInicio(NULL, p);
    Palavras res = l;
    if (l != NULL) {
        for (l; l->prox != NULL; l = l->prox);
        l->prox = new;
    } else
        res = new;
    return res;
}

void acrescenta (Palavras *l, char *p) {

    Palavras *read = l;
    while ((*read) != NULL && strcmp((*read)->palavra, p) < 0) {
        read = &((*read)->prox);
    }
    if ((*read) != NULL && (*read)->palavra == p)
        (*read)->ocorr++;
    else {
        *read = acrescentaInicio(*read, p);
    }
}

struct celula * maisFreq (Palavras l) {
    Palavras acc;
    for (; l!= NULL; l = l->prox) {
        if (l->ocorr > acc->ocorr)
            acc = l;
    }
    return acc;
}

int main () {
    return 0;
}