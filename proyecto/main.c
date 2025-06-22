#include <stdio.h>
#include <stdlib.h>
#include "alghorithm.h"

void print_shortest_path(int n, int array[n],int source){
	for(int i = 0; i < n; i++){
		printf("%d  -> %d  cost: %d\n", source, i, array[i]);
	}
}

int main(){
	int n = 5;
	int matrix[n][n], mst[n][n];
	/*create_matrix(n, matrix, 0);
	insert_edge(n, matrix, 0, 1, 2);
	insert_edge(n, matrix, 0, 4, 4);
	insert_edge(n, matrix, 1, 2, 6);
	insert_edge(n, matrix, 1, 4, 3);
	insert_edge(n, matrix, 2, 3, 7);
	insert_edge(n, matrix, 2, 4, 5);
	insert_edge(n, matrix, 3, 4, 1);
	printf("-------GRAPH------\n");
	print_matrix(n, matrix);
	kruskal(n, matrix, mst);
	printf("-------MST   Kruskal------\n");
	print_matrix(n, mst);
	prim(n, matrix, mst);
	printf("-------MST   Prim------\n");
	print_matrix(n, mst);
	int source = 1;
	int route[n];
	create_matrix(n, matrix, INF);
	insert_edge(n, matrix, 0, 1, 2);
	insert_edge(n, matrix, 0, 4, 4);
	insert_edge(n, matrix, 1, 2, 6);
	insert_edge(n, matrix, 1, 4, 3);
	insert_edge(n, matrix, 2, 3, 7);
	insert_edge(n, matrix, 2, 4, 5);
	insert_edge(n, matrix, 3, 4, 1);
	printf("-------List of shortest paths from %d------\n", source);
	dijkstra(n, source, matrix, route);
	print_shortest_path(n, route, source);*/
	char *name = "matrix1.txt";
	printf("length: %d\n",  matrix_length(name));
	create_matrix_file(name);
}
