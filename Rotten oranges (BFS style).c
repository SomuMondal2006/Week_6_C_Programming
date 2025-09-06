//Rotten oranges (BFS style)
//https://www.geeksforgeeks.org/problems/rotten-oranges2536/1



#include <stdio.h>
#include <stdlib.h>

#define MAX 500

typedef struct {
    int x, y, time;
} Node;

typedef struct {
    Node arr[MAX * MAX];
    int front, rear;
} Queue;

void initQueue(Queue *q) {
    q->front = q->rear = 0;
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

void enqueue(Queue *q, int x, int y, int time) {
    q->arr[q->rear].x = x;
    q->arr[q->rear].y = y;
    q->arr[q->rear].time = time;
    q->rear++;
}

Node dequeue(Queue *q) {
    return q->arr[q->front++];
}

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int minTimeToRotAllOranges(int mat[MAX][MAX], int n, int m) {
    Queue q;
    initQueue(&q);

    int fresh = 0, time = 0, rotten = 0;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if (mat[i][j] == 2) {
                enqueue(&q, i, j, 0);
            } else if (mat[i][j] == 1) {
                fresh++;
            }
        }
    }

    if (fresh == 0)
        return 0;

    while (!isEmpty(&q)) {
        Node curr = dequeue(&q);
        time = curr.time;

        for (i = 0; i < 4; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && mat[nx][ny] == 1) {
                mat[nx][ny] = 2;
                enqueue(&q, nx, ny, curr.time + 1);
                rotten++;
            }
        }
    }

    return (rotten == fresh) ? time : -1;
}

int main() {
    int n, m;
    int mat[MAX][MAX];
    int i, j;

    printf("Enter number of rows: ");
    scanf("%d", &n);

    printf("Enter number of columns: ");
    scanf("%d", &m);

    printf("Enter matrix values (0, 1, 2):\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int result = minTimeToRotAllOranges(mat, n, m);
    printf("Minimum time to rot all oranges: %d\n", result);

    return 0;
}

