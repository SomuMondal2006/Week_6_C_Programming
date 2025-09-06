//First non-repeating character stream
//https://www.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/1



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100005  

struct Queue {
    int front, rear, size;
    char arr[MAX];
};

void initQueue(struct Queue *q) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(struct Queue *q) {
    return q->size == 0;
}

void enqueue(struct Queue *q, char ch) {
    q->rear++;
    q->arr[q->rear] = ch;
    q->size++;
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) return;
    q->front++;
    q->size--;
}

char front(struct Queue *q) {
    return q->arr[q->front];
}

void firstNonRepeating(char *s) {
    int n, i, idx, chIndex;
    int freq[26] = {0};
    struct Queue q;
    char result[MAX];
    char ch;

    n = strlen(s);
    initQueue(&q);
    idx = 0;

    for (i = 0; i < n; i++) {
        ch = s[i];
        chIndex = ch - 'a';
        freq[chIndex]++;

        enqueue(&q, ch);

        while (!isEmpty(&q) && freq[front(&q) - 'a'] > 1) {
            dequeue(&q);
        }

        if (!isEmpty(&q))
            result[idx++] = front(&q);
        else
            result[idx++] = '#';
    }

    result[idx] = '\0';
    printf("%s\n", result);
}

int main() {
    char s[MAX];

    printf("Enter the input string: ");
    scanf("%s", s);

    printf("Output: ");
    firstNonRepeating(s);

    return 0;
}

