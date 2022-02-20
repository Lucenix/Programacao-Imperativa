#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <malloc.h>

void one() {
    int max=0,r;
    do{
        assert(scanf("%d", &r) ==1);
        if (max < r)
            max = r;
    }while(r!=0);
    printf("%d",max);
}

void two() {
    int r, soma = 0,count = 0;
    do {
        assert(scanf("%d", &r) ==1);
        soma += r;
        count++;
    }while(r!=0);
    printf("%f", (double) soma / (double) count);
}

void three() {
    int r, max, max2;
    assert(scanf("%d", &r) == 1);
    max = r;
    while (r!=0) {
        assert(scanf("%d", &r) == 1);
        if (r >= max) {
            max2 = max;
            max = r;
        } else if (r > max2) {
            max2 = r;
        }
    }
    printf("%d", max2);
}

int bitsUm (unsigned int n) {
    int r = 0;
    while (n!=0) {
        if (n%2 == 1)
            r++;
        n/=2;
    }
    return r;
}

int trailingZ (unsigned int n) {
    int r = 0;
    unsigned int a;
    while (n!=0 && a!=1) {
        a = n%2;
        if (a == 0)
            r++;
        n/=2;
    }
    return r;
}

int qDig (unsigned int n) {
    int i = 1;
    while (n!=0) {
        n/=10;
        i++;
    }
    return i;
}

char *strcatt (char s1[], char s2[]) {
    int i, j;
    for (i = 0; s1[i]!='\0'; i++);
    for (j = 0; s2[j]!='\0'; j++) {
        s1[i+j] = s2[j];
    }
    s1[i+j] = '\0';
    return s1;
}

char *strcpyy (char *dest, char source[]) {
    int i;
    for (i = 0; source[i] != '\0'; i++) {
        dest[i] = source[i];
    }
    dest[i] = '\0';
    return dest;
}

int strcmpp (char s1[], char s2[]) {
    int i;
    for (i = 0; s1[i] != '\0' && s1[i] == s2[i]; i++);
    return s1[i] - s2[i];
}

char *strstrr (char s1[], char s2[]) {
    int i = 0, j, k;
    char *r = NULL;

    do {
        for (j = 0, k = i; s1[k] != '\0' && s1[k] == s2[j]; j++, k++);
        if (s2[j] == '\0')
            r = s1 + i;
        i++;
    }while(s1[i] != '\0' && r == NULL);

    return r;
}

void strrevv (char s[]) {
    int i,j;
    for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
    }
}

void strnoV(char s[]) {
    int i, w;
    for (i=0, w=0; s[i] != '\0'; i++) {
        if (s[i] != 'a' && s[i] != 'e')
            s[w++] = s[i];
    }
}

void truncW (char t[], int n) {
    char delim = ' ';
    int i, conta = 0, w;
    for (i = 0, w = 0; t[i] != '\0'; i++) {
        if (t[i] == delim){
            t[w++] = delim;
            conta = 0;
        } else if (conta < n) {
            t[w++] = t[i];
            conta++;
        }
    }
    t[w] = '\0';
}

char charMaisFreq (char s[]) {
    char r;
    if (!s) r = 0;
    else {
        char aux[strlen(s)];
        strcpy(aux, s);
        int i, w = 1, j;
        for (i = 1; s[i] != '\0'; i++) {
            for (j = 0; j<w && s[i] != aux[j]; j++);
            if (j == w) aux[w++] = s[i];
        }
        aux[w] = '\0';
        int max = 0, conta;
        for (i = 0; aux[i] != '\0'; i++) {
            conta = 0;
            for (j = 0; s[j] != '\0'; j++)
                if (s[j] == aux[i]) conta++;
            if (conta > max) {
                max = conta;
                r = aux[i];
            }
        }
    }
    return r;
}

int iguaisConsecutivos (char s[]) {
    int i,j, r = 0, conta;
    for (i = 0; s[i] != '\0'; i++){
        conta = 0;
        for (j = i; s[j] != '\0' && s[i] == s[j]; j++) {
            conta++;
        }
        if (r<conta) r = conta;
    }
    return r;
}

