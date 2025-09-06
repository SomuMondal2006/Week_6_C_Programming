//Reverse first K elements of queue
//https://www.geeksforgeeks.org/problems/reverse-first-k-elements-of-queue/1



#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = 0;
    queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue))
        return -1;
    return queue->array[queue->front];
}

void reverseFirstK(struct Queue* queue, int k) {
    int i, remaining, top;
    int* stack;

    if (k > queue->size) {
        return;
    }

    stack = (int*)malloc(k * sizeof(int));
    top = -1;

    for (i = 0; i < k; i++) {
        stack[++top] = dequeue(queue);
    }

    while (top >= 0) {
        enqueue(queue, stack[top--]);
    }

    remaining = queue->size - k;
    for (i = 0; i < remaining; i++) {
        enqueue(queue, dequeue(queue));
    }

    free(stack);
}

void printQueue(struct Queue* queue) {
    int count = queue->size;
    int index = queue->front;
    int i;

    for (i = 0; i < count; i++) {
        printf("%d ", queue->array[index]);
        index = (index + 1) % queue->capacity;
    }
    printf("\n");
}

int main() {
    int n, k, i, x;
    struct Queue* queue;

    printf("Enter size of queue: ");
    scanf("%d", &n);

    queue = createQueue(n);

    printf("Enter queue elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(queue, x);
    }

    printf("Enter value of k: ");
    scanf("%d", &k);

    reverseFirstK(queue, k);

    printf("Queue after reversing first %d elements:\n", k);
    printQueue(queue);

    return 0;
}

