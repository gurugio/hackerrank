#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size;
	int i, space, star;

	scanf("%d", &size);

	for (i = 1; i <= size; i++) {
		for (space = 1; space <= size - i; space++)
			printf(" ");
		for (star = space; star <= size; star++)
			printf("#");
		printf("\n");
	}


	return 0;
}
