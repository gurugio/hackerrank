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

long heap_pop(long *array, int cur)
{
	int l, r;
	long ret = array[cur];

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

	return ret;
}

void heap_delete(long *array, long val)
{
	int i;

	for (i = 0; i < heap_index; i++) {
		if (array[i] == val)
			break;
	}
	if (i < heap_index)
		heap_pop(array, i);

#ifdef DEBUG
	for (i = 0; i < heap_index; i++)
		printf("%ld ", heap[i]);
	printf("\n");
#endif
}

int main(void)
{
	int i;
	int num;
	int op;
	long arg;


	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &op);
		
		switch (op) {
		case 1:
			scanf("%ld", &arg);
			heap_push(heap, arg);
			break;
		case 2:
			scanf("%ld", &arg);
			heap_delete(heap, arg);
			break;
		case 3:
			printf("%ld\n", heap[0]);
			break;
		}
	}


	return 0;
	

	heap_push(heap, 286789035);
	heap_push(heap, 255653921);
	heap_push(heap, 274310529);
	heap_push(heap, 494521015);

	heap_delete(heap, 255653921);
	heap_delete(heap, 286789035);

	heap_push(heap, 236295092);
	heap_push(heap, 254828111);
	
	heap_delete(heap, 254828111);

	heap_push(heap, 465995753);
	heap_push(heap, 85886315);
	heap_push(heap, 7959587);
	heap_push(heap, 20842598);

	heap_delete(heap, 7959587);

	heap_push(heap, -51159108);
	heap_delete(heap, -51159108);
	
	return 0;
}
