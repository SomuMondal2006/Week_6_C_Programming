//Implement queue using array
//https://www.geeksforgeeks.org/problems/implement-queue-using-array/1



#include <stdio.h>
#define MAX 100000

int queue[MAX];
int front = 0;
int rear = 0;

void push(int x) {
    if (rear == MAX) {
        return;  
    }
    queue[rear++] = x;
}

int pop() {
    if (front == rear) {
        return -1; 
    }
    return queue[front++];
}

int main() {
    int n, i;  
    scanf("%d", &n);

    for (i = 0; i < n; i++) { 
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(x);
        } 
        else if (type == 2) {
            printf("%d ", pop());
        }
    }

    return 0;
}

