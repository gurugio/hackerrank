#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


/* int graph[11] = {0, 0, 1, 1, 3, 2, 1, 2, 6, 8, 8}; */
/* int visit[11] = {0,}; */
/* int tmpvisit[11] = {0,}; */

int *graph;
int *visit;
int *tmpvisit;
int num_node;
int num_edge;
int remove_edge;

int get_leaf(int root)
{
	int i;
	int ret = 0;

	for (i = 1; i <= num_node; i++) {
		if (i != root && graph[i] == root)
			ret += get_leaf(i);
	}
	return ret + 1;
}

void find_eventree(int current)
{
	int i;
	
	if (visit[current] == 0) {
		visit[current] = 1;
	}

	for (i = 1; i <= num_node ; i++) {
		if (i != current && graph[i] == current) {
			if ((get_leaf(i) % 2) == 0)
				remove_edge++;//graph[i] = 0;
			find_eventree(i);
		}
	}
}
	
int main()
{
	int i;

	scanf("%d %d", &num_node, &num_edge);
	
	graph = calloc(num_node + 1, sizeof(int));
	visit = calloc(num_node + 1, sizeof(int));

	for (i = 2; i <= num_node; i++) {
		int index;
		int go;
		scanf("%d %d", &index, &go);
		graph[index] = go;
	}

	find_eventree(1);
	printf("%d\n", remove_edge);

	/* for (i = 1; i < num_node; i++) */
	/* 	printf("%d\n", get_leaf(1)); */

	free(graph);
	free(visit);

	return 0;
}
