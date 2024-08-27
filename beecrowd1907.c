#include <stdio.h>

#define MAX 1024

int N, M;
char image[MAX][MAX];
int visited[MAX][MAX];

// Directions for moving in the grid (up, down, left, right)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// Queue structure for BFS
typedef struct {
    int x, y;
} Point;

Point queue[MAX * MAX];
int front, rear;

void enqueue(Point p) {
    queue[rear++] = p;
}

Point dequeue() {
    return queue[front++];
}

int is_empty() {
    return front == rear;
}

void bfs(int start_x, int start_y) {
    front = rear = 0;  // Initialize queue
    enqueue((Point){start_x, start_y});
    visited[start_x][start_y] = 1;

    while (!is_empty()) {
        Point p = dequeue();
        int x = p.x;
        int y = p.y;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 0 && nx < N && ny >= 0 && ny < M && image[nx][ny] == '.' && !visited[nx][ny]) {
                enqueue((Point){nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 0; i < N; i++) {
        scanf("%s", image[i]);
    }

    int clicks = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (image[i][j] == '.' && !visited[i][j]) {
                bfs(i, j);
                clicks++;
            }
        }
    }

    printf("%d\n", clicks);
    return 0;
}
