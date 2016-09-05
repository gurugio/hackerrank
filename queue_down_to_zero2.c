#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int queue[100000000];
int head, tail;

int go2zero(int num)
{
	int i;
	int ret = 0;
	int cur;

	head = tail = 0;
	queue[head++] = num;
	
	while (1) {
		int old_head = head;

		while (tail < old_head) {
			cur = queue[tail++];
			if (cur == 0)
				goto FINISH;
			for (i = 2; i <= (int)sqrt(cur); i++) {
				if ((cur % i) == 0) {
					queue[head++] = (int)cur/i;
				}
			}
			queue[head++] = cur - 1;
		}
		ret++;
	}
FINISH:
	return ret;
}
int main(void)
{
	int count, num;
	int i;

	scanf("%d", &count);

	for (; count > 0; count--) {
		scanf("%d", &num);
		printf("%d\n", go2zero(num));
	}

	/* printf("->%d\n", go2zero(0)); */
	/* printf("->%d\n", go2zero(5)); */
	/* printf("->%d\n", go2zero(7)); */

	/* printf("->%d\n", go2zero(94)); */
	/* printf("->%d\n", go2zero(7273)); */
	//printf("->%d\n", go2zero(225604));

	return 0;
}
