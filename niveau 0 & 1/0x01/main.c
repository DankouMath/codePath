#include <stdio.h>

int tabSumP(int *t, int len)
{
	int n,i;

	n = 0;
	for(i=0;i<len;i+=2)
		n+=t[i];
	return 	n;
}

int tabSumI(int *t, int len)
{
	int n,i;

	n = 0;
	for(i=1;i<len;i+=2)
		n+=t[i];
	return 	n;
}

int main()
{

	int n[5] = {4,5,7,5,9};
	printf("Somme Pair: %d\n Somme Impair: %d", tabSumP(n, 5), tabSumI(n, 5));
	return 0;	
}
