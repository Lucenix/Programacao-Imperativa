#include <stdio.h>
#include <malloc.h>

typedef struct slist {
    int valor;
    struct slist *prox;
} *LInt;

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} *ABin;

int limpaEspacos (char s[]) {
    int r, w;
    for (r = 0, w = 0; s[r] != '\0'; r++) {
        s[w++] = s[r];
        for(r; s[r] == ' ' && s[r+1] == ' '; r++);
    }
    return w;
}

void transposta (int N, float m[N][N]){
    int i, j;
    for(i = 0; i<N; i++) {
        for(j = i+1; j<N; j++) {
            float temp = m[i][j];
            m[i][j] = m[j][i];
            m[j][i] = temp;
        }
    }
}

LInt cloneL (LInt l) {
    LInt r = NULL, *p = &r;
    while (l) {
        (*p) = malloc(sizeof(LInt));
        (*p)->valor = l->valor;
        p = &(*p)->prox;
        l = l->prox;
    }
    return r;
}

int nivelV(ABin a, int n, int v[]) {
    int r = 0, e, d;
    if (n != 1 && a) {
        e = a->esq ? nivelV(a->esq, n-1, v) : 0;
        d = a->dir ? nivelV(a->dir, n-1, v+e) : 0;
        r = e + d;
    } else if (a){
        r = 1;
        *v = a->valor;
    }
    return r;
}

void removeMaiorA(ABin a) {
    ABin ant = a;
    if (a) {
        while(a->dir) {
            ant = a;
            a = a->dir;
        }
        ant->dir = NULL;
        free(a);
    }
}

#define MAXc 3

typedef struct chunk {
    int vs [MAXc];
    struct chunk *prox;
} *CList;
typedef struct stackC {
    CList valores;
    int sp;
} StackC;

int push (StackC *s, int x) {
    if (s->sp == MAXc) {
        s->sp = 0;
        CList new = malloc(sizeof(CList));
        if (!new) return 1;
        new->prox = s->valores;
        s->valores = new;
    }
    s->valores->vs[s->sp++] = x;
    return 0;
}

int pop (StackC *s, int *x) {
    int r = 1;
    if (s->sp != 0)
        *x = s->valores->vs[--(s->sp)];
    else if (s->valores){
        CList temp = s->valores;
        s->valores = s->valores->prox;
        free(temp);
        s->sp = MAXc;
        r = 0;
    }
    return r;
}

int size(StackC s) {
    int r = 0;
    while (s.valores) {
        for (int i = 0; i<s.sp; i++) r++;
        s.sp = 3;
        s.valores = s.valores->prox;
    }
    return r;
}

void reverse (StackC *s) {
    StackC *new = malloc(sizeof(StackC));
    new->sp = 0;
    new->valores = NULL;
    int x;
    while(!pop(s, &x)) push(new, x);
}

void reversee (StackC *s) {
    int v[size(*s)], r = 0;
    StackC sc = *s;
    while(sc.valores) {
        for (int i = 0; i < sc.sp; ++i) {
            v[r++] = sc.valores->vs[--(sc.sp)];
        }
        sc.sp = 3;
        sc.valores = sc.valores->prox;
    }
    CList start = s->valores;
    for (int j = r; j>=0; j--) {
        for (int i = 0; i < MAXc; ++i) {
             s->valores->vs[s->sp++] = v[j];
        }
        s->valores = s->valores->prox;
        s->sp = 0;
    }
    s->valores = start;
}

int main () {
    char s[] = " a  m d eee   d  ";
    limpaEspacos(s);
    printf("%s", s);
    return 0;
}