int compPrefixoSemRep (char s[]) {
    int i, j, r = 0;
    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; s[j] != s[i]; j++);
        if (j!=i) return r;
        else r++;
    }
    return r;
}

int difConsecutivos (char s[]) {
    int r=0, i, j;
    for (i = 0; s[i] != '\0'; i++) {
        j = compPrefixoSemRep(s + i);
        if (r<j) r = j;
    }
    return r;
}

int maiorPrefixo (char s1 [], char s2 []) {
    int i,r=0;
    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++);
    if (s1[i]!=s2[i]) r = i;
    else r = i+1;
    return r;
}

int maiorSufixo (char s1[], char s2[]) {
    int i, j, r=0;

    for(i=0; s1[i]!='\0'; i++); i--; // strlen()
    for(j=0; s2[j]!='\0'; j++); j--; // strlen()

    while (s1[i] == s2[j] && (i>=0 || j>=0)) {
        i--;
        j--;
        r++;
    }

    return r;
}

int sufPref (char s1[], char s2[]) {
    int i,j;
    for(i=0, j=0; s1[i]!='\0'; i++) {
        if (s1[i] == s2[j]) j++;
        else j = 0;
    }
    return j;
}

int contaPal (char s[]) {
    int r = 0;
    while (*s != '\0') {
        while (*s != '\0' && *s!=' ')
            s++;
        while (*s == ' ')
            s++;
        r++;
    }
    return r;
}

int contaVogais (char s[]) {
    int r = 0;
    while (*s != '\0') {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' ||
            *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')
            r++;
    }
    return r;
}

int contida (char a[], char b[]) {
    int r = 1;
    while (*a != '\0' && *b != '\0') {
        if (*a == *b)
            ++b;
        ++a;
    }
    if (*b != '\0')
        r = 0;
    return r;
}

int palindrome (char s[]) {
    int i;
    long len = strlen(s);
    for (i = 0; len > i && s[i] == s[len]; i++, len--)
        ;
    if (len < i)
        len = 1;
    else
        len = 0;
    return len;
}

int remRep (char x[]) {
    int w = 0, r = 0;
    while (x[r] != '\0') {
        char temp = x[r++];
        while (x[r] == temp)
            r++;
        x[w++] = temp;
    }
    x[w] = '\0';
    return w;
}

int limpaEspacos (char t[]) {
    int w, r;
    for (r = 0; t[r] != '\0' && t[r] != ' '; r++)
        ;
    for (w = r; t[r] != '\0'; w++) {
        char temp = t[r];
        //o r++ não pode aparecer no incremento porque se não avança um a mais
        //desta maneira v sei que ele avança sempre pelo menos uma vez ao fazer o teste
        while (t[r++] == ' ');
        t[w] = temp;
    }
    t[w] = '\0';
    return w;
}

void insere (int v[], int N, int x) {
    for (N; N >= 0 && v[N] > x; N--) {
        v[N+1] = v[N];
    }
    v[N+1] = x;
}

void merge (int r[], int a[], int b[], int na, int nb) {
    int i = 0, j = 0;
    while (i < na && j < nb) {
        if (a[i] < b [j])
            r[i+j] = a[i++];
        else
            r[i+j] = b[j++];
    }
    while (i < na)
        r[i+j] = a[i++];
    while (j < nb)
        r[i+j] = b[j++];
}

int crescente (int a[], int i, int j) {
    int r = 1;
    while (r && i < j) {
        if (a[i] > a[i+1])
            r = 0;
        i++;
    }
    return r;
}

int retiraNeg (int v[], int N) {
    int r, w;
    for (r = 0, w = 0; r < N; r++) {
        if (v[r] >= 0)
            v[w++] = v[r];
    }
    return w;
}

