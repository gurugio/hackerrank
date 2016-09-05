#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>


unsigned long stack_front[100000];
unsigned long stack_back[100000];

int front_top;
int back_top;
int reverse;

void print_front(void)
{
	int i;
	unsigned long *t;
	
	if (reverse == 0) {
		back_top = 0;
		for (i = front_top-1; i >= 0; i--)
			stack_back[back_top++] = stack_front[i];
		printf("%lu\n", stack_back[back_top - 1]);
		reverse = 1;
	} else {
		/* front_top = 0; */
		/* for (i = back_top-1; i >= 0; i--) */
		/* 	stack_front[front_top++] = stack_back[i]; */
		/* printf("%lu\n", stack_front[front_top - 1]); */
		printf("%lu\n", stack_back[back_top - 1]);
	}
	
	/* front_top = 0; */
	/* for (i = back_top-1; i >= 0; i--) */
	/* 	stack_front[front_top++] = stack_back[i]; */
}

void dequeue(void)
{
	int i;

	if (reverse == 0) {
		back_top = 0;
		for (i = front_top-1; i >= 0; i--)
			stack_back[back_top++] = stack_front[i];
		back_top--;
		reverse = 1;
	} else {
		/* front_top = 0; */
		/* for (i = back_top-1; i >= 0; i--) */
		/* 	stack_front[front_top++] = stack_back[i]; */
		/* front_top--; */
		/* reverse = 0; */
		back_top--;
	}
}

void enqueue(unsigned long num)
{
	int i;
	if (reverse == 0)
		stack_front[front_top++] = num;
	else {
		front_top = 0;
		for (i = back_top-1; i >= 0; i--)
			stack_front[front_top++] = stack_back[i];
		stack_front[front_top++] = num;
		reverse = 0;
	}
}

int main() {
	int i;
	int num;
	int op;
	unsigned long arg;

	scanf("%d", &num);

	for (i = 0; i < num; i++) {
		scanf("%d", &op);
		
		switch (op) {
		case 1:
			scanf("%lu", &arg);
			enqueue(arg);
			break;
		case 2:
			dequeue();
			break;
		case 3:
			print_front();
			break;
		}
	}
	
			
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
