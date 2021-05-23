//
// Created by andre on 21/04/2021.
//
#define MAX 10

#include <malloc.h>
#include "stdio.h"

struct staticstack {
    int sp;
    int values[MAX];
};

typedef struct staticstack *SStack;

void Sinit(SStack s) {
    s->sp = 0;
}

int Sisempty (SStack s) {
    int z;
    return (s->sp == 0);
}

int Spush (SStack s, int x) {
    int r = 1;
    if (s->sp < MAX) {
        s->values[(s->sp)++] = x;
        r = 0;
    }
    return r;
}

int Spop (SStack s, int *x) {
    int r = 1;
    if (s->sp > 0) {
        *x = s->values[--s->sp];
        r = 0;
    }
    return r;
}

int Stop (SStack s, int *x) {
    int r = 1;
    if (s->sp > 0) {
        *x = s->values[s->sp-1];
        r = 0;
    }
    return r;
}

typedef struct staticQueue {
    int front;
    int length;
    int values [MAX];
} QUEUE, *SQueue;

void SinitQueue(SQueue q) {
    q->length = 0;
    q->front = 0;
}

int SisEmpty(SQueue q) {
    return (q->length == 0);
}

int Senqueue(SQueue q, int x) {
    int r = 1;
    if (q->length < MAX) {
        r = 0;
        q->values[(q->front + (q->length++))%MAX] = x;
    }
    return r;
}

int Sdequeue(SQueue q, int *x) {
    int r = 1;
    if (q->length > 0) {
        r = 0;
        *x = q->values[q->front];
        q->front = (q->front+1)%MAX;
        q->length--;
    }
    return r;
}

int Sfront(SQueue q, int *x) {
    int r = 1;
    if (q->length > 0) {
        r = 0;
        *x = q->values[q->front];
    }
    return r;
}

typedef struct dinStack {
    int size; // guarda o tamanho do array values
    int sp;
    int *values;
} *DStack;

typedef struct dinQueue {
    int size; // guarda o tamanho do array values
    int front;
    int length;
    int *values;
} *DQueue;

void Dinit (DStack s) {
    s->sp = 0;
    s->size = MAX;
    s->values = malloc(sizeof(int)*s->size);
}

int SisemptyD(DStack s) {
    return(s->sp == 0);
}

int DupDStack(DStack s) {
    int r = 1;
    int *temp = realloc(s->values,sizeof (int)*2*s->size);
    if (temp != NULL) {
        r = 0;
        s->values = temp;
        s->size *= 2;
    }
    return r;
}

int Dpush(DStack s, int x) {
    int r = 0;
    if (s->sp == s->size)
        r = DupDStack(s);
    if (r == 0)
        s->values[s->sp++] = x;
    return r;
}

void DinitQueue (DQueue q) {
    q->front = 0;
    q->length = 0;
    q->size = MAX;
    q->values = malloc(sizeof(int) * q->size);
}

int DisEmptyQ (DQueue q) {
    return (q->length == 0);
}

int DupDQueue (DQueue q) {
    int r = 1;
    int *temp = realloc(q->values, sizeof(int) * 2 * q->size);
    if (temp != NULL) {
        r = 0;
        q->values = temp;
        for (int i = 0; i<q->front; i++) {
            q->values[q->size + i] = q->values[i];
        }
        q->size *= 2;
    }
    return r;
}

int Denqueue (DQueue q, int x) {
    int r = 0;
    if (q->length == q->size)
        r = DupDQueue(q);
    if (r == 0)
        q->values[(q->front + q->length++) % q->size] = x;
    return r;
}

int Ddequeue (DQueue q, int *x) {
    int r = 1;
    if (q->length != 0) {
        r = 0;
        *x = q->values[q->front];
        q->front = (q->front+1)%q->size;
        q->length--;
    }
    return r;
}

int Dfront (DQueue q, int *x) {
    int r = 1;
    if (q->length != 0) {
        r = 0;
        *x = q->values[q->front];
    }
    return r;
}

int main () {
    QUEUE q;
    SinitQueue(&q);
    Senqueue(&q, 3);
    printf("%d\n", q.length);
    printf("%d\n", q.front);
    printf("%d\n", q.values[q.front]);
    return 0;
}
