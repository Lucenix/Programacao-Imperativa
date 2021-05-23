//
// Created by andre on 09/03/2021.
//

#include <stdio.h>
#include <malloc.h>

typedef struct nodo {
    int valor;
    struct nodo * prox;
} *LInt;

typedef struct nodoo {
    int valor;
    struct nodoo *esq, *dir;
} *ABin;

ABin busca(ABin a, int *t) {
    ABin r = NULL;
    if (a != NULL && t > 0) {
        r = busca(a->esq, t);
        (*t)--;
    }
    if (t == 0) {
        r = a;
    } else if (a != NULL && t > 0){
        r = busca(a->dir, t);
        (*t)--;
    }

    return r;
}

ABin procura(ABin a) {
    int t = 34;
    return busca(a, &t);
}


LInt cria() {
    LInt cabeca = malloc(sizeof(LInt));
    cabeca->valor = 0;
    cabeca->prox = NULL;
    LInt ant = cabeca;
    for (int i = 1; i<10; i++) {
        LInt new = malloc(sizeof(LInt));
        new->valor = ant->valor + 37;
        ant->prox = new;
        ant = new;
    }

    return cabeca;
}

int main () {

    return 0;
}