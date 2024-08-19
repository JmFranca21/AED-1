#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, cost;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return parent[i] = find(parent, parent[i]); // Path compression
}

void unionSets(int parent[], int rank[], int u, int v) {
    int rootU = find(parent, u);
    int rootV = find(parent, v);
    if (rank[rootU] < rank[rootV])
        parent[rootU] = rootV;
    else if (rank[rootU] > rank[rootV])
        parent[rootV] = rootU;
    else {
        parent[rootV] = rootU;
        rank[rootU]++;
    }
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->cost - ((Edge*)b)->cost;
}

int kruskalMST(Edge edges[], int R, int C) {
    qsort(edges, C, sizeof(Edge), compareEdges);
    
    int* parent = malloc((R + 1) * sizeof(int));
    int* rank = malloc((R + 1) * sizeof(int));
    for (int i = 1; i <= R; i++) {
        parent[i] = i;
        rank[i] = 0;
    }

    int mstCost = 0;
    for (int i = 0, e = 0; e < R - 1 && i < C; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            mstCost += edges[i].cost;
            unionSets(parent, rank, setU, setV);
            e++;
        }
    }

    free(parent);
    free(rank);
    return mstCost;
}

int main() {
    int R, C;
    scanf("%d %d", &R, &C);
    
    Edge* edges = malloc(C * sizeof(Edge));
    for (int i = 0; i < C; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].cost);
    }

    int result = kruskalMST(edges, R, C);
    printf("%d\n", result);
    
    free(edges);
    return 0;
}
