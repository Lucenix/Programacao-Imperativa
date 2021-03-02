/* Aula 18/2 - Programação Imperativa

Bibliografia da Cadeira:  The C Programming Language

Programação Funcional - Qual a relação entre o input e o output?
Programação Imperativa - Como obter o output?
--------------------------------------------------------------------
MEMÓRIA
-armazenamento de informação
-mudança de memória e alteração de memória
    Variáveis: armazenam informação.
        - Nome
        - Tipo (quantos bits usados, long /= float /= double)
            em Haskell  x:: Int
            em C        int x;
--------------------------------------------------------------------
gcc 

 */

#include <stdio.h>

main () 
{
    char a, b, c;
    a = 'A'; b = ' '; c = '0';
    printf ("%c %d\n", a, a);
    a = a+1; c = c+2;
    printf ("%c %d %c %d\n", a, a, c, c);
    c = a + b;
    printf ("%c %d\n", c, c);
}