#include "Header.h"


char* checkline(char* s) {   //  �������� ������ �� ������������
	int t = 0;

	for (int i = 0; i < strlen(s); i++) {
		if (isalpha(s[i]) == 0 && s[i]!='\n' && s[i] != ' ') {
			printf("Error: invalid input.\n");
			return NULL;
		}
		if (isalpha(s[i]) != 0) t++;
	}
	if (t == 0) {
		printf("Error: no letters in file.\n");
		return NULL;
	}

	return s;
}

node *newnode(node *p, char *w) {   // ���������� ���� � ������
	int cond;
	if (p == NULL) {
		p = (node*)malloc(sizeof(node));
		p->word = (char*)malloc(strlen(w));
		strcpy(p->word, w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}

	else if ((cond = strcmp(w, p->word)) == 0)
		p->count++;
	else if (cond < 0)
		p->left = newnode(p->left, w);
	else
		p->right = newnode(p->right, w);
	return p;
}

void free_tree(node *root) {
	if (root != NULL) {
		free_tree(root->left); // ����������� ����� ������ ���������
		free_tree(root->right); // ����������� ����� ������� ��������� 
		free(root); // ������� ���� ������
	}
}

//  ������������ ����� (in-order)
void print_inorder(node *p) {
	if (p != NULL) {
		print_inorder(p->left);  // ����������� ����� ������ ���������
		printf("%s (%d) ", p->word, p->count); // ����� ����������� ����
		print_inorder(p->right);  // ����������� ����� ������� ��������� 
	}
}

// ������������ ����� � �������� �������
void print_inorder_reverse(node *p) {
	if (p != NULL) {
		print_inorder_reverse(p->right);
		printf("%s (%d) ", p->word, p->count);
		print_inorder_reverse(p->left);
	}
}

// �������� �����
void print_postorder(node *p) {
	if (p != NULL) {
		print_postorder(p->left);  // ����������� ����� ������ ���������
		print_postorder(p->right);
		printf("%s (%d) ", p->word, p->count);
	}
}

// ������ ����� (pre-order)
void print_preorder(node *p) {
	if (p != NULL) {
		printf("%s (%d) ", p->word, p->count);  // ����� ����������� ����
		print_preorder(p->left);  // ����������� ����� ������ ���������
		print_preorder(p->right);  // ����������� ����� ������� ��������� 
	}
}


int count_nodes(node* p, int h) {   // ���������� ���������� ����� �������� ������
	int c = 0, lc, rc;
	if (h < 0 || !p || !p->left && !p->right)
		return 0;
	else {
		lc = count_nodes(p->left,h-1);
		rc = count_nodes(p->right,h-1);
		if (h == 0)
			return 1;
	}
	return (lc + rc);
}

node *create_tree(char *filename)   // �������� ������
{
	node *root = NULL;
	FILE *f;
	char str[100];
	char *s;
	if (!(f = fopen(filename, "rt"))) {	// ��������� ��������� ���� ��� ������ � ��������� �� ������������ ��������
		printf("Error: could not open the file\n");	// ��������� � ���, ��� ���� �� �����������
		exit(1);
	}

	fgets(str, sizeof(str), f); // ���������� ���������� ����� � ������

	char sep[] = {' ','\n','\0'};  // ������ � ��������������� ���������
	s = strtok(str, sep);  // �������� �� �������

	if (strlen(s) > 20) { // �������� ����� �� �����
			printf("Error: word length > 20\n");
			free_tree(root);
			exit(1);
		}
	root = newnode(root, s);

	s = strtok(NULL, sep);
	while (s != NULL)
	{
		if (strlen(s) > 20) { // �������� ����� �� �����
			printf("Error: word length >20\n");
			free_tree(root);
			exit(1);
		}
		root = newnode(root, s);
		s = strtok(NULL, sep);
	}
	fclose(f);
	return root;
}
