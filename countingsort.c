#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int ar[1000000];
char str[1000000][10];
char **sortstr;

int main()
{
	char **sortstr;
	int i, j;
	int count[100] = {0,};
	int next[100] = {0,};
	int num;
	
	scanf("%d", &num);
	sortstr = calloc(num, sizeof(char *));
	
	for (i = 0; i < num; i++) {
		scanf("%d", &ar[i]);
		scanf("%s", str[i]);

		if (i < (int)num/2) {
			str[i][0] = '-';
			str[i][1] = '\0';
		}
		count[ar[i]]++;
		/* printf("%d %s\n", ar[i], str[i]); */
	}

	next[0] = 0;
	for (i = 1; i < 100; i++) {
		next[i] = next[i - 1] + count[i - 1];
	}
	/* for (i = 0; i < 100; i++) { */
	/* 	printf("%d ", next[i]); */
	/* } */
	/* printf("\n"); */

	for (i = 0; i < num; i++) {
		int index;

		index = next[ar[i]];
		next[ar[i]]++;
		sortstr[index] = str[i];

		/* printf("%d %s\n", index, sortstr[index]); */
	}

	for (i = 0; i < num; i++)
		printf("%s ", sortstr[i]);
	printf("\n");
	
	return 0;
}
