#include <stdio.h>

int tabSum(int *t, int len)
{
	int n,i;

	n = 0;
	for(i=0;i<len;i++)
		n+=t[i];
	return 	n;
}

int main()
{

	int n[5] = {5,5,5,5,5};
	printf("Somme: %d\n", tabSum(n, 5));
	return 0;
}
