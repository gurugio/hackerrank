#include <stdio.h>
#include <stdlib.h>

#define lchild(i) (2*(i) + 1)
#define rchild(i) (2*(i) + 2)

long heap[1000000];
int heap_index;

int parent(int i)
{
	return (i <= 0) ? -1 : ((int)(((i) - 1)/2));
}

void swap(long *array, int a, int b)
{
	long t = array[a];
	array[a] = array[b];
	array[b] = t;
}

void heap_push(long *array, long val)
{
	int p;
	int cur;

	/* printf("insert=%ld\n", val); */
	array[heap_index++] = val;

	cur = heap_index - 1;
	while (1) {
		int t;
		
		p = parent(cur);
		if (p < 0 || array[p] <= array[cur])
			break;

		swap(array, cur, p);
		cur = p;
	}

#ifdef DEBUG
		int i;
		printf("after push<%ld>\n", val);
		for (i = 0; i < heap_index; i++)
			printf("<%d>%ld ", i, heap[i]);
		printf("\n");
#endif
}

long heap_pop(long *array)
{
	int l, r;
	int next;
	long ret = array[0];
	int p;

	if (heap_index == 0)
		return -1;
	
	heap_index--;
	array[0] = array[heap_index];

	next = 0;
	l = r = 0;
	while (next < heap_index) {
		p = next;
		l = lchild(p);
		r = rchild(p);

#ifdef DEBUG
		printf("p=%d l=%d r=%d heap_index=%d\n", p, l, r, heap_index);
#endif

		if (l >= heap_index && r >= heap_index)
			break;
		
		if (array[p] < array[l] && array[p] < array[r])
			break;
		
		if (l < heap_index && array[l] < array[next])
			next = l;

		if (r < heap_index && array[r] < array[next])
			next = r;

		if (next == p)
			break;
		swap(array, p, next);
	}

#ifdef DEBUG
	{
		int i;
		printf("after pop<%ld>\n", ret);
		for (i = 0; i < heap_index; i++)
			printf("<%d>%ld ", i, heap[i]);
		printf("\n");
	}
#endif

	return ret;
}

int make_sweet(long *array, long least)
{
	long a, b;
	long min;
	int count = 0;
			int i;
			int again = 0;

	while (1) {
		min = array[0];
		if (min >= least)
			break;
		a = heap_pop(array);
		b = heap_pop(array);
#ifdef DEBUG
		printf("a=%ld b=%ld c=%ld\n", a, b, a + 2*b);
#endif
		if (a >= 0 && b >= 0)
			heap_push(array, a + 2 * b);
		else 
			return -1;

		
		count++;
	}
	return count;
}

int main(void)
{
	int i;
	int num;
	long arg;
	long val;

	scanf("%d", &num);
	scanf("%ld", &arg);

	for (i = 0; i < num; i++) {
		scanf("%ld", &val);
		heap_push(heap, val);
	}

	/* for (i = 0; i < num; i++) { */
	/* 	printf("%d %ld\n", i, heap_pop(heap)); */
	/* } */

	printf("%d\n", make_sweet(heap, arg));

	return 0;
}
