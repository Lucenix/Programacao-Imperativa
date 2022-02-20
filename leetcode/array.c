#include <stdio.h>

int canThreePartsEqualSum(int* arr, int arrSize){
    if (arrSize >= 3) {
        int i = 0, j = 2;
        int soma1 = arr[i], soma2 = arr[i+1], soma3 = 0;
        for (; j<arrSize; j++)
            soma3+=arr[j];
        if ((soma1 == soma2) && soma1 == soma3)
                return 1;
        printf("%d, %d, %d \n", soma1, soma2, soma3);
        for (j=2; j<arrSize;) {
                if (arr[j] > 0) {
                    if (soma1 < soma2 && arr[i+1] > 0) {
                        i++;
                        soma1 += arr[i];
                        soma2 -= arr[i];                        
                    } else {
                        soma2 += arr[j];
                        soma3 -= arr[j];
                        j++;
                    }
                } else {
                    if (soma1 > soma2 && arr[i+1] < 0) {
                        i++;
                        soma1 += arr[i];
                        soma2 -= arr[i]; 
                    } else {
                        soma2 += arr[j];
                        soma3 -= arr[j];
                        j++;
                    }
                }
                if (i + 1 >= j) {
                    soma2 += arr[j];
                    soma3 -= arr[j];
                    j++;    
                }
            if ((soma1 == soma2) && soma1 == soma3) {
                return 1;
            }
            printf("%d, %d, %d \n", soma1, soma2, soma3);
        }   
    } 
    return 0;
}

int main() {
    int array[] = {18,12,-18,18,-19,-1,10,10};
    printf("%d", canThreePartsEqualSum(array, 8));
}