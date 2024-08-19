#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
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
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int kruskalMST(Edge edges[], int M, int N) {
    qsort(edges, N, sizeof(Edge), compareEdges);
    int* parent = malloc(M * sizeof(int));
    int* rank = malloc(M * sizeof(int));
    for (int i = 0; i < M; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    int mstWeight = 0;
    for (int i = 0, e = 0; e < M - 1 && i < N; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int setU = find(parent, u);
        int setV = find(parent, v);
        if (setU != setV) {
            mstWeight += edges[i].weight;
            unionSets(parent, rank, setU, setV);
            e++;
        }
    }
    free(parent);
    free(rank);
    return mstWeight;
}

int main() {
    int M, N;
    while (scanf("%d %d", &M, &N), M && N) {
        Edge* edges = malloc(N * sizeof(Edge));
        for (int i = 0; i < N; i++)
            scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        printf("%d\n", kruskalMST(edges, M, N));
        free(edges);
    }
    return 0;
}
