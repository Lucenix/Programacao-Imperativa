//
// Created by andre on 18/03/2021.
//

//ordenar arrays

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
    int i,j;
    for (j=N-1;j>0; j--)
        for (i=0; i<j;i++)
            if (v[i]>v[i+1]) swap (v,i,i+1);
}

int main() {

}