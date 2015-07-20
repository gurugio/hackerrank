#include <stdio.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node n[50];


int height(struct node *root)
{
	int hleft = 0, hright = 0;

	printf("data=%d\n", root->data);
	if (root->left)
		hleft = height(root->left);
	if (root->right)
		hright = height(root->right);

	printf("left=%d right=%d\n", hleft, hright);
	if (!root->right && !root->left) {
		printf("data=%d return=%d\n", root->data, 1);
		return 1;
	} else {
		printf("data=%d return=%d\n", root->data,
		       hleft > hright ? hleft + 1 : hright + 1);
		return hleft > hright ? hleft + 1 : hright + 1;
	}
}
	      
void inorder(struct node *root)
{
	if (root->left)
		inorder(root->left);
	printf("%d ", root->data);
	if (root->right)
		inorder(root->right);
}

void top_view(struct node *root)
{
	/* example */
	/* n[3].left = &n[5]; */
	/* n[3].right = &n[2]; */
	
	/* n[5].left = &n[1]; */
	/* n[5].right = &n[4]; */

	/* n[2].left = &n[6]; */
	/* n[2].right = &n[7]; */

	/* n[1].right = &n[9]; */

	/* n[7].left = &n[8]; */

	/* top_view(&n[3]); */
	struct node *old_root;
	while (root->left != NULL) {
		old_root = root;
		root = root->left;

		root->right = old_root;
	}
	
	while (root != NULL) {
		printf("%d ", root->data);
		root = root->right;
	}
}

int main(void)
{
	int i;

	for (i = 1; i <= 9; i++) {
		n[i].data = i;
		n[i].left = n[i].right = NULL;
	}

	n[3].left = &n[5];
	n[3].right = &n[2];
	
	n[5].left = &n[1];
	n[5].right = &n[4];

	n[2].left = &n[6];
	n[2].right = &n[7];

	n[1].right = &n[9];

	n[7].left = &n[8];

	/* printf("%d\n", height(&n[3])); */
	top_view(&n[3]);
}

