#include <stdio.h>
#include <stdlib.h>

#define NODE_SIZE 8

int graph[NODE_SIZE][NODE_SIZE] = {
	{0,1,1,1,0,0,0,0},
	{1,0,1,0,0,0,0,0},
	{1,1,0,1,1,0,0,0},
	{1,0,1,0,0,1,1,0},
	{0,0,1,0,0,0,0,0},
	{0,0,0,1,0,0,1,1},
	{0,0,0,1,0,1,0,0},
	{0,0,0,0,0,1,0,0}
};

int visit[NODE_SIZE] = {0,};


void bfs(int start)
{
	int queue[30];
	int rear = 0, tail = 0;
	int cur;
	int i;

	queue[tail++] = start;
	visit[start] = 1;
	printf("visit=%d\n", start);

	while (rear != tail) {
		cur = queue[rear++];
		for (i = cur + 1; i < NODE_SIZE; i++) {
			if (graph[cur][i] == 1 && visit[i] == 0) {
				queue[tail++] = i;
				visit[i] = 1;
				printf("visit=%d\n", i);
			}
		}
	}
}

int main(void)
{
	bfs(0);
	return 0;
}
