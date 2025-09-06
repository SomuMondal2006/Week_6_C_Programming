//Implement queue using linked list
//https://www.geeksforgeeks.org/problems/implement-queue-using-linked-list/1



#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initQueue(struct Queue* q) {
    q->front = q->rear = NULL;
}

void push(struct Queue* q, int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (q->rear == NULL) {
        q->front = q->rear = newNode;
        return;
    }

    q->rear->next = newNode;
    q->rear = newNode;
}

int pop(struct Queue* q) {
    if (q->front == NULL) {
        return -1; 
    }

    struct Node* temp = q->front;
    int val = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL; 
    }

    free(temp);
    return val;
}

int main() {
    struct Queue q;
    initQueue(&q);

    int Q;
    scanf("%d", &Q);

    int i; 

    for (i = 0; i < Q; i++) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&q, x);
        } 
        else if (type == 2) {
            printf("%d ", pop(&q));
        }
    }

    return 0;
}

