#include <stdio.h>

int main(void)
{
	int size;
	char buf[128];
	char *p;
	int i, j;
	
	p = fgets(buf, 128, stdin);
	if (!buf) {
		perror("error to read size\n");
		return 1;
	}

	size = (int)strtol(buf, NULL, 10);
	printf("size-%dX%d\n", size, size);

	for (i = 0; i < size; i++) {
		fgets(buf, 128, stdin);
		p = buf;
		for (j = 0; j < size; j++) {
			int num;
			num = strtol(p, &p, 10);
			printf("num=%d p=%p\n", num, p);
			p++;
		}
	}


	return 0;
}
	