int menosFeq (int v[], int N) {
    int i, conta, min, acc, r;
    for (i = 0, min = 0; i < N; i++) {
        acc = v[i];
        for (conta = -1; i<N && v[i] == acc; i++, conta++);
        if (conta < min) {
            min = conta;
            r = acc;
        }
    }
    return r;
}

int elimRepOrd (int v[], int n) {
    int r, w;
    for (r = 0, w = -1; r < n; r++) {
        if (v[w] != v[r]) {
            v[++w] = v[r];
        }
    }
    if (n==0) w--;
    return w+1;
}

int comunsOrd (int a[], int na, int b[], int nb) {
    int i=0, j=0, r=0;
    while (i<na && j<nb) {
        if (a[i] == b[j]) {
            i++;j++;r++;
        } else if (a[i] < b[j]) {
            i++;
        } else {
            j++;
        }
    }
    return r;
}

//estupido, está a ver números repetidos como se fossem comuns se os repetidos estiverem no a {1,1,3,3} e {1,3} dá resultado 4
//enquanto que no outro dá resultado 2 enfim
int comuns (int a[], int na, int b[], int nb) {
    int i,j,ra=0,flag;
    for(i = 0; i<na;i++) {
        for (j = 0,flag = 1; j<nb && flag; j++) {
            if (a[i] == b[j]) {flag--; ra++;}
        }
    }
    return ra;
}

int minInd(int v[], int n) {
    int min = n-1, i;
    for (i = 0 ;i<n-1; i++) {
        if (v[min]>v[i]) min = i;
    }
    return min;
}

void somasAc(int v[], int Ac [], int N) {
    int i;
    if (N>0) {
        Ac[0] = v[0];
        for (i = 1; i<N; i++) {
            Ac[i] = v[i] + Ac[i-1];
        }
    }
}

int triSup (int N, float m [N][N]) {
    int i, j, r = 1;
    for (i = 0; i<N && r; i++) {
        for (j = 0; j<i && r;j++) {
            if (m[i][j] != 0) r = 0;
        }
    }
    return r;
}

void transporta (int N, float m [N][N]) {
    int i, j;
    for (i = 0; i<N; i++) {
        for (j = i; j<N; j++) {
            if (i!=j) {
                float temp = m[i][j];
                *(&m[i][j]) = m[j][i];
                *(&m[j][i]) = temp;
            }
        }
    }
}

void addTo (int N, int M, int a [N][M], int b[N][M]) {
    int i, j;
    for (i = 0; i<N; i++) {
        for (j = 0; j<M; j++) {
            *(&(a[i][j])) += b[i][j];
        }
    }
}

int unionSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, len = 0;
    for (i = 0; i<N; i++) {
        r[i] = v1[i] || v2[i];
        len+=r[i];
    }
    return len;
}

int intersectSet(int N, int v1[N], int v2[N], int r[N]) {
    int i, len = 0;
    for (i = 0; i<N; i++) {
        r[i] = v1[i] && v2[i];
        len+=r[i];
    }
    return len;
}

int unionMSet(int N, int v1[N], int v2[N], int r[N]){
    int i, len = 0;
    for (i = 0; i<N; i++) {
        r[i] = v1[i] + v2[i];
        len+=r[i];
    }
    return len;
}

int intersectMSet(int N, int v1[N], int v2[N], int r[N]){
    int i, len = 0;
    for (i = 0; i<N; i++) {
        r[i] = (v1[i] > v2[i] ? v2[i] : v1[i]);
        len+=r[i];
    }
    return len;
}

int cardinalMSet (int N, int v[N]) {
    int i, r = 0;
    for (i = 0; i<N; i++) r += v[i];
    return r;
}

typedef enum movimento {Norte, Oeste, Sul, Este} Movimento;
typedef struct posicao {
    int x, y;
} Posicao;

Posicao posFinal (Posicao inicial, Movimento mov[], int N) {
    int i;
    for (i = 0; i<N; i++) {
        switch (mov[i]) {
            case Norte:
                (inicial.y)++;
                break;
            case Sul:
                (inicial.y)--;
                break;
            case Este:
                (inicial.x)++;
                break;
            case Oeste:
                (inicial.x)--;
                break;
        }
    }
    return inicial;
}

