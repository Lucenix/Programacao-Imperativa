//
// Created by andre on 18/03/2021.
//

//ordenar arrays

#include <stdio.h>

void swap(int v[], int i, int j) {
    int z = v[i];
    v[i] = v[j];
    v[j] = z;
}

void minOrdenaR (int v[], int N) {
    if (N>1) {
        int m, i;
        if(N>1) {
            m = 0;
            for (i = 1; i<N; i++)
                if (v[i]<v[m]) m = i;
            swap (v,0,m);
            minOrdenaR(v+1, N-1);
        }
    }
}

void minOrdena (int v[], int N) {
    if (N>1) {
        int m, i, j;
        for (j=0; j<N-1; j++) {
            //para cada j, m é o indice do menor elemento posterior
            m=j;
            for (i=j+1; i<N; i++) {
                if (v[i]<v[j]) m = i;
            }
            swap(v, j, m);
        }
    }
}

void selSort (int v[],int N) {
    int i, j;

    for (j = 0; j<N-1; j++)
        for (i=j+1; i<N; i++)
            if(v[i]<v[j])
                swap(v,i,j);
}

void bubbleSort (int v[], int N) {
    int i,j, ord=0;
    for (j=N-1;j>0; j--) {
        for (i=0; i<j; i++)
            if (v[i]>v[i+1]) {swap (v,i,i+1); ord = i;}
        j=ord+1;
    }
}

void insere (int v[], int N, int x) {
    int j;
    for (j = N-1; j>=0 && v[j] > x; j--) {
        v[j+1] = v[j];
    }
    v[j] = x;
}

void insSort(int v[], int N) {
    int i=0;
    while (i<N) {
        insere (v,i,v[i]);
        i++;
    }
}

void merge(int a[], int na, int b[], int nb, int v[]) {
    int i=0, j=0;
    while (i<na && j<nb) {
        if (a[i] < b[j]) v[i+j] = a[i++];
        else v[i+j] = b[j++];
    }
    while (i<na) {
        v[i+j] = a[i++];
    }
    while (j<nb) {
        v[i+j] = b[j++];
    }
}

void mergeSort(int v[], int N) {
    int m, i;
    int aux[N];
    if (N>1) {
        m = N/2;
        mergeSort(v, m);
        mergeSort(v+m,N-m);
        merge(v,m,v+m, N-m, aux);
        for (i = 0; i<N; i++) v[i] = aux[i];
    }
}

int partition(int v[],int N) {
    int r, i;
    for (i = r = 0; i < N-1; i++)
        if (v[i] <= v[N-1])
            swap(v, r++, i);
    swap(v, r, N-1);
    return r;
}

void qSort(int v[], int N) {
    int p;
    if (N>1) {
        p = partition(v,N);
        qSort(v,p);
        qSort(v+p+1,N-p-1);
    }
}

int main() {
    int v[10] = {3,4,1,2,8,0,7,5,5,4};
    qSort(v,10);
    for (int i = 0; i<10;i++)
        printf("%d ", v[i]);
}