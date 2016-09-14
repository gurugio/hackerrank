#include <stdio.h>

int store[1024];

int fib(int x)
{
	if (store[x] == 0) {
		store[x] = fib(x - 1) + fib(x - 2);
		//printf("store[%d] = %d\n", x, store[x]);
	} else {
		//printf("get from store[%d]\n", x);
	}

	return store[x];
}

int _fib(int x)
{
	if (x == 1) return 1;
	if (x == 2) return 2;
	return _fib(x - 1) + _fib(x - 2);
}

int main(void)
{
	store[0] = 0;
	store[1] = 1;
	store[2] = 2;

	printf("%d\n", fib(30));
	printf("%d\n", _fib(30));
}
