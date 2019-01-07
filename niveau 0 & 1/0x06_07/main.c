#include "binarytree.h"

int main()
{
	Tree t = NULL;
    t = insertNode(t, 3);
	t = insertNode(t, 4);
	t = insertNode(t, 1);
	t = insertNode(t, 6);	
	
	FILE *f = openDotFile("01.gv");
	exportNode(f, t);
	searchNode(f, t, 3);
	exportDotFile(f, t);
	
	return 0;
}
