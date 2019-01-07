#ifndef _TREE
#define _TREE

#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int val;
	struct Node* left;
	struct Node* right;
};

typedef struct Node* Tree;

Tree createNode(int n);
Tree insertNode(Tree t, int n);
FILE* openDotFile(char *filename);
void exportNode(FILE *f, Tree t);
void searchNode(FILE *f, Tree t, int n);
void exportDotFile(FILE *f, Tree t);

#endif
