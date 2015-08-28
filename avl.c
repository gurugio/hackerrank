
#include <stdio.h>
#include <stdlib.h>

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
	printf("%d %d\n", root->val, root->ht);
	print_tree(root->right);
}

int get_balance(node *n)
{
	int left = 0, right = 0;
	if (n == NULL)
		return 0;
	if (n->left)
		left = n->left->ht;
	if (n->right)
		right = n->right->ht;
	return left - right;
}

int get_height(node *n)
{
	int left = 0, right = 0;
	if (n == NULL)
		return 0;
	if (n->left)
		left = n->left->ht;
	if (n->right)
		right = n->right->ht;
	return left > right ? left + 1 : right + 1;
}

node *rotate_right(node *n)
{
	node *old_root = n;
	node *left_right = n->left->right;

	n = old_root->left;
	n->right = old_root;
	old_root->left = left_right;
	old_root->ht = get_height(old_root);
	n->ht = get_height(n);
	return n;
}

node *rotate_left(node *n)
{
	node *old_root = n;
	node *right_left = n->right->left;
	n = old_root->right;
	n->left = old_root;
	old_root->right = right_left;
	old_root->ht = get_height(old_root);
	n->ht = get_height(n);
	return n;
}

node *insert(node *root, int val)
{
	int bal;

	if (root == NULL) {
		root = malloc(sizeof(node));
		root->val = val;
		root->left = root->right = NULL;
		root->ht = 1;
		return root;
	}

	if (root->val > val)
		root->left = insert(root->left, val);
	else
		root->right = insert(root->right, val);

	/* height is +1 of child tree */
	root->ht = get_height(root);
	bal = get_balance(root);
	printf("root-%d ht=%d bal=%d\n", root->val, root->ht, bal);

	if (get_balance(root) == 2 && get_balance(root->left) == 1) {
		/* LL case */
		printf("LL rotate\n");
		root = rotate_right(root);
	} else if (get_balance(root) == 2 && get_balance(root->left) == -1) {
		/* LR case */
		printf("LR rotate\n");
		root->left = rotate_left(root->left);
		root = rotate_right(root);
	} else if (get_balance(root) == -2 && get_balance(root->right) == -1) {
		/* RR case */
		printf("RR rotate\n");
		root = rotate_left(root);
	} else if (get_balance(root) == -2 && get_balance(root->right) == 1) {
		/* RL case */
		printf("RL rotate\n");
		root->right = rotate_right(root->right);
		root = rotate_left(root);
	}
	
	return root;
}


int main(void)
{
	node *root = NULL;
	int test;

	test = 4;

	if (test == 1)
	{
		root = insert(root, 1);
		root = insert(root, 2);
		root = insert(root, 3);
		root = insert(root, 4);
		root = insert(root, 5);
		root = insert(root, 6);
		root = insert(root, 7);
		root = insert(root, 8);
		root = insert(root, 9);
		print_tree(root);
	} else if (test == 2) {
		root = insert(root, 9);
		root = insert(root, 8);
		root = insert(root, 7);
		root = insert(root, 6);
		root = insert(root, 5);
		root = insert(root, 4);
		root = insert(root, 3);
		root = insert(root, 2);
		root = insert(root, 1);
		print_tree(root);
	} else if (test == 3) {
		root = insert(root, 9);
		root = insert(root, 1);
		root = insert(root, 8);
		root = insert(root, 2);
		root = insert(root, 7);
		root = insert(root, 3);
		root = insert(root, 6);
		root = insert(root, 4);
		root = insert(root, 5);
		print_tree(root);
	} else if (test == 4) {
		root = insert(root, 1);
		root = insert(root, 5);
		root = insert(root, 2);
		root = insert(root, 6);
		root = insert(root, 3);
		root = insert(root, 7);
		root = insert(root, 4);
		root = insert(root, 8);
		root = insert(root, 9);
		print_tree(root);
	}

	return 0;
}
