#include "stdio.h"

void swap(int v[], int i, int j) {
    int z = v[i];
    v[i] = v[j];
    v[j] = z;
}

void bubbleSort (int v[], int N) {
    int i,j, ord=0, r = 0;
    for (j=N-1;j>0; j--) {
        for (i=0; i<j; i++)
            if (v[i]>v[i+1]) {swap (v,i,i+1); ord = i; r++;}
        j=ord+1;
    }
    printf("%d\n", r);
}

int sumhtpo (int n){
    int r = 0, w = 0;
    int arr[10000];

    while (n != 1) {
        arr[w++] = n;
        r += n;
        if (n%2 == 0) n = n/2;
        else n = 1+(3*n);
    }
    bubbleSort(arr, w);
    printf("%d\n", arr[w-20]);
    printf("%d\n", arr[w-2]);
    printf("%d\n", arr[w-1]);
    return r;
}

int main () {
    sumhtpo(6);
    printf("\n");
    sumhtpo(97);
    return 0;
}