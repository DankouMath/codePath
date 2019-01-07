#include "binarytree.h"

//Donner explications
//

//considère : il n'a que des nombres pas de lettres
//et pas d'opé spéciales et pas de paenthèses


int isOper(char c)
{
	if(c == '+' || c == '-' || c == '*' || c == '/')
	{
		return 1;
	}
	if(c == '^')
	{
		return 1;
	}
	return 0;
}

int isParOp(char c)
{
	if(c == '(') return 1;
	return 0;
}

int isParCl(char c)
{
	if(c == ')') return 1;
	return 0;
}

int charIs(List l, char c)
{
	if(l == NULL) return 0;
	char oper = l->t->oper[0];
	return (oper == c);
}

List listBuild(char *expr)
{
	int i = 0;
	int k = 0;
	int item = 0;
	
	List list = NULL;
	char *buffer = (char*)malloc(sizeof(char)*strlen(expr));
	
	while(expr[i] != '\0')
	{
		if(expr[i] >= '0' && expr[i] <= '9')
		{
			while(expr[i] >= '0' && expr[i] <= '9')
			{
				buffer[k] = expr[i];
				i++;
				k++;
			}
			buffer[k] = '\0';
			list = insertEnd(list, createNode(buffer,item++));
			k = 0;
		}
		
		else if(isOper(expr[i]) || isParOp(expr[i])|| isParCl(expr[i]))
		{
			buffer[0] = expr[i];
			buffer[1] = '\0';
			
			list = insertEnd(list, createNode(buffer,item++));
			i++;
		}
		
		else{i++;}
		
	}
	free(buffer);
	return list;
}
 
void listPrint(List l)
{
	
	while(l != NULL)
	{
		printf("item: %s / id: %d\n", l->t->oper, l->t->id);
		l = l->next;
	}
	printf("\n");
}

void treePrint(Tree t)
{
	if(t == NULL) return ;
	printf("Noeud: %s\n", t->oper);
	if(t->left != NULL) printf("	fils: %s\n", t->left->oper);
	if(t->right != NULL) printf("	fils: %s\n", t->right->oper);
	treePrint(t->left);
	treePrint(t->right);
}

List listGather(List l)
{
	List prv;
	List nxt;	
	//Copie des arbres
	l->t->left = l->prev->t;
	l->t->right = l->next->t;
	//Sauvegarde du précédent;
	prv = l->prev;
	//Raccordement du précédents
	l->prev = l->prev->prev;
	if(l->prev != NULL) l->prev->next = l;
	//Efface du précédent
	free(prv);
	//Sauvegarde du suivant;
	nxt = l->next;
	//Raccordement du suivant(dans les suivants)
	l->next = l->next->next;
	if(l->next != NULL) l->next->prev = l;
	//Effacment du suivant
	free(nxt);
	
	return l;
}

List delPar(List l)
{
	List prv;
	List nxt;
	//Sauvegarde du précédent;
	prv = l->prev;
	//Raccordement du précédents
	l->prev = l->prev->prev;
	if(l->prev != NULL) l->prev->next = l;
	//Efface du précédent
	free(prv);
	//Sauvegarde du suivant;
	nxt = l->next;
	//Raccordement du suivant(dans les suivants)
	l->next = l->next->next;
	if(l->next != NULL) l->next->prev = l;
	//Effacment du suivant
	free(nxt);
	
	return l;
}

int prioOper(List l)
{
	//A penser si l'arbre à des feuilles, on peut le considérer comme un simple nombre
	// Et est donc de prio 0;
	if(l == NULL || hasSon(l->t)){return 0;}
	char oper = l->t->oper[0];
	
	if(oper == '+' || oper == '-'){return 1;}
	if(oper == '*' || oper == '/'){return 2;}
	if(oper == '^'){return 3;}
	return 0;
}

List treeBuild(List list)
{
	List start = list;
	List f = list;
	
	// /!\ si l'opérateur suivant n'est pas plus prio, alors c'est cool ! Simple ;)
	while(start->next != NULL)
	{
		if((prioOper(f) > 0)) // si opérateur et non parenthèse ...
		{
			//rassemblement
			if(prioOper(f) >= prioOper(lnxt(f)->next))
			{
				f = listGather(f);
			}
		}
					
		if(f->prev == NULL) start = f;
		f = f->next;
		if(f == NULL) f = start;
	}
	
	return start;
}

int main(int argc, char **argv)
{
	int size;
	char *str = *(argv+1);
	List l = listBuild(str);
	listPrint(l);
	l=treeBuild(l);
	listPrint(l);
	
	/*Export*/
	FILE* f = openDotFile("test.dot");
	exportNode(f, l->t);
	exportDotFile(f, l->t);

	return 0;
}
