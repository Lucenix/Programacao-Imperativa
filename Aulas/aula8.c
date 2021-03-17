//
// Created by andre on 16/03/2021.
//

#include <stdio.h>

int elem(int x, int v[], int N) {
    int max = N - 1, min = 0, i, r = -1;
    while (r == -1 && min <= max) {
        i = (max + min) / 2;
        if (v[i] == x) r = i;
        if (v[i] < x)
            min = i + 1;
        else
            max = i - 1;
    }
    return r;
    //int r=-1;
    //for (int i = 0; i<N && r==-1; i++) {
    //    if(v[i] == x)
    //        r = i;   //break
    //    if(v[i]>x)
    //        i = N-1; //break
    //}
    //return r;
}

int main () {
    int v[] = {1,2,3,4,6,7,8,9};
    printf("%d", elem(5,v,9));
    return 0;
}