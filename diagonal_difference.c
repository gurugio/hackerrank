#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int size;
#define BUF_SIZE 1024	
	char buf[BUF_SIZE];
	char *p;
	int i, j;
	int *matrix;
	int diag1, diag2;
	
	p = fgets(buf, 128, stdin);
	if (!buf) {
		perror("error to read size\n");
		return 1;
	}

	size = (int)strtol(buf, NULL, 10);

	matrix = (int *)malloc(sizeof(int) * size * size);

	for (i = 0; i < size; i++) {
		fgets(buf, BUF_SIZE, stdin);
		p = buf;
		for (j = 0; j < size; j++) {
			int num;
			num = strtol(p, &p, 10);
			matrix[i * size + j] = num;
			p++;
		}
	}

	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			printf("%d ", matrix[(i * size) + j]);
		}
		printf("\n");
	}
	
	diag1 = diag2 = 0;
	for (i = 0; i < size; i++) {
		diag1 += matrix[i * size + i];
		diag2 += matrix[(i + 1) * size - i - 1];
	}
	
	printf("%d\n", abs(diag1 - diag2));

	return 0;
}
	
