#include "stdlib.h"

int rangeBitwiseAnd(int left, int right){
    int potenciaLess, potenciaGreat = 2, r = 0;
    while (potenciaGreat <= right)
        potenciaGreat *= 2;
    potenciaLess  = potenciaGreat / 2;
    while (potenciaGreat > right && potenciaLess <= left) {
        r += potenciaLess;
        left -= potenciaLess;
        right -= potenciaLess;
        while((potenciaLess /= 2) > left)
            ;
        potenciaGreat = potenciaLess * 2;
    }
    return r;
}

int main () {
    printf("%d", rangeBitwiseAnd(5,7));
}