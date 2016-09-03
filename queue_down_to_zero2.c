#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int findmin(int *q, int c)
{
	int min = 0xffffff;
	int i;

	for (i = 0; i < c; i++) {
		if (q[i] < min)
			min = q[i];
	}

	return min;
}

int go2zero(int num)
{
	int i;
	int *queue;
	int qindex = 0;
	int ret;

	if (num == 1)
		return 1;

	queue = calloc(10000, sizeof(int));

	for (i = 2; i <= (int)sqrt(num); i++) {
		if ((num % i) == 0) {
			printf("[%d]enq=%d\n", num, (int)num/i);
			queue[qindex++] = (int)num/i;
		}
	}

	if (qindex == 0) {
		queue[qindex++] = num - 1;
		printf("[%d]enq=%d\n", num, num-1);
	}

	for (i = 0; i < qindex; i++) {
		int o = queue[i];
		queue[i] = go2zero(queue[i]);
		printf("[%d]%d %d\n", num, o, queue[i]);
       	}

	// add free q
	ret = findmin(queue, qindex) + 1;
	free(queue);
	return ret;
}
int main(void)
{
	int count, num;
	int i;

	/* scanf("%d", &count); */

	/* for (; count > 0; count--) { */
	/* 	scanf("%d", &num); */
	/* 	printf("%d\n", go2zero(num)); */
	/* } */

	printf("->%d\n", go2zero(3));
	printf("->%d\n", go2zero(4));
	printf("->%d\n", go2zero(5));
	printf("->%d\n", go2zero(7));

	printf("->%d\n", go2zero(70));
	printf("->%d\n", go2zero(7273));
	//printf("->%d\n", go2zero(225604));


	/* } */
	return 0;
}
