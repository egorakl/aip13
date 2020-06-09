#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {  // ���� ������
	char *word;  // ��������� �� �����
	int count;   // ����� ���������
	struct node *left;  //  ����� �����
	struct node *right;  //  ������ �����
}node;

node *create_tree(char *filename);
void free_tree(node *root);
void print_inorder(node *p);
void print_inorder_reverse(node *p);
void print_postorder(node *p);
void print_preorder(node *p);
