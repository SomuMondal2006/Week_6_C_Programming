//Hackerrank: Queue using two stacks
//https://www.hackerrank.com/challenges/queue-using-two-stacks/problem



#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    long long arr[MAX];
    int top;
} Stack;

void init(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, long long value) {
    s->arr[++(s->top)] = value;
}

long long pop(Stack *s) {
    return s->arr[(s->top)--];
}

long long peek(Stack *s) {
    return s->arr[s->top];
}

int main() {
    int q;
    scanf("%d", &q);

    Stack s1, s2;
    init(&s1);
    init(&s2);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            long long x;
            scanf("%lld", &x);
            push(&s1, x);
        } 
        else if (type == 2) {
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            if (!isEmpty(&s2)) {
                pop(&s2);
            }
        } 
        else if (type == 3) {
            if (isEmpty(&s2)) {
                while (!isEmpty(&s1)) {
                    push(&s2, pop(&s1));
                }
            }
            printf("%lld\n", peek(&s2));
        }
    }

    return 0;
}

