#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>


char *check_pair(char *pair)
{
	int index = 0;
	char *stack;
	int top = 0;
	int ret = 0;
	
	stack = (char *)calloc(strlen(pair), sizeof(char));
	
	while (pair[index] != '\0') {
		switch (pair[index]) {
		case '(':
		case '{':
		case '[':
			stack[top++] = pair[index];
			break;
		case ')':
			if (top == 0 || stack[--top] != '(')
				ret = -1;
			break;
		case '}':
			if (top == 0 || stack[--top] != '{')
				ret = -1;
			break;
		case ']':
			if (top == 0 || stack[--top] != '[')
				ret = -1;
			break;
		}

		if (ret == -1)
			return "NO";

		index++;
	}

	if (top == 0 && ret == 0)
		return "YES";
	else
		return "NO";
}

int main(){
	int t;
	scanf("%d",&t);
	for(int a0 = 0; a0 < t; a0++){
		char* s = (char *)malloc(10240 * sizeof(char));
		scanf("%s",s);
		printf("%s\n", check_pair(s));
	}

	return 0;
}