int caminho (Posicao inicial, Posicao final, Movimento mov[], int N) {
    int i, flag = 1;
    for (i = 0; i<N && flag; i++) {
        if (inicial.x < final.x) mov[i] = Este;
        else if (inicial.y < final.y) mov[i] = Norte;
        else if (inicial.x > final.x) mov[i] = Oeste;
        else if (inicial.y < final.y) mov[i] = Sul;
        else flag = 0;
    }
    if (i == N && flag) return -1;
    else return i;
}

int maisCentral (Posicao pos[], int N) {
    int i, contaMin = (pos[N-1].x * pos[N-1].x) + (pos[N-1].y * pos[N-1].y), min = N-1;
    for (i = 1; i<N; i++) {
        int temp =(pos[i].x * pos[i].x) + (pos[i].y * pos[i].y);
        if ((pos[i].x * pos[i].x) + (pos[i].y * pos[i].y) < contaMin) { contaMin = temp; min = i;}
    }
    return min;
}

int vizinhos (Posicao p, Posicao pos[], int N) {
    int i, r;
    for (i = 0, r = 0; i<N; i++) {
        if (p.x == pos[i].x + 1 ||
            p.x == pos[i].x - 1 ||
            p.y == pos[i].y + 1 ||
            p.y == pos[i].y - 1) r++;
    }
    return r;
}

typedef struct lligada {
    int valor;
    struct lligada *prox;
} *LInt;

LInt newLInt (int v, LInt t){
    LInt new = (LInt) malloc (sizeof (struct lligada));

    if (new!=NULL) {
        new->valor = v;
        new->prox  = t;
    }
    return new;
}

int length (LInt l) {
    int r;
    for (r = 0; l; l = l->prox, r++);
    return r;
}

void freeL (LInt l) {
    LInt aux;
    while (l) {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

void imprimeL (LInt l) {
    while (l) {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

LInt reverseL (LInt l) {
    LInt temp = NULL, next;
    if (l) {
        while (l->prox) {
            next = l->prox;
            l->prox = temp;
            temp = l;
            l = next;
        }
        l->prox = temp;
    }
    return l;
}

void insertOrd (LInt *l, int x) {
    while (*l && (*l)->valor < x) {
        l = &(*l)->prox;
    }
    LInt new = newLInt(x, *l);
    (*l) = new;
}

int removeOneOrd (LInt *l, int x) {
    int r = 1;
    while (*l && (*l)->valor < x) l = &(*l)->prox;
    if (*l && (*l)->valor == x) { r = 0; *l = (*l)->prox; }
    return r;
}

void mergeL (LInt *r, LInt a, LInt b) {
    while (a && b) {
        if (a->valor < b->valor) { *r = a; a = a->prox;}
        else { *r = b; b = b->prox;}
        r = &(*r)->prox;
    }
    if (a) *r = a;
    else if (b) *r = b;
}

void splitQS (LInt l, int x, LInt *mx, LInt *Mx) {
    while (l) {
        if (l->valor < x) {*mx = l; mx = &(*mx)->prox;}
        else {*Mx = l; Mx = &(*Mx)->prox;}
        l = l->prox;
    }
    *mx = NULL; *Mx = NULL;
}

LInt parteAmeio (LInt *l){
    int len = length(*l)/2;
    LInt r = NULL;
    if (len > 0) {
        LInt new = *l; r = new; *l = (*l)->prox;
        for (len--; len > 0; len--) {
            new->prox = *l;
            new = new->prox;
            *l = (*l)->prox;
        }
        new->prox = NULL;
    }
    return r;
}

int main() {
    int a[] = {1,1,3,3};
    int b[] = {1,3};
    printf("%d\n", comunsOrd(a,4,b,2));
    printf("%d\n", comuns(a,4,b,2));
    return 0;
}
