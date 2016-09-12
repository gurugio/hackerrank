#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

int data[7] = {1, 2, 2, 4, 5, 6, 7}; // F
//int data[7] = {1, 2, 3, 4, 5, 6, 7}; // T
//int data[7] = {1, 2, 4, 3, 5, 6, 7}; // F

int dataindex;
int datalimit;
struct Node Root = {-1, NULL, NULL};

bool check_inorder(struct Node *root, int data, int bigger)
{
	if (!root)
		return true;
	
	if (root->left)
		if (!check_inorder(root->left, data, bigger))
			return false;
	
	if (bigger) {
		if (root->data <= data) {
			printf("F: %d > %d\n", root->data, data);
			return false;
		} else
			printf("T: %d > %d\n", root->data, data);
	} else {
		if (root->data >= data) {
			printf("F: %d < %d\n", root->data, data);
			return false;
		} else
			printf("T: %d < %d\n", root->data, data);
	}
	
	if (root->right)
		if (!check_inorder(root->right, data, bigger))
			return false;

	return true;
}

bool checkBST(struct Node *root)
{
	if (root) {
		if (check_inorder(root->left, root->data, 0) &&
		    check_inorder(root->right, root->data, 1) &&
		    checkBST(root->left) && checkBST(root->right))
			return true;
		else
			return false;
	} else
		return true;
}

void build_inorder(struct Node *root, int level)
{
	if (root != NULL) {
		root->left = root->right = NULL;
		if (level > 0) {
			root->left = malloc(sizeof(struct Node));
			build_inorder(root->left, level - 1);
		}

		if (dataindex < datalimit)
			root->data = data[dataindex++];
		else
			root->data = -1;
		
		if (level > 0) {
			root->right = malloc(sizeof(struct Node));
			build_inorder(root->right, level - 1);
		}
	}
}

void print_inorder(struct Node *root)
{
	if (root->left)
		print_inorder(root->left);
	printf("%d %d %d\n", root->data,
	       root->left ? root->left->data : -1,
	       root->right ? root->right->data : -1);
	if (root->right)
		print_inorder(root->right);
}


int main(void)
{
	datalimit = 7;
	build_inorder(&Root, 2);
	print_inorder(&Root);
	
	printf("%d\n", check_inorder(Root.left, 4, 0));
	printf("%d\n", check_inorder(Root.right, 4, 1));	

	printf("%d\n", checkBST(&Root));
	
	return 0;
}
