#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PUSH 1
#define POP  2
#define PRINTMAX 3

int main(void)
{
	int num;
	int index;
	int i;
	unsigned int command, data;
	int m;
	int max;
	unsigned int *stack;

	scanf("%d", &num);

	stack = (unsigned int *)calloc(num, sizeof(int));
	index = 0;
	max = 0;
	for (i = 0; i < num; i++) {
		scanf("%d", &command);
		switch (command) {
		case PUSH:
			scanf("%d", &data);
			stack[index] = data;
			index++;
			if (data > max)
				max = data;
			break;
		case POP:
			index--;
			stack[index] = 0;
			max = 0;
			for (m = 0; m < index; m++) {
				if (stack[m] > max)
					max = stack[m];
			}
			break;
		case PRINTMAX:
			printf("%d\n", max);
			break;
		}
	}

	return 0;
}

/*
7
1 1
1 44
3
3
2
3
3
*/
