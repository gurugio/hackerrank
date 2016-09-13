#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main(void)
{
	int num;
	int len;
	int *array;
	int i;
	int found;

	scanf("%d", &num);

	for (; num > 0; num--) {
		unsigned int left, right;
		
		scanf("%d", &len);
		array = calloc(len, sizeof(unsigned int));

		for (i = 0; i < len; i++) {
			scanf("%u", &array[i]);
		}

		left = 0;
		right = 0;
		for (i = 0; i < len; i++)
			right += array[i];

		found = 0;
		for (i = 0; i < len; i++) {
			if (i == 0)
				left = 0;
			else
				left += array[i - 1];
			right -= array[i];

			if (left == right) {
				found = 1;
				break;
			}
		}
		if (found)
			printf("YES\n");
		else
			printf("NO\n");
		free(array);
	}

	return 0;
}
