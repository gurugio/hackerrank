#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct one_char {
	char ch;
	struct one_char *next;
	struct one_char *prev;
};

char newstr[100000];
int op_history[1000000];
int arg_history[1000000];
int op_top;

struct one_char front = {-1, NULL, NULL};
struct one_char back = {-1, NULL, NULL};

void current(void)
{
	struct one_char *pos;
	int i;

	printf("front: ");
	for (pos = front.next; pos != NULL; pos = pos->next)
		printf("%c", pos->ch);
	printf("\n");

	printf("back: ");
	for (pos = back.next; pos != NULL; pos = pos->next)
		printf("%c", pos->ch);
	printf("\n");

	for (i = 0; i < op_top; i++)
		printf("%d %d\n", op_history[i], arg_history[i]);
}

void add_str(char *str)
{
	// add at the end of front
	struct one_char *pos = &front;
	struct one_char *n;

	op_history[op_top] = 1;
	arg_history[op_top] = strlen(str);
	op_top++;
			
	while (pos->next != NULL)
		pos = pos->next;

	while (*str != '\0') {
		n = malloc(sizeof(struct one_char));
		n->ch = *str++;
		n->next = NULL;
		n->prev = pos;
		pos->next = n;
		pos = n;
	}
}

void del_str(int count)
{
	struct one_char *pos = &front;
	struct one_char *last;
	

	op_history[op_top] = 2;
	arg_history[op_top] = count;
	op_top++;

	// move from the end of front to the head of back
	while (pos->next != NULL)
		pos = pos->next;

	for (; count > 0; count--) {
		last = pos->prev;
		pos->prev->next = NULL;
		
		pos->next = back.next;
		pos->prev = &back;
		if (back.next != NULL)
			back.next->prev = pos;
		back.next = pos;

		pos = last;
	}
}

void print_char(int index)
{
	struct one_char *pos = &front;
	int i = 0;

	while (pos->next != NULL && i++ < index)
		pos = pos->next;

	printf("%c\n", pos->ch);
}

void revert(void)
{
	int arg;
	int op;

	op_top--;
	arg = arg_history[op_top];
	op = op_history[op_top];
	
	if (op == 1) {
		struct one_char *last = &front;
		// move arg characters from the end of back to front
		while (last->next != NULL)
			last = last->next;
		
		for (; arg > 0; arg--) {
			struct one_char *n;
			n = last;
			last = last->prev;
			free(n);
		}
		last->next = NULL;
	} else if (op == 2) {
		struct one_char *last = &front;
		while (last->next != NULL)
			last = last->next;

		for (; arg > 0; arg--) {
			struct one_char *n;

			// remove from back
			n = back.next;
			back.next = n->next;
			if (n->next != NULL)
				n->next->prev = &back;

			// append to front
			last->next = n;
			n->prev = last;
			n->next = NULL;
			last = n;
		}
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
