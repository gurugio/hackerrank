#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void index_sort(char *str, int len)
{
	int map['z'-'a' + 1] = {0,};
	int i;
	int j;

	for (i = 0; i < len; i++)
		map[str[i] - 'a']++;
	i = 0;
	for (j = 0; j < 'z' -'a' + 1; j++)
		for (; map[j] > 0; map[j]--)
			str[i++] = j + 'a';
}

int main()
{
	int num;
	int size;
	int i, j;
	char **grid;
	int ret = 0;

	scanf("%d", &num);

	for (; num > 0; num--) {
		ret = 0;
		scanf("%d", &size);

		grid = (char **)calloc(size, sizeof(char *));
		for (i = 0; i < size; i++) {
			grid[i] = (char *)calloc(size+1, sizeof(char));
			scanf("%s", grid[i]);
		}

		for (i = 0; i < size; i++) {
			index_sort(grid[i], size);
			//printf("%s\n", grid[i]);
		}

		for (i = 0; i < size; i++) {
			for (j = 1; j < size; j++) {
				if (grid[j][i] < grid[j-1][i])
					goto finish;
			}
		}

		ret = 1;
	finish:
		printf("%s\n", ret == 0 ? "NO" : "YES");

		for (i = 0; i < size; i++) {
			free(grid[i]);
		}
		free(grid);
	}

	return 0;
}

