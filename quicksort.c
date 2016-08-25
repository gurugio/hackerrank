#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insert_sort(int *array, int len)
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
			} else
				break;
		}
		array[left+1] = pivot;
		
		for (i = 0; i < len; i++)
			printf("%d ", array[i]);
		printf("\n%d\n", shift);

	}


	for (i = 0; i < len; i++)
		printf("%d ", array[i]);
	printf("\n%d\n", shift);
}

void partition(int ar_size, int *ar)
{
	int *left, *right;
	int i;
	int pivot;
	int l, r;
	int copy;

	if (ar_size <= 1)
		return;
	
	left = calloc(ar_size, sizeof(int));
	right = calloc(ar_size, sizeof(int));

	pivot = ar[0];
	l = r = 0;
	for (i = 0; i < ar_size; i++) {
		if (ar[i] <= pivot) {
			left[l] = ar[i];
			l++;
		} else {
			right[r] = ar[i];
			r++;
		}
	}

	copy = 0;
	for (i = 0; i < l; i++) {
		/* printf("%d ", left[i]); */
		ar[copy++] = left[i];
	}
	/* printf("%d ", pivot); */
	ar[copy++] = pivot;
	for (i = 0; i < r; i++) {
		/* printf("%d ", right[i]); */
		ar[copy++] = right[i];
	}
	free(left);
	free(right);
}

void printar(int ar_size, int *ar)
{
	int i;
	for (i = 0; i < ar_size; i++)
		printf("%d ", ar[i]);
	printf("\n");
}

void quicksort(int ar_size, int *ar)
{
	int *left, *right;
	int i;
	int pivot;
	int l, r;
	int copy;

	if (ar_size <= 1)
		return;
	
	left = calloc(ar_size, sizeof(int));
	right = calloc(ar_size, sizeof(int));

	pivot = ar[0];
	l = r = 0;
	for (i = 1; i < ar_size; i++) {
		if (ar[i] <= pivot) {
			left[l] = ar[i];
			l++;
		} else {
			right[r] = ar[i];
			r++;
		}
	}

	copy = 0;
	for (i = 0; i < l; i++) {
		ar[copy++] = left[i];
	}
	ar[copy++] = pivot;
	for (i = 0; i < r; i++) {
		ar[copy++] = right[i];
	}
	free(left);
	free(right);

	quicksort(l, &ar[0]);
	quicksort(r, &ar[l+1]);
	printar(ar_size, ar);
}


int main(void)
{
	int array1[] = {5, 8, 1, 3, 7, 9, 2};
	int array2[] = {12,41,53,25,1};
	int array3[] = {62,51,33,65,32};
	int array4[] = {62,51,33,65,99};

	quicksort(7, array1);
	quicksort(5, array2);
	quicksort(5, array3);
}

