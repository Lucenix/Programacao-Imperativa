#include <stdio.h>
//o endereço passado é do início do array aka não sabe o tamanho do array
//um array passado como argumento é passado como endereço e não como uma cópia
void copiaArray(int destino[], int origem[], int N) {
    for (int i = 0; i<N; i++) 
        destino[i] = origem[i];
        //os arrays que entram são literalmente os arrays originais e não cópias
}

int main() {
    //sempre que um array é DECLARADO tem de ter tamanho ou tamanho inferido
    int y [] = {1,2,3,4,5,6,7,8,9,10},
        z [5] = {1,2,3,4,5,6,7,8,9,10}, //isto cria um array de tamanho 5 com os que conseguir lá meter {1,2,3,4,5}
        b [10],
        a = 42,
        *p;
    //vetores e matrizes
    //os arrays são endereços de memória - ENDEREÇO DA SUA PRIMEIRA COMPONENTE
    //impossível igual arrays b = y
    for (int i = 0; i<10; i++) {
        y[i] = i+1;
    }
    //p = a; //o p vai guardar o valor 42 mas não não faz sentido ter como endereço
    //p = &a; //o p vai guardar o endereço do a
    p = b; //o p vai ter como endereço a primeira componente de b aka p vai ser b

    copiaArray(b, y, 10);
    //for (int i = 0; i<10; i++)
    //    printf(p[i]); não faço ideia como fazer isso
    return 0;
}
