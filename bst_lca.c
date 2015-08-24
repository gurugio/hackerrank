/* Binary Search Tree: Lowest Common Ancestor */
#include <stdio.h>


struct node
{
	int data;
	struct node * left;
	struct node * right;
} node;

struct node nodes[10];


struct node *lca(struct node *root, int v1, int v2)
{
	struct node *found;
	if (root == NULL)
		return NULL;

	if (v1 < root->data && v2 < root->data)
		found = lca(root->left, v1, v2);
	else if (v1 > root->data && v2 > root->data)
		found = lca(root->right, v1, v2);
	else if (v1 == root->data || v2 == root->data)
		found = root;
	else
		found = root;
	return found;
}

int main(void)
{
	nodes[4].data = 4;
	nodes[2].data = 2;
	nodes[7].data = 7;
	nodes[1].data = 1;
	nodes[3].data = 3;
	nodes[6].data = 6;

	nodes[4].left = &nodes[2];
	nodes[4].right = &nodes[7];

	nodes[2].left = &nodes[1];
	nodes[2].right = &nodes[3];

	nodes[7].left = &nodes[6];
	nodes[7].right = NULL;

	nodes[1].left = nodes[1].right = NULL;
	nodes[3].left = nodes[3].right = NULL;
	nodes[6].left = nodes[6].right = NULL;

	{
		struct node *found;
		found = lca(&nodes[4], 2, 7);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");


		found = lca(&nodes[4], 2, 6);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");

		found = lca(&nodes[4], 1, 7);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");

		found = lca(&nodes[4], 1, 3);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");

		found = lca(&nodes[4], 7, 6);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");

		found = lca(&nodes[4], 7, 4);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");

		found = lca(&nodes[4], 1, 4);
		if (found)
			printf("%d\n", found->data);
		else
			printf("not found\n");
	}

	return 0;
}
