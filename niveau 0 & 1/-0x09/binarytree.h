#ifndef _TREE
#define _TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
	char *oper;
	int id;
	struct Node* left;
	struct Node* right;
};

typedef struct Node* Tree;

struct Elem
{
	Tree t;
	struct Elem* prev;
	struct Elem* next;
};

typedef struct Elem* List;

Tree createNode(char *val, int id);
int hasSon(Tree t);
List createElem(Tree t);
List insertEnd(List l, Tree t);
int listSize(List l);
List lprv(List l);
List lnxt(List l);
FILE* openDotFile(char *filename);
void exportNode(FILE *f, Tree t);
void exportDotFile(FILE *f, Tree t);

#endif
