#include "string.h"
#include "stdio.h"

//int palindrome(char* s, int a, int b, int n) {
//    int r = b-a-1;
//    for(; a>=0 && b<n && s[a] == s[b]; r+=2, a--, b++);
//    return r;
//}

int manacher(char* s, int* ind) {
    int count = 0;
    *ind = 1;
    int n = strlen(s), flag = 1, i = 0;
    n = 2*n+1;
    //val[i] guarda apenas quantos elementos para a direita é que são palindromicos
    int val[n]; int mirror;
    val[0] = 0, val[1] = 1; i = 2;
    int rBorder = 2;
    while(flag && i<n) {
        //valor do palindrome do char espelho
        mirror = val[2*(*ind) - i];
        //se i = par então val[i] começa a 0; se i = impar então val[i] começa a 1 porque tem #i#
        val[i] = i%2; count++;
        //se i existir na borda, eu sei o valor inicial de val[i] -> menor entre o espelho e o limite da borda
        if(rBorder-i>0) {
            val[i] = mirror < rBorder - i ? mirror : rBorder - i;
            count++;
        }
        //agora a parte importante
        //quando i existe na borda:
        //quero apenas expandir se i+val[i] == rBorder: se for menos ou mais não me interessa
        //se i não existe na borda, tenho de expandir não há volta a dar =>
        //expando se rBorder - i < 0 ou i+val[i] == rBorder
        if(rBorder - i < 0 || i+val[i] == rBorder)
            //testes de expansão
            //1)não pode passar dos limites
            //2)os elementos têm de ser iguais
            //3)incremento val[i] por 2! => sempre que encontro a...i...a também encontro #a...i...a#
            //  para além disso, val[i] fica então com o numero certo do tamanho do palindromo
            for(; i-val[i]>=0 && i+val[i]<n && s[(i-val[i]-1)/2] == s[(i+val[i]+1)/2];val[i]+=2)count++;
        //se val[i] for maior que val[*ind], esse passa a ser o novo ind e é preciso atualizar a borda
        if(val[i]>val[*ind]) {*ind = i; rBorder = *ind + val[*ind];}
        //rBorder chegou ao fim não preciso de ver mais nada
        if(rBorder >= n-1) flag = 0;
        //importante andar ne
        i++;

        /*val[i] = palindrome(s, i-1, i+1, n);
        //if (i + val[i]/2 >= n-1) flag = 0;
        //if(val[i] > val[*ind]){*ind = i; rBorder = *ind + val[*ind]/2;} 
        //i++;
        //while(flag && i <= rBorder) {
        //    
        //    if(i+mirror/2 == rBorder) {
        //        val[i] = palindrome(s, i-mirror/2-1, i+mirror/2+1, n);
        //        if (i + val[i]/2 >= n-1) flag = 0;
        //        if(val[i] >= val[*ind]) {*ind = i; rBorder = *ind + val[*ind]/2;}
        //    } else 
        //        val[i] = mirror < 2*(rBorder - i) + 1 ? mirror : 2*(rBorder - i) + 1;
        //    i++;
        //}
        //printf("ind %d\n", *ind);*/
    }
    for(i = 0; i<n-1; i++)
        printf("%d ", val[i]);
    printf("%d\n", val[i]);
    for(i = (*ind - val[*ind])/2; i<(*ind+val[*ind])/2; i++)
        putchar(s[i]);
    putchar('\n');
    printf("total: %d conta: %d\n", n, count);
    return val[*ind];
}

int main() {
    char s[100];
    int ind, r;
    strcpy(s, "abaxabaxabybaxabyb");
    r = manacher(s,&ind);
    strcpy(s, "babcbabcbaccba");
    r = manacher(s,&ind);
    strcpy(s, "abababa");
    r = manacher(s,&ind);
    strcpy(s, "forgeeksskeegfor");
    r = manacher(s,&ind);
    strcpy(s, "abacdedcaba");
    r = manacher(s,&ind);
    return 0;
}