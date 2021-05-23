#include <stdlib.h>

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

Lista clone(Lista l) {
    Lista r = NULL, *sitio = &r;
    while (l != NULL) {
        *sitio = newLista(l->valor, NULL);
        l = l->prox;
        sitio = & ((*sitio)->prox);
    }
    //if (l != NULL)
    //    copy = newLista(l->valor, clone(l->prox));
    //else
    //    copy = NULL;
    return r;
}

Lista insereOrd (Lista l, int x) {

}

int main () {
    return 0;
}