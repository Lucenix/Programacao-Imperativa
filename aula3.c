#include <stdio.h>


void maxMin(int *x, int *y) {
    int t;
    if (*x<*y) {
        t = *x;
        *x = *y;
        *y = t;
    }
}

//tipos de endereços de memória
int main() {
    int x = 3;
    int y = 4;
        //z;

    maxMin(&x, &y);
    printf("%d %d \n", x, y);

    int *a; //a -> pointer (endereço da variável)
    a = &x; //a passa a ser o pointer de x
    
    (*a)++; //somar um à variável que o pointer aponta therefore x == 4
    

    // &x significa o endereço onde x está guardado
    // *a significa o conteúdo do endereço a

    //z = *a; //z passa a ser == 3+1

    return 0;
}
