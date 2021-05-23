#include "stdlib.h"

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;

ABin removeMenor (ABin *a) {
    ABin r = NULL;
    if (*a != NULL) {
        while ((*a)->esq != NULL)
            a = &(*a)->esq;
        r = *a;
        (*a) = (*a)->dir;
    }
    return r;
}

void removeRaiz (ABin *a) {
    ABin cabeca;
    if ((*a)->dir != NULL) {
        cabeca = removeMenor(&(*a)->dir);
        cabeca->esq = (*a)->esq;
    } else 
        cabeca = (*a)->esq;
    cabeca->dir = (*a)->dir; //e null quando a dir e NULL
    free(*a);
    *a = cabeca;
}

int removeElem (ABin *a, int x) {
    int r = 1;
    while((*a) != NULL && (*a)->valor != x) {
        if (x > (*a)->valor)
            a = &(*a)->dir;
        else
            a = &(*a)->esq;
    }
    if ((*a) != NULL) {
        r = 0;
        removeRaiz(a);
    }
    return r;
}

void rodaEsquerda (ABin *a){ABin b = (*a)->dir;(*a)->dir = b->esq;b->esq = (*a);*a = b;}
void rodaDireita (ABin *a){ABin b = (*a)->esq;(*a)->esq = b->dir;b->dir = *a;*a = b;}

void promoveMenor (ABin *a) {
    if ((*a) != NULL && (*a)->esq != NULL) {
        promoveMenor(&(*a)->esq);
        rodaDireita(a);
    }
}

void promoveMaior (ABin *a) {
    if ((*a) != NULL && (*a)->dir != NULL) {
        promoveMaior(&(*a)->dir);
        rodaEsquerda(a);
    }
}

ABin removeMenorNew (ABin *a) {
    promoveMenor(a);
    ABin r = (*a);
    (*a) = (*a)->dir;
    return r;
}

int constroiEspinhaAux(ABin *a, ABin *ult) {
        int r = 0;
        if ((*a) != NULL) {
            r++;
            if ((*a)->esq != NULL) {
                ABin b = (*a);
                while (b->esq != NULL)
                    b = b->esq;
                r += constroiEspinhaAux(&(*a)->esq, ult);
                (*ult)->dir = (*a);
                (*ult) = (*a);
                (*a) = b;
            }
            if ((*a)->dir != NULL) {
                r += constroiEspinhaAux(&(*ult)->dir, ult);
            } else {
                (*ult) = (*a);
            }
        }

        return r;
}

int constroiEspinha (ABin *a) {
    ABin ult;
    return constroiEspinhaAux(a, &ult);
}

ABin equilibraEspinha (ABin *a, int n) {
    ABin r = *a;
    if (n == 0) {
        *a = NULL;
    } else {
        int i;
        ABin *temp = a;
        for (i = 0; i < n; i++) 
            temp = &(*temp)->dir;
        r = (*temp);

        while(*temp != NULL) {
            ABin aux = *temp;
            temp = &(*temp)->dir;
            free(aux);
        }

    }
    return r;
}