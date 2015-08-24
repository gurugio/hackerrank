
#include <stdio.h>

typedef struct node
{
    int val;
    struct node *left;
    struct node *right;
    int ht;
} node;


struct node nodes[10];

void print_tree(node *root)
{
	if (root == NULL)
		return;

	print_tree(root->left);
	printf("%d\n", root->val);
	print_tree(root->right);
}

node * insert(node * root,int val)
{
	
	return root;
}


int main(void)
{
	nodes[3].val = 3;
	nodes[3].ht = -1;
	nodes[3].left = &nodes[2];
	nodes[3].right = &nodes[4];

	nodes[2].val = 2;
	nodes[2].ht = 0;
	nodes[2].left = NULL;
	nodes[2].right = NULL;

	nodes[4].val = 4;
	nodes[4].ht = -1;
	nodes[4].left = NULL;
	nodes[4].right = &nodes[5];

	nodes[5].val = 5;
	nodes[5].ht = 0;
	nodes[5].left = NULL;
	nodes[5].right = NULL;

	print_tree(&nodes[3]);
	insert(&nodes[3], 6);
	print_tree(insert(&nodes[3], 6));
}
