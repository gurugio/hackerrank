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

void quicksort(int ar_size, int *ar)
{
	int i;
	int pivot;
	int g;
	int t;

	/* pivot = partition(ar_size, ar); */
	/* if (pivot < 0) */
	/* 	return; */
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
		}
	}
	t = ar[i];
	ar[i] = ar[g];
	ar[g] = t;
	printar(7, array1);
	
	quicksort(g, &ar[0]);
	quicksort(ar_size - g - 1, &ar[g + 1]);
}


int main(void)
{
	quicksort(7, array1);
	/* quicksort(5, array2); */
	/* quicksort(5, array3); */
}

