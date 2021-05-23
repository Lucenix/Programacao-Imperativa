#include <stdlib.h>
#include <stdio.h>

typedef struct slist {
    int valor;
    struct slist * prox;
} *LInt;

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x;
        r->prox = xs;
    }
    return r;
}

LInt clone (LInt l) {
    LInt r,a,b;
    r = a = b = NULL;
    while (l) {
        a = newLInt(l->valor,NULL);

        if (!b) r = a;
        if (b) a->prox = a;
        b = a;

        l = l->prox;
    }
    return r;
}

int main () {
    LInt l1 = newLInt(1, newLInt(2, NULL));
    LInt l2 = clone(l1);
    while (l2) {
        printf("%d", l2->valor);
        l2 = l2->prox;
    }
    putchar('\n');
    return 0;
}

