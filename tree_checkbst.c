#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

bool checkBST(struct Node *root)
{
	if (root->left == NULL && root->right != NULL)
		return false;
	if (root->left == NULL && root->right == NULL)
		return true;

	if (root->left != NULL) {
		if (root->left->data > root->data
		    || !checkBST(root->left))
			return false;
	}
	
	if (root->right != NULL) {
		if (root->right->data < root->data
		    || !checkBST(root->right))
			return false;
	}

	return true;
}

	

int main(void)
{
	struct Node n[8];

	n[1].data = 1;
	n[1].left = n[1].right = NULL;
	n[4].data = 4;
	n[4].left = n[4].right = NULL;
	n[6].data = 1;
	n[6].left = n[6].right = NULL;
	n[7].data = 1;
	n[7].left = n[7].right = NULL;

	n[2].data = 2;
	n[2].left = &n[1];
	n[2].right = &n[4];

	n[5].data = 5;
	n[5].left = &n[6];
	n[5].right = &n[7];

	n[3].data = 3;
	n[3].left = &n[2];
	n[3].right = &n[5];

	printf("%d\n", checkBST(&n[3]));
	
	return 0;
}
