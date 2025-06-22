#ifndef UTILS_H
#define UTILS_H

#define MAX_NODES 100
#define INF 100000

void create_matrix(int n, int matrix[n][n], int value);

void create_matrix_file(char *name, int n, char alghorithm[20], int matrix[n][n]);

int matrix_length(char *name);

void insert_edge(int n, int matrix[n][n], int u, int v, int w);

void print_matrix(int n, int matrix[n][n]);

void kruskal(int n, int adjacendy_matrix[n][n], int mst[n][n]);

void prim(int n, int adjacendy_matrix[n][n], int mst[n][n]);

void dijkstra(int n, int source, int matrix[n][n], int route[n]);

#endif
