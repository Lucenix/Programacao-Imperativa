#include <stdio.h>
#include <assert.h>

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

int main() {
    return 0;
}
