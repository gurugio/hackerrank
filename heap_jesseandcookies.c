#include <stdio.h>
#include <stdlib.h>

#define lchild(i) (2*(i) + 1)
#define rchild(i) (2*(i) + 2)

long heap[100000];
int heap_index;

int parent(int i)
{
	return (i <= 0) ? -1 : ((int)(((i) - 1)/2));
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
		if (p < 0 || array[p] < array[cur])
			break;

		t = array[cur];
		array[cur] = array[p];
		array[p] = t;
		cur = p;
	}

#ifdef DEBUG
		int i;
		for (i = 0; i < heap_index; i++)
			printf("%ld ", heap[i]);
		printf("\n");
#endif
}

long heap_pop(long *array)
{
	int l, r;
	int cur = 0;
	long ret = array[0];

	if (heap_index == 0)
		return -1;
	
	array[cur] = array[heap_index - 1];
	
	while (cur < heap_index) {
		l = lchild(cur);
		r = rchild(cur);

#ifdef DEBUG
		printf("cur=%d l=%d r=%d heap_index=%d\n", cur, l, r, heap_index);
#endif

		if (l < heap_index && r < heap_index) {
			int t;
			if (array[l] < array[r]) {
				t = array[l];
				array[l] = array[cur];
				array[cur] = t;
				cur = l;
			} else {
				t = array[r];
				array[r] = array[cur];
				array[cur] = t;
				cur = r;
			}
		} else if (l < heap_index && r >= heap_index) {
			int t;
			t = array[l];
			array[l] = array[cur];
			array[cur] = t;
			cur = l;
		} else
			break;
	}

	heap_index--;
#ifdef DEBUG
	{
		int i;
		for (i = 0; i < heap_index; i++)
			printf("%ld ", heap[i]);
		printf("\n");
	}
#endif

	return ret;
}

int make_sweet(long *array, int least)
{
	long a, b;
	long min;
	int count = 0;
			int i;
			int again = 0;

	while (1) {
		min = heap_pop(array);
		if (min >= least)
			break;
		heap_push(array, min);
		a = heap_pop(array);
		b = heap_pop(array);

		printf("a=%ld b=%ld c=%ld\n", a, b, a + 2*b);
		if (a > 0 && b > 0)
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
	int arg;
	long val;

	scanf("%d", &num);
	scanf("%d", &arg);

	for (i = 0; i < num; i++) {
		scanf("%ld", &val);
		heap_push(heap, val);
	}

	printf("%d\n", make_sweet(heap, arg));
	
	return 0;
}
