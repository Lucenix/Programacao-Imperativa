
#include "stdlib.h"

typedef struct lista {
    int valor;
    struct lista *prox;
} * Lista;

Lista newLista (int x, Lista l) {
    Lista r;
    r = malloc (sizeof (struct lista));
    r->valor = x;
    r->prox = l;
    return r;
}

Lista fromArray (int v[], int N) {
    Lista r = NULL;
    if (N>0)
        r = newLista(v[0], fromArray(v+1, N-1));
    //for (i = N; i>0; i--)
    //    r = newLista(v[i]-1, r);
    return r;
}

Lista clone(Lista l) {
    int i, j;
    Lista r, ult = NULL, new;

    r = newLista(l->valor,ult);
    ult = r;
    l = l->prox;

    for (l; l != NULL; l = l->prox) {
        new = newLista(l->valor, NULL);
        ult->prox = new;
    }

    //if (l != NULL)
    //    copy = newLista(l->valor, clone(l->prox));
    //else
    //    copy = NULL;
    return r;
}

int main () {
    Lista z;
    z = newLista(1, newLista(2, newLista(3, NULL)));
    Lista a = clone(z);
    return 0;
}

