#include <stdlib.h>
#include <stdio.h>

typedef struct linkedList {
    int val;
    struct linkedList *next;
}*LList;

void reverse(LList *l) {
    LList next = NULL, prev = NULL, current = *l;
    while (current != NULL)
    {
        prev = current->next;
        current->next = next;
        next = current;
        current = prev;
    }
    *l = next;
}

void push(LList *l, int data) {
    LList new = malloc(sizeof(LList));
    new->next = *l;
    new->val = data;
    *l = new;
}

void printList(LList head)
{
    while (head) {
        printf("%d  ", head->val);
        head = head->next;
    }
}

int main() {
    LList l1 = NULL;
    push(&l1, 4);
    push(&l1, 5);
    push(&l1, 6);
    push(&l1, 7);
    printList(l1);
    putchar('\n');
    reverse(&l1);
    printList(l1);
    return 0;
}