#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


char newstr[100000];
int op_history[1000000];
int arg_history[1000000];
int op_top;

char front[1000000];
int front_top;
char back[1000000];
int back_top;

void current(void)
{
	struct one_char *pos;
	int i;

	printf("front: ");
	for (i = 0; i < front_top; i++)
		printf("%c", front[i]);
	printf("\n");

	printf("back: ");
	for (i = 0; i < back_top; i++)
		printf("%c", back[i]);
	printf("\n");

	for (i = 0; i < op_top; i++)
		printf("%d %d\n", op_history[i], arg_history[i]);
}

void add_str(char *str)
{
	op_history[op_top] = 1;
	arg_history[op_top] = strlen(str);
	op_top++;
			
	// add at the end of front
	while (*str != '\0') {
		front[front_top++] = *str++;
	}
}

void del_str(int count)
{
	op_history[op_top] = 2;
	arg_history[op_top] = count;
	op_top++;

	for (; count > 0; count--) {
		front_top--;
		back[back_top++] = front[front_top];
	}
}

void print_char(int index)
{
	printf("%c\n", front[index - 1]);
}

void revert(void)
{
	int arg;
	int op;

	op_top--;
	arg = arg_history[op_top];
	op = op_history[op_top];
	
	if (op == 1) {
		front_top -= arg;
	} else if (op == 2) {
		for (; arg > 0; arg--)
			front[front_top++] = back[--back_top];
	}
}

int main(void)
{
	int num_op;
	int i;
	int op;
	int arg;
	
	scanf("%d", &num_op);

	for (i = 0; i < num_op; i++) {
		scanf("%d", &op);

		switch (op) {
		case 1:
			scanf("%s", newstr);
			add_str(newstr);
			break;
		case 2:
			scanf("%d", &arg);
			del_str(arg);
			break;
		case 3:
			scanf("%d", &arg);
			print_char(arg);
			break;
		case 4:
			revert();
			break;
		}
		//current();
	}

	return 0;
}
