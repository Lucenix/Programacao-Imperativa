//
// Created by andre on 14/04/2021.
//
#include <stdio.h>
#include <string.h>
#include "math.h"

typedef struct aluno {
    int numero;
    char nome[100];
    int miniT [6];
    float teste;
} Aluno;

int nota (Aluno a){
    return 0;
}

void imprimeAluno (Aluno *a){
    int i;
    printf ("%-5d %s (%d", a->numero, a->nome, a->miniT[0]);
    for(i=1; i<6; i++) printf (", %d", a->miniT[i]);
    printf (") %5.2f %d\n", a->teste, nota(*a));
}

int note (Aluno a) {
    int r = 0;
    if (a.teste >= 8) {
        double somaMiniT = 0;
        for (int i = 0; i<6; i++) {
            somaMiniT += a.miniT[i];
        }
        somaMiniT = (somaMiniT*20)/12;
        if (somaMiniT >= 8) {
            r = ceil(somaMiniT * 0.3 + a.teste * 0.7);
        }
    }
    return r;
}

int procuraNum (int num, Aluno t[], int N) {
    int i, r = -1;
    for (i = 0; i < N && t[i].numero < num; i++);
    if (i<N && t[i].numero == num) r = i;
    return r;
}

int partition(Aluno t[], int N) {
    int i, x;
    for (i = x = 0; i<N-1; i++) {
        if (t[i].numero<=t[N-1].numero) {
            Aluno temp = t[x];
            t[x++] = t[i];
            t[i] = temp;
        }
    }
    Aluno temp = t[x];
    t[x] = t[i];
    t[i] = temp;
    return x;
}

void ordenaPorNum (Aluno t[], int N) {
    int p;
    if (N>1) {
        p = partition(t, N);
        ordenaPorNum(t,p);
        ordenaPorNum(t+p+1,N-p-1);
    }
}

void merge(Aluno t1[], int N1, Aluno t2[], int N2, Aluno r[]) {
    int i = 0, j = 0;
    while (i<N1 && j < N2) {
        if (t1[i].numero<t2[j].numero)r[i+j] = t1[i++];
        else r[i+j] = t2[j++];
    }
    while (i<N1)
        r[i+j] = t1[i++];
    while (j<N2)
        r[i+j] = t2[j++];
}

void ordenaPorNumMerge(Aluno t[], int N) {
    int m, i;
    Aluno r[N];
    if (N>1) {
        m = N/2;
        ordenaPorNumMerge(t, m);
        ordenaPorNumMerge(t+m, N-m);
        merge(t, m, t+m, N-m, r);
        for (i = 0; i<N; t[i] = r[i++]);
    }
}

int partitionInd(Aluno t[], int N, int ind[]) {
    int i, x;
    for (i = x = 0; i<N-1; i++) {
        //cuidado, tem de se verificar o ind[i] e não o no local do i ou se não nada muda
        if (t[ind[i]].numero<=t[ind[N-1]].numero) {
            int temp = ind[x];
            ind[x++] = ind[i];
            ind[i] = temp;
        }
    }
    int temp = ind[x];
    ind[x] = ind[i];
    ind[i] = temp;
    return x;
}

void criaIndPorNum (Aluno t[], int N, int ind[]) {
    int p;
    if (N>1) {
        //o t tem de se manter inteiro porque os seus elementos não se alteram
        p = partitionInd(t, N, ind);
        criaIndPorNum(t, p, ind);
        criaIndPorNum(t, N-p-1, ind+p+1);
    }
}

void imprimeTurmaInd(int ind[], Aluno t[], int N) {
    for (int i = 0; i<N; i++) {
        imprimeAluno(t+ind[i]);
    }
}

int procuraNumInd (int num, int ind[], Aluno t[], int N) {
    int i, r = -1;
    for (i = 0; i < N && t[ind[i]].numero < num; i++);
    if (i < N && t[ind[i]].numero == num) r = i;
    return r;
}

int partitionIndNome(Aluno t[], int N, int ind[]) {
    int i, x;
    for (i = x = 0; i<N; i++) {
        if(strcmp(t[ind[i]].nome, t[ind[x]].nome) <= 0) {
            int temp = ind[x];
            ind[x++] = ind[i];
            ind[i] = temp;
        }
    }
    int temp = ind[x];
    ind[x] = ind[i];
    ind[i] = temp;
    return x;
}

void criaIndPorNome(Aluno t[], int N, int ind[]) {
    int p;
    if (N>1) {
        //o t tem de se manter inteiro porque os seus elementos não se alteram
        p = partitionIndNome(t, N, ind);
        criaIndPorNome(t, p, ind);
        criaIndPorNome(t, N-p-1, ind+p+1);
    }
}

int main() {
    Aluno Turma1 [7] = {{4444, "André", {2,1,0,2,2,2}, 10.5}
            ,{3333, "Paulo", {0,0,2,2,2,1},  8.7}
            ,{8888, "Carla", {2,1,2,1,0,1}, 14.5}
            ,{2222, "Joana", {2,0,2,1,0,2},  3.5}
            ,{7777, "Maria", {2,2,2,2,2,1},  5.5}
            ,{6666, "Bruna", {2,2,2,1,0,0}, 12.5}
            ,{5555, "Diogo", {2,2,1,1,1,0},  8.5}
    } ;
    int indNome [7], indNum [7] = {0,1,2,3,4,5,6};
    int i;

    printf ("\n-------------- Testes --------------\n");

    //ordenaPorNum (Turma1, 7);

    // printf ("procura 5555: %d \n", procuraNum (5555, Turma1, 7));
    // printf ("procura 9999:%d \n", procuraNum (9999, Turma1, 7));

    //for (i=0; i<7; imprimeAluno (Turma1 + i++));

    criaIndPorNum (Turma1, 7, indNum);

    for(i=0;i<7; printf("%d ", indNum[i++]));
    putchar('\n');
    // criaIndPorNome (Turma1, 7, indNome);

    imprimeTurmaInd (indNum, Turma1, 7);
    // imprimeTurmaInd (indNome, Turma1, 7);

    // printf ("procura 5555:%d \n",  procuraNumInd (5555, indNum, Turma1, 7));
    // printf ("procura 9999:%d \n",  procuraNumInd (9999, indNum, Turma1, 7));

    printf ("\n---------- Fim dos Testes ----------\n");

    return 0;
}