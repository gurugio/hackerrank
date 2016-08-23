#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
	int num_string;
	int i, j;
	char **strings;
	int num_query;
	char **querys;
	int found;
	
	scanf("%d", &num_string);
	fgetc(stdin);

	strings = calloc(num_string, sizeof(char *));
	for (i = 0; i < num_string; i++) {
		strings[i] = malloc(50);
		fgets(strings[i], 50, stdin);
		/* strings[i][strlen(strings[i]) - 1] = '\0'; */
	}
      
	scanf("%d", &num_query);
	fgetc(stdin);

	querys = calloc(num_query, sizeof(char *));
	for (i = 0; i < num_query; i++) {
		querys[i] = malloc(50);
		fgets(querys[i], 50, stdin);
		/* querys[i][strlen(querys[i]) - 1] = 0; */
	}

	for (i = 0; i < num_query; i++) {
		found = 0;
		for (j = 0; j < num_string; j++) {
			if (!strncmp(querys[i], strings[j], 20))
				found++;
		}
		fprintf(stdout, "%d\n", found);
	}
	

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
