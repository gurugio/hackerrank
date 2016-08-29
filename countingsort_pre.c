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
	int i, j;
	int next[100];
	
	for (i = 0; i < num; i++) {
		scanf("%d", &ar[i]);
		scanf("%s", str[i]);
		count[ar[i]]++;
	}

	next[0] = count[0];
	printf("%d ", next[0]);
	for (i = 1; i < 100; i++) {
		next[i] = next[i - 1] + count[i];
		printf("%d ", next[i]);
	}
	printf("\n");

	return 0;
}
