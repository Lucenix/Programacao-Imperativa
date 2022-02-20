#include "string.h"
#include "stdio.h"

char * convert(char * s, int numRows){
    if (numRows == 1)
        return s;
    int len = strlen(s);
    char *start = malloc(sizeof(char) * len + 1);
    int i, x1, x2, r, w = 0;
    
    for (i = 0; numRows > 1 && i<numRows; i++) {
        r = i;
        int flag = 1;
        for (x1 = 2*(numRows - i - 1), x2 = 2*i; r < len && w < len; flag = !flag) {
            if (x1 && flag) {
                start[w++] = s[r];
                r += x1;
            } else if (x2 && !flag) {
                start[w++] = s[r];
                r += x2;
            }
        }
    }
    start[len] = '\0';
    return start;
}

int main () {
    char *s = "A";
    s = convert(s, 1);
    printf("%s", s);
    return 0;
}