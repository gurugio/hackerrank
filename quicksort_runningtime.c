#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array1[] = {1,3,9,8,2,7,5};
int array2[] = {12,41,53,25,1};
int array3[] = {62,51,33,65,32};
int array4[] = {62,51,33,65,99};


void printar(int ar_size, int *ar)
{
	int i;
	for (i = 0; i < ar_size; i++)
		printf("%d ", ar[i]);
	printf("\n");
}

int partition(int ar_size, int *ar)
{
	int i;
	int pivot;
	int g;
	int t;

	if (ar_size <= 1)
		return -1;

	g = 0;
	pivot = ar[ar_size - 1];
	for (i = 0; i < ar_size - 1; i++) {
		if (ar[i] > pivot)
			continue;
		else if (ar[i] < pivot) {
			t = ar[i];
			ar[i] = ar[g];
			ar[g] = t;
			g++;
		}
	}
	t = ar[i];
	ar[i] = ar[g];
	ar[g] = t;
	
	printar(ar_size, ar);
	return g;
}

static int quicksort_swap_count = 0;
static int insertsort_swap_count = 0;

void insertsort(int len, int *array)
{
	int left, right;
	int i;
	int shift;
	int pivot;

	shift = 0;
	for (right = 1; right < len; right++) {
		pivot = array[right];
		for (left = right - 1; left >= 0; left--) {
			if (array[left] > pivot) {
				array[left + 1] = array[left];
				shift++;
				insertsort_swap_count++;
			} else
				break;
		}
		array[left+1] = pivot;
	}
}


void quicksort(int ar_size, int *ar)
{
	int i;
	int pivot;
	int g;
	int t;

	if (ar_size <= 1)
		return;

	g = 0;
	pivot = ar[ar_size - 1];
	for (i = 0; i < ar_size - 1; i++) {
		if (ar[i] > pivot)
			continue;
		else if (ar[i] < pivot) {
			t = ar[i];
			ar[i] = ar[g];
			ar[g] = t;
			g++;
			quicksort_swap_count++;
		}
	}
	t = ar[i];
	ar[i] = ar[g];
	ar[g] = t;
	quicksort_swap_count++;
	
	quicksort(g, &ar[0]);
	quicksort(ar_size - g - 1, &ar[g + 1]);
}


int main(void)
{
	int ar_size;
	scanf("%d", &ar_size);
	int i;
	int ar1[ar_size];
	int ar2[ar_size];
	for(i = 0; i < ar_size; i++) { 
		scanf("%d", &ar1[i]);
		ar2[i] = ar1[i];
	}
	
	quicksort(ar_size, ar1);
	insertsort(ar_size, ar2);
	printf("%d\n", insertsort_swap_count - quicksort_swap_count);
	printf("%d\n", sizeof(ar1));
}

