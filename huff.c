#include <stdio.h>
#include <string.h>

typedef struct node
{
    int freq;
    char data;
    struct node * left;
    struct node * right;
}node;

typedef char * string;
struct node nodes[100];

void decode_huff(node * root,string s)
{
	int i;
	node *cur;
	node *next;

	printf("decode:%s\n", s);

	cur = root;
	for (i = 0; i < strlen(s); i++) {
		if (s[i] == '1') {
			next = cur->right;
		} else {
			next = cur->left;
		}

		if (next->left == NULL && next->right == NULL) {
			printf("%p\n", next->data);
			cur = root;
		} else {
			cur = next;
		}
	}
	printf("\n");
}


int main(void)
{
	string code = "1001011";
	
	/* root */
	nodes[0].freq = 5;
	nodes[0].data = 0;
	nodes[0].left = &nodes[1];
	nodes[0].right = &nodes[2];

	/* node */
	nodes[1].freq = 2;
	nodes[1].data = 0;
	nodes[1].left = &nodes[3];
	nodes[1].right = &nodes[4];

	/* node A */
	nodes[2].freq = 3;
	nodes[2].data = 'A';
	nodes[2].left = nodes[2].right = NULL;

	/* node B */
	nodes[3].freq = 1;
	nodes[3].data = 'B';
	nodes[3].left = nodes[3].right = NULL;

	/* node C */
	nodes[4].freq = 1;
	nodes[4].data = 'C';
	nodes[4].left = nodes[4].right = NULL;

	decode_huff(&nodes[0], code);
}
