#include <stdio.h>
#include <assert.h>
#include "stdlib.h"

typedef struct slist    {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int retiraNeg (int v[], int N) {
    int r, w;
    for (r = 0; r<N; r++) {
        if (v[r] >= 0) 
            v[w++] = v[r];
    }
    return w;
}

int difConsecutivos (char s[]) {
    int i, j, k, max = 0;
    for (i = 0; s[i] != '\0'; i++) {
        int r;
        for (j = i+1; j != -1 && s[j] != '\0'; j++) {
            for (k = i; s[k] != s[j]; k++)
                ;
            if (k != j) {
                r = j-i;
                j = -2;
            } else {
                r = j-i+1;
            }
        }
        if (max < r)
            max = r;
    }
    return max;
}

int maximo(LInt l) {
    int max = l->valor;
    for (l = l->prox; l != NULL; l = l->prox) {
        if (l->valor > max)
            max = l->valor;
    }
    return max;
}

int removeALL(LInt l, int x) {
    LInt *sitio = &l;
    int r = 0;
    while (*sitio != NULL) {
        if ((*sitio)->valor == x) {
            r++;
            (*sitio) = (*sitio)->prox;
        } else {
            sitio = &(*sitio)->prox;
        }
    }
    return r;
}

LInt arrayToList (int v[], int N) {
    LInt l = NULL, *r = &l;
    for (int i = 0; i<N; i++) {
        (*r) = malloc(sizeof(LInt));
        (*r)->valor = v[i];
        r = &(*r)->prox;
    }
    return l;
}

int miniHeapOK(ABin a) {
    int r = 1;
    if (a) {
        if (a->dir)
            r = (a->valor < a->dir->valor) && miniHeapOK(a->dir);
        if (a->esq)
            r = (a->valor < a->esq->valor) && miniHeapOK(a->esq);
    }
    return r;
}

int maxHeap(ABin a) {
    int l = a->esq ? maxHeap(a->esq) : a->valor;
    int r = a->dir ? maxHeap(a->dir) : a->valor;
    return (l < r ? r : l);
}

void removeMin(ABin *a) {
    if ((*a)->esq && (*a)->dir) {
        if ((*a)->esq->valor < (*a)->dir->valor) {
            (*a)->valor = (*a)->esq->valor;
            removeMin(&(*a)->esq);
        } else {
            (*a)->valor = (*a)->dir->valor;
            removeMin(&(*a)->dir);
        }
    } else {
        ABin temp = (*a);
        (*a)->esq ? (*a) = (*a)->esq : ((*a) = (*a)->dir);
        free(temp);
    }
}

void add(ABin *a, int x);

void heapSort(int v[], int N) {
    ABin *tree = malloc(sizeof(ABin));
    *tree = NULL;
    int i;
    for (i = 0; i<N; i++)
        add(tree, v[i]);
    for (i = 0; i<N; i++) {
        v[i] = (*tree)->valor;
        removeMin(tree);
    }
}

int kMaior (int v[], int N, int k) {
    int i;
    ABin *tree = malloc(sizeof(tree));
    *tree = NULL;
    for (i = 0; i<k; i++) add(tree, v[i]);
    for (i; i<N; i++) {
        if (v[i] > (*tree)->valor) {
            removeMin(tree);
            add(tree, v[i]);
        }
    }
    return(*tree)->valor;
}

//int main () {
//    char s[] = "aabcccaac";
//    printf("%d\n", difConsecutivos(s));
//    char f[] = "aabcccaabcd";
//    printf("%d\n", difConsecutivos(f));
//    return 0;
//}