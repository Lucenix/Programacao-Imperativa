#include <stdio.h>
#include "stdlib.h"

typedef struct slist {
    int valor;
    struct slist * prox;
} * LInt;

typedef struct {
    LInt inicio,fim;
} Queue;

void initQueue (Queue *q) {
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q) {
    return !(q.inicio && q.fim);
}

LInt newLInt (int x, LInt xs) {
    LInt r = malloc (sizeof(struct slist));
    if (r!=NULL) {
        r->valor = x; r->prox = xs;
    }
    return r;
}

int enqueue (Queue *q, int x) {
    int r = 1;
    LInt newFim = newLInt(x, NULL);
    if (newFim != NULL) {
        if (q == NULL)
            initQueue(q);
        r = 0;
        if (q->inicio == NULL  /*QisEmpty(*q)*/)
            q->fim = q->inicio = newFim;
        else
            q->fim = q->fim->prox = newFim;
    }
    return r;
}

int dequeue (Queue *q, int *x) {
    int r = 1;
    if (q != NULL && q->inicio != NULL) {
        r = 0;
        *x = q->inicio->valor;
        LInt temp = q->inicio;
        if (q->inicio == q->fim)
            q->fim = NULL;
        q->inicio = q->inicio->prox;
        free(temp);
    }
    return r;
}

int front (Queue q, int *x) {
    int r = 1;
    if (q.inicio != NULL) {
        r = 0;
        *x = q.inicio->valor;
    }
    return r;
}

typedef LInt QueueC;

void initQueueC (QueueC *q) {
    *q = NULL;
}

int QCisEmpty (QueueC q) {
    return !q;
}

int enqueueC (QueueC *q, int x) {
    int r = 1; LInt nova = newLInt(x, NULL);
    if (nova != NULL && q) {
        r = 0;
        if (*q == NULL)
            nova->prox = nova;
        else {
            nova->prox = (*q)->prox;
            (*q)->prox = nova;
        }
        *q = nova;
    }
    return r;
}

int dequeueC (QueueC *q, int *x) {
    int r = 1;
    LInt temp;
    if (*q) {
        r = 0;
        *x = (*q)->prox->valor;
        temp = (*q)->prox;
        if ((*q)->prox == (*q))
            *q = NULL;
        else
            (*q)->prox = temp->prox;
        free(temp);
    }
    return r;
}

int frontC (QueueC *q, int *x) {
    int r = 1;
    if (*q) {
        r = 0;
        *x = (*q)->prox->valor;
    }
    return r;
}


typedef struct dlist {
    int valor;
    struct dlist *ant, *prox;
} *DList;

typedef struct {
    DList back, front;
} Deque;

void initDeque(Deque *q) {
    q->front = NULL;
    q->back = NULL;
}

int DisEmpty (Deque q) {
    return !(q.front && q.back);
}

int pushBack (Deque *q, int x) {
    int r = 1;
    DList nova = malloc(sizeof(DList));
    if (q && nova) {
        r = 0;
        nova->valor = x;
        nova->ant = NULL;
        nova->prox = q->back;
        if (q->back == NULL)
            q->front = q->back = nova;
        else
            q->back = q->back->ant = nova;
    }
    return r;
}

int pushFront (Deque *q, int x) {
    int r = 1;
    DList nova = malloc(sizeof(DList));
    if (q && nova) {
        r = 0;
        nova->valor = x;
        nova->ant = q->front;
        nova->prox = NULL;
        if (q->front == NULL)
            q->front = q->back = NULL;
        else
            q->front = q->front->prox = nova;
    }
    return r;
}

int popBack (Deque *q, int *x) {
    int r = 1;
    if (!DisEmpty(*q)) {
        r = 0;
        *x = q->back->valor;
        DList temp = q->back;
        if (q->back == q->front)
            q->front = NULL;
        q->back = q->back->prox;
        free(temp);
    }
    return r;
}

int popFront (Deque *q, int *x) {
    int r = 1;
    if (!DisEmpty(*q)) {
        r = 0;
        *x = q->front->valor;
        DList temp = q->front;
        if (q->back == q->front)
            q->back = NULL;
        q->front = q->front->ant;
        free(temp);
    }
    return r;
}

int main() {
    long long *a;
    *a = 100;
    printf("%ld", *((long *) a));
    *((long *) a) -= 1;
    printf("%lld", *a);
    return 0;
}
