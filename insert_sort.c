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

int main(void)
{
	int array1[] = {2,1,3,1,2};
	int array2[] = {12,41,53,25,1};
	int array3[] = {62,51,33,65,32};
	int array4[] = {62,51,33,65,99};


	insert_sort(array1, 5);
	insert_sort(array2, 5);
	insert_sort(array3, 5);
	insert_sort(array4, 5);

}

