#include <stdio.h>
#include "alghorithm.h"

void create_matrix(int n, int matrix[n][n], int value){
	for (int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++) matrix[i][j] = value;
	}
}

void insert_edge(int n, int matrix[n][n], int u, int v, int w){
	matrix [u][v] = matrix [v][u] = w;
}

void print_matrix(int n, int matrix[n][n]){
	for (int i = 0; i < n; i++){
		for(int j = 0 ; j < n; j++){
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
}

void kruskal(int n, int adjacendy_matrix[n][n], int mst[n][n]){
	create_matrix(n, mst, 0);
	int belong_nodes[n];

	for(int i = 0; i < n; i++){
		belong_nodes[i] = i;
	}

	//reference nodes
	int nodeA;
	int nodeB;
	//the total of edges is equal to total_nodes - 1;
	int edges = 0;

	while (edges < n - 1){
		printf("total edges; %d \n", edges);
		int min = INF;
		for (int i = 0; i < n ; i++ ){
			for (int j = i + 1; j < n; j++ ){
				if ( min > adjacendy_matrix[i][j] && adjacendy_matrix[i][j] && belong_nodes[i] != belong_nodes[j]){
					min = adjacendy_matrix[i][j];
					nodeA = i;
					nodeB = j;
				}
			}
		}
		// add to MST if the nodes dont belong same tree
		if(belong_nodes[nodeA] != belong_nodes[nodeB]){
			insert_edge(n,mst, nodeA, nodeB, min);
			print_matrix(n, mst);
			//add all nodes from nodeB to nodeA
			int temp = belong_nodes[nodeB];
			belong_nodes[nodeB] = belong_nodes[nodeA];
			for (int i = 0 ; i < n; i++) if (temp == belong_nodes[i]) belong_nodes[i] = belong_nodes[nodeA];
			edges++;
		}
	}
}

void prim(int n, int adjacendy_matrix[n][n], int mst[n][n]){
	create_matrix(n, mst, 0);
	int belong_nodes[n];
	belong_nodes[0] = 1;
	for(int i = 1; i < n; i++){
		belong_nodes[i] = 0;
	}

	//reference nodes
	int nodeA;
	int nodeB;
	//the total of edges is equal to total_nodes - 1
	int edges = 0;

	while (edges < n - 1){
		printf("total edges; %d \n", edges);
		int min = INF;
		for (int i = 0; i < n ; i++ ){
			if(belong_nodes[i]){
				for (int j = 0; j < n; j++ ){
					if ( min > adjacendy_matrix[i][j] && adjacendy_matrix[i][j] && !belong_nodes[j]){
						min = adjacendy_matrix[i][j];
						nodeA = i;
						nodeB = j;
					}
				}
			}
		}
		// add new node to mst
		insert_edge(n,mst, nodeA, nodeB, min);
		print_matrix(n, mst);
		//check the node added
		belong_nodes[nodeB] = 1;
		edges++;
	}
}

void dijkstra(int n, int source, int matrix[n][n], int route[n]){
	int flag[n];
	int min, pos_min;
	for (int i = 0; i < n; i++){
		flag[i] = 0;
		route[i] = matrix[source][i];
	}

	route[source] = 0;

	for(int i = 1; i < n; i++){
		min = INF;
		for(int j = 0; j < n; j++){
			if((route[j] < min) && !flag[j]){
				min = route[j];
				pos_min = j;
			}
		}

		flag[pos_min] = 1;
		for(int j = 0; j < n; j++){
			if(((route[pos_min] + matrix[pos_min][j]) < route[j]) && flag[j] != 1)
				route[j] = route[pos_min] + matrix[pos_min][j];
		}
	}
}
