#include <stdio.h>
#include <math.h>

int prime(int n)
{
	int i = 2;
	int rroot = (int)sqrt(n);

	while(i <= rroot)
	{
		if(n % i == 0)
			return 0;
		i++;
	}

	return 1;
}

int main()
{
	int n = 97;
	prime(n) ? printf("%d est premier !", n) : printf("%d n'est pas premier", n);
}
