#include "binarytree.h"

Tree createNode(char *val, int id)
{
	int len = strlen(val);
	Tree t = (Tree)malloc(sizeof(struct Node));
	t->oper = (char*)malloc(sizeof(char)*(len+1));
	if(t != NULL)
	{
		strcpy(t->oper, val);
		t->id = id;
		t->left = NULL;
		t->right = NULL;
	}
	return t; 
}

int hasSon(Tree t)
{
	if((t->right != NULL) || (t->left != NULL))
		return 1;
	return 0;
}

List createElem(Tree t)
{
	List l = (List)malloc(sizeof(struct Elem));
	if(l != NULL)
	{
		l->t = t;
		l->prev = NULL;
		l->next = NULL;
	}
	return l;
}

List insertEnd(List l, Tree t)
{
	List tmp = l;
	if(l == NULL) return createElem(t);
	else
	{
		while(l->next != NULL){l = l->next;}
		l->next = createElem(t);
		l->next->prev = l;
	}
	return tmp;
}

int listSize(List l)
{
	int s = 0;
	while(l != NULL){l = l->next; s++;}
	return s;
}

List lprv(List l){return l->prev;}

List lnxt(List l){return l->next;}


void exportNode(FILE *f, Tree t)
{
	if(t == NULL) return ;
	fprintf(f, "\"#%d\" [label=\"%s\"]\n\t", t->id, t->oper);
	if(t->left != NULL) fprintf(f, "\"#%d\" -- \"#%d\"\n\t", t->id, t->left->id);
	if(t->right != NULL) fprintf(f, "\"#%d\" -- \"#%d\"\n\t", t->id, t->right->id);
	exportNode(f, t->left);
	exportNode(f, t->right);
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
