#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


int main()
{
	int count[100] = {0,};
	int num;
	scanf("%d", &num);

	int ar[num];
	char str[num][10];
	char **sortstr;
	int i, j;

	sortstr = calloc(num, sizeof(char *));
	for (i = 0; i < num; i++)
		sortstr[i] = NULL;
	
	for (i = 0; i < num; i++) {
		scanf("%d", &ar[i]);
		scanf("%s", str[i]);
		count[ar[i]]++;
	}

	for (i = 1; i < 100; i++) {
		count[i] = count[i - 1] + count[i];
	}
	for (i = 0; i < 100; i++)
		printf("%d ", count[i]);
	printf("\n");

	for (i = 0; i < num; i++) {
		int index;
		for (index = count[ar[i] - 1]; index < count[ar[i]]; index++) {
			if (sortstr[index] == NULL)
				break;
		}
		sortstr[index] = str[i];
		printf("%d %s\n", index, sortstr[index]);
	}


	
	return 0;
}
