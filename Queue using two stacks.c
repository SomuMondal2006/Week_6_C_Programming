//Queue using two stacks
//https://www.geeksforgeeks.org/problems/queue-using-two-stacks/1



#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Stack {
    int arr[MAX];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

int isEmpty(struct Stack *s) {
    return s->top == -1;
}

int isFull(struct Stack *s) {
    return s->top == MAX - 1;
}

void pushStack(struct Stack *s, int data) {
    if (isFull(s)) {
        printf("Stack Overflow\n");
        return;
    }
    s->arr[++s->top] = data;
}

int popStack(struct Stack *s) {
    if (isEmpty(s)) {
        return -1;
    }
    return s->arr[s->top--];
}

struct Queue {
    struct Stack s1, s2;
};

void initQueue(struct Queue *q) {
    initStack(&q->s1);
    initStack(&q->s2);
}

void enqueue(struct Queue *q, int data) {
    pushStack(&q->s1, data);
}

int dequeue(struct Queue *q) {
    int data;

    if (isEmpty(&q->s2)) {
        while (!isEmpty(&q->s1)) {
            pushStack(&q->s2, popStack(&q->s1));
        }
    }

    data = popStack(&q->s2);

    return data;
}

int main() {
    struct Queue q;
    int numQueries;
    int i;
    int type, x, val;

    initQueue(&q);

    printf("Enter number of queries: ");
    scanf("%d", &numQueries);

    printf("Enter queries:\n");
    for (i = 0; i < numQueries; i++) {
        scanf("%d", &type);

        if (type == 1) {
            scanf("%d", &x);
            enqueue(&q, x);
        } 
        else if (type == 2) {
            val = dequeue(&q);
            printf("%d ", val);
        }
    }

    return 0;
}

