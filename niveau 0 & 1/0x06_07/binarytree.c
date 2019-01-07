#include "binarytree.h"

Tree createNode(int n)
{
	Tree t = (Tree)malloc(sizeof(struct Node));
	if(t != NULL)
	{
		t->val = n;
		t->left = NULL;
		t->right = NULL;
	}
	return t; 
}

Tree insertNode(Tree t, int n)
{

	if(t == NULL) return createNode(n);
	if(n < t->val) t->left = insertNode(t->left, n);
	if(n > t->val) t->right = insertNode(t->right, n);
	
	return t;
}

//Réécrire les fonction pour les utiliséesde manière plus logique

void exportNode(FILE *f, Tree t)
{
	if(t == NULL) return ;
	if(t->left != NULL) fprintf(f, "%d -- %d\n\t", t->val, t->left->val);
	if(t->right != NULL) fprintf(f, "%d -- %d\n\t", t->val, t->right->val);
	exportNode(f, t->left);
	exportNode(f, t->right);
}

void searchNode(FILE *f, Tree t, int n)
{
	if(t == NULL) return ;
	if(t->val == n) fprintf(f, "%d[color=\"blue\"]", n);
	if(n < t->val) searchNode(f, t->left, n);
	if(n > t->val) searchNode(f, t->right, n);
}

FILE* openDotFile(char *filename)
{
	FILE* f = fopen(filename, "w");
	fprintf(f, "graph G {\n\t");
	return f;
}

void exportDotFile(FILE *f, Tree t)
{	
	fprintf(f, "\r}");
	fclose(f);
}
