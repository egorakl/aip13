#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node {  // Узел дерева
	char *word;  // Указатель на слово
	int count;   // Число вхождений
	struct node *left;  //  Левая ветка
	struct node *right;  //  Правая ветка
}node;

node *create_tree(char *filename);
void free_tree(node *root);
void print_inorder(node *p);
void print_inorder_reverse(node *p);
void print_postorder(node *p);
void print_preorder(node *p);
