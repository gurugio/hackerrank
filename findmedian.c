#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int array1[] = {-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854};
int array2[] = {-20, -3916237, -357920, -3620601, 7374819, -7330761, 30, 6246457, -6461594, 266854, -520, -470};
int array3[] = {5,4,3,2};
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
	
	return g;
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
		}
	}
	t = ar[i];
	ar[i] = ar[g];
	ar[g] = t;
	
	quicksort(g, &ar[0]);
	quicksort(ar_size - g - 1, &ar[g + 1]);
}

int array[1000001];

int main(void)
{
	int num;
	int i;
	scanf("%d", &num);

	for (i = 0; i < num; i++)
		scanf("%d", &array[i]);

	quicksort(num, array);
	printf("%d\n", array[num/2]);
	
	return 0;
}
