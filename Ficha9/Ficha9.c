
#include "stdlib.h"
#include "stdio.h"

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin newABin (int r, ABin e, ABin d) {
    ABin a = malloc (sizeof(struct nodo));
    if (a!=NULL) {
        a->valor = r; a->esq = e; a->dir = d;
    }
    return a;
}

int altura (ABin a) {
    int r = 0, e, d;
    if (a != NULL) {
        e = altura(a->esq);
        d = altura(a->dir);
        r = 1 + (e > d ? e : d);
    }
    return r;
}

int nFolhas (ABin a) {
    int r = 0;
    if (a != NULL) {
        if (a->esq == NULL && a->dir == NULL)
            r = 1;
        else
            r = nFolhas(a->dir) + nFolhas(a->esq);
    }
    return r;
}

ABin maisEsquerda (ABin a) {
    if (a != NULL)
        while (a->esq != NULL)
            a = a->esq;
    return a;
}

void imprimeNivel (ABin a, int l) {
    if (a != NULL) {
        if (l == 0)
            printf("%d ", a->valor);
        else {
            imprimeNivel(a->esq, l-1);
            imprimeNivel(a->dir, l-1);
        }
    }
}

int procuraE (ABin a, int x) {
    return a != NULL && ((a->valor == x) || procuraE(a->esq, x) || procuraE(a->dir, x));
}

struct nodo *procura (ABin a, int x) {
    while (a != NULL && a->valor != x) {
        if (a->valor > x)
            a = a->esq;
        else
            a = a->dir;
    }
    return a;
}

int nivel (ABin a, int x) {
    int r;
    /*
    int i;
    for (i = 0, r = -1; a != NULL && r == -1; i++) {
        if (a->valor == x)
            r = i;
        else if (a->valor > x)
            a = a->esq;
        else
            a = a->dir;
    }*/
    for (r = 0; a != NULL && a->valor != x; r++) {
        if (a->valor > x)
            a = a->esq;
        else
            a = a->dir;
    }
    return a != NULL ? r : -1;
}

void imprimeAte (ABin a, int x) {
    if (a != NULL) {
        imprimeAte(a->esq, x);
        if (a->valor < x) {
            printf("%d ", a->valor);
            imprimeAte(a->dir, x);
        }
    }
}

ABin insere (ABin a, int x) {
    ABin *sitio = &a;
    while ((*sitio) != NULL) {
        if ((*sitio)->valor < x) //salvaguarda o apontador do nodo pai porque esse endereço não muda
            sitio = &(*sitio)->dir;
            //*sitio = (*sitio)->dir acho que destroi a arvore porque altera o que está no endereço para o que vem a seguir
        else
            sitio = &(*sitio)->esq;
    }
    (*sitio) = newABin(x, NULL, NULL); //não sei se isto dá... dá sim porque sitio == &(local a adicionar) logo ao alterar o conteudo
    return a;
}

int main() {
    return 0;
}