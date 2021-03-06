#include "Header.h"


int main()
{
	node *tree;
	char temp;
	int c,n;
	tree = create_tree("aaa.txt");
	
	printf("In-order:\n");
	print_inorder(tree);
	printf("\nReverse in-order:\n");
	print_inorder_reverse(tree);
	printf("\nPre-order:\n");
	print_preorder(tree);
	printf("\nPost-order:\n");
	print_postorder(tree);
	
	printf("\n\nNodes height: ");
	if ((scanf_s("%d%c", &n, &temp) != 2 || temp != '\n') || (n < 0)) {
		printf("Error: invalid input");
		return 0;
	}

	c = count_nodes(tree, n);
	printf("N = %d\n", c);


	free_tree(tree);
	return 0;
}
