//Interleave halves of queue
//https://www.geeksforgeeks.org/problems/interleave-the-first-half-of-the-queue-with-second-half/1



#include <stdio.h>

void interleaveQueue(int q[], int n) {
    int i, j = 0, k = 0;
    int mid = n / 2;

    int result[n];
    int first[mid];

    for (i = 0; i < mid; i++) {
        first[i] = q[i];
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            result[i] = first[j++];
        } else {
            result[i] = q[mid + k];
            k++;
        }
    }

    for (i = 0; i < n; i++) {
        q[i] = result[i];
    }
}

int main() {
    int n, i;

    printf("Enter size of queue (even number): ");
    scanf("%d", &n);

    if (n % 2 != 0) {
        printf("Queue size must be even!\n");
        return 0;
    }

    int q[n];

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    interleaveQueue(q, n);

    printf("Queue after interleaving:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", q[i]);
    }
    printf("\n");

    return 0;
}

