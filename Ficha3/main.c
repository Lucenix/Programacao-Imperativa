#include <stdio.h>
//1a

void printarray(int v[], int N);

void onea () {
    int x [15] = {1, 2, 3, 4, 5,
                  6, 7, 8, 9,10,
                  11,12,13,14,15};
    int *y, *z, i;
    y = x;
    z = x+3;
    for (i=0; i<5; i++) {
        printf ("%d %d %d\n",
                x[i], *y, *z);
        y = y+1; z = z+2;
        //y -> 1, z -> 4
        //1,1,4
        //2,2,6
        //3,3,8
        //4,4,10
        //5,5,12
    }
}

void oneb() {
        int i, j, *a, *b;
        i=3; j=5;
        a = b = 42;
        a = &i; b = &j; //a->i, b->j
        i++; //i==4
        j = i + *b; //j == 4+5 == 9
        b = a; //b->i
        j = j + *b; //j == 4+9 == 13
        printf ("%d\n", j); //13
}

void swapM(int *x, int*y) {
    int z = *x;
    *x = *y;
    *y = z;
}

void swap(int v[], int i, int j) {
    int z = v[i];
    v[i] = v[j];
    v[j] = z;
}

int soma (int v[], int N) {
    int *x = v,
        soma = 0;
    while (N) {
        soma += *x;
        x++;
        N--;
    }
    return soma;
}

void inverteArray1(int v[], int N) {
    for (int i = 0; i<N; i++) {
        swap(v, i, N-1-i);
    }
}

void inverteArray2(int v[], int N) {
    for (int i = 0; i<N; i++){
        swapM(&v[i],&v[N-1-i]);
    }
}

int maximum(int v[], int N, int *m) {
    int result;
    if (N<=0)
        result = -1;
    else {
        int r = v[0];
        for (int i = 1; i<N; i++) {
            if (v[i] > r)
                r = v[i];
        }
        *m = r;
        result = 0;
    }
    return result;
}

void quadrados(int q[], int N) {
    q[0] = 0;
    for (int i = 1; i<N; i++) {
        q[i] = q[i-1] + 2+i + 1;
    }
}

int comb (int a, int b, int *c) {
    if (a==0 || b == 0 || a-b == 0)
        *c = 1;
    else {
        int num = a;
        for (int i = a - 1; i > 0; i--)
            num *= i;
        int dem1 = b;
        for (int i = b - 1; i > 0; i--)
            dem1 *= i;
        int dem2 = a - b;
        for (int i = dem2 - 1; i > 0; i--)
            dem2 *= i;
        int dem = dem1 * dem2;
        *c = num / dem;
        return 0;
    }
}

void pascal (int v[], int N) {

    int i,j;

    for (i = 0; i < N+1; i++) {

        v[i] = 1;

        for (j = 1; j < i; j++) {

            v[i - j] = v[i - j] + v[i - j - 1];
        }
    }

    //for (int i = N-1; i>=0; i--) {
    //    comb(N-1, i, &v[i]);
    //}
    //if (N==1){
    //    v[0] = 1;
    //    printarray(v, N);
    //} else {
    //int prevline[N-1];
    //pascal (prevline, N-1);
    //v[0] = 1;
    //v[N-1] = 1;
    //for (int i = 1; i<N-1; i++)
    //    v[i] = prevline[i] + prevline[i-1];
    //printarray(v, N);
    //}
}


void printarray(int *v, int N) {
    for (int i = 0; i<N; i++)
        printf("%d ", v[i]);
    putchar('\n');
}

int main() {
    //onea();
    //oneb();
    int v[5];
    //comb(5,5,&v[4]);
    //printf("%d", v[4]);
    pascal (v, 3);
    printarray(v, 3);
    return 0;
}
