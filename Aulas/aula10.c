#include <malloc.h>

typedef struct stack {
    int sp;
    int matriz[100];
}Stack;

Stack *CreateStack() {
    Stack *s;
    s = (Stack *) malloc(sizeof(Stack));
    s->sp = -1;
    return s;
}

int main() {
    Stack *s = CreateStack();
    return 0;
}