#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* int array1[] = {3,2,1,1,1}; */
/* int array2[] = {4,3,2}; */
/* int array3[] = {1,1,4,1}; */


/* int swap_arr(int len, int *ar) */
/* { */
/* 	int i; */
/* 	for (i = 0; i < (int)len/2; i++) { */
/* 		int t = ar[len - 1 - i]; */
/* 		ar[len - 1 - i] = ar[i]; */
/* 		ar[i] = t; */
/* 	} */
/* } */

/* int get_height(int len, int *ar) */
/* { */
/* 	int i; */
/* 	int h = 0; */
/* 	for (i = 0; i < len; i++) */
/* 		h += ar[i]; */
/* 	return h; */
/* } */

int main(void)
{
	int a1_size, a2_size, a3_size;
	int *array1, *array2, *array3;
	int *a1_height, *a2_height, *a3_height;
	int i;
	int total;
	int h1, h2, h3;
	int h1_size, h2_size, h3_size;

	int *a1, *a2, *a3;
		

	scanf("%d %d %d", &a1_size, &a2_size, &a3_size);

	array1 = (int *)calloc(a1_size, sizeof(int));
	array2 = (int *)calloc(a2_size, sizeof(int));
	array3 = (int *)calloc(a3_size, sizeof(int));
	a1_height = (int *)calloc(a1_size, sizeof(int));
	a2_height = (int *)calloc(a2_size, sizeof(int));
	a3_height = (int *)calloc(a3_size, sizeof(int));

	total = 0;
	for (i = 0; i < a1_size; i++) {
		int t;
		scanf("%d", &t);
		array1[i] = t;
		total += t;
	}
	
	for (i = 0; i < a1_size; i++) {
		a1_height[i] = total;
		total -= array1[i];
	}

	total = 0;
	for (i = 0; i < a2_size; i++) {
		int t;
		scanf("%d", &t);
		array2[i] = t;
		total += t;
	}
	
	for (i = 0; i < a2_size; i++) {
		a2_height[i] = total;
		total -= array2[i];
	}

	total = 0;
	for (i = 0; i < a3_size; i++) {
		int t;
		scanf("%d", &t);
		array3[i] = t;
		total += t;
	}
	
	for (i = 0; i < a3_size; i++) {
		a3_height[i] = total;
		total -= array3[i];
	}

	/* printf("%d %d %d %d %d %d\n", a1_size, a2_size, a3_size, */
	/*        a1_height[0], a2_height[0], a3_height[0]); */
	/* printf("%d %d %d\n", a1_height[1], a2_height[1], a3_height[1]); */

	/*
	 * fast version
	 */


	if (a1_size < a2_size && a1_size < a3_size) {
		h1_size = a1_size;
		a1 = a1_height;
		h2_size = a2_size;
		a2 = a2_height;
		h3_size = a3_size;
		a3 = a3_height;
	} else if (a2_size < a1_size && a2_size < a3_size) {
		h1_size = a2_size;
		a1 = a2_height;
		h2_size = a1_size;
		a2 = a1_height;
		h3_size = a3_size;
		a3 = a3_height;
	} else {
		h1_size = a3_size;
		a1 = a3_height;
		h2_size = a1_size;
		a2 = a1_height;
		h3_size = a2_size;
		a3 = a2_height;
	}
		
	for (h1 = 0; h1 < h1_size; h1++) {
		for (h2 = 0; h2 < h2_size; h2++) {
			if (a2[h2] == a1[h1])
				break;
		}

		if (h2 == h2_size)
			continue;

		for (h3 = 0; h3 < h3_size; h3++) {
			if (a3[h3] == a1[h1])
				break;
		}

		if (h3 == h3_size)
			continue;

		printf("%d\n", a1[h1]);
		return 0;
	}
	printf("0\n");

	
	/*
	 * slow version
	 */
#if 0
	unsigned int a1_height, a2_height, a3_height;
	int a1_size, a2_size, a3_size;

	unsigned int orig_a1_height = 0, orig_a2_height = 0, orig_a3_height = 0;
	int orig_a1_size, orig_a2_size, orig_a3_size;

	int *array1, *array2, *array3;
	int i;

	scanf("%d %d %d", &orig_a1_size, &orig_a2_size, &orig_a3_size);

	array1 = (int *)calloc(orig_a1_size, sizeof(int));
	array2 = (int *)calloc(orig_a2_size, sizeof(int));
	array3 = (int *)calloc(orig_a3_size, sizeof(int));

	for (i = orig_a1_size - 1; i >= 0; i--) {
		int t;
		scanf("%d", &t);
		array1[i] = t;
		orig_a1_height += t;
	}
	for (i = orig_a2_size - 1; i >= 0; i--) {
		int t;
		scanf("%d", &t);
		array2[i] = t;
		orig_a2_height += t;
	}
	for (i = orig_a3_size - 1; i >= 0; i--) {
		int t;
		scanf("%d", &t);
		array3[i] = t;
		orig_a3_height += t;
	}
	/* printf("%d %d %d %d %d %d\n", orig_a1_size, orig_a2_size, orig_a3_size, */
	/*        orig_a1_height, orig_a2_height, orig_a3_height); */


	a1_size = orig_a1_size;
	a1_height = orig_a1_height;
	while (a1_size > 0) {
		/* printf("a1=%d\n", a1_height); */
		a2_height = orig_a2_height;
		a2_size = orig_a2_size;
		while (a2_size > 0) {
			/* printf("a2=%d\n", a2_height); */
			if (a1_height == a2_height)
				break;
			else
				a2_size--;
			a2_height -= array2[a2_size];
		}

		if (a2_size > 0) {
			a3_size = orig_a3_size;
			a3_height = orig_a3_height;
			while (a3_size > 0) {
				/* printf("a3=%d\n", a3_height); */
				if (a1_height == a3_height)
					break;
				else
					a3_size--;
				a3_height -= array3[a3_size];
			}
		}

		if (a2_size > 0 && a3_size > 0) {
			break;
		}

		a1_size--;
		a1_height -= array1[a1_size];	
	}
	printf("%d\n", a1_height);
#endif


	return 0;
}

