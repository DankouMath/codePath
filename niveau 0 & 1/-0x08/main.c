#include <stdio.h>
#include <string.h>

//Donner explications
//

char prevChar(char *str, int pos)
{
	int i = pos - 1;
	while(i > 0 && str[i] == ' ') i--;
	if(i < 0) return str[0];
	return str[i];
}

char nextChar(char *str, int pos)
{
	int i = pos + 1;
	while(str[i] != '\0' && str[i] == ' ') i++;
	if(str[i] == '\0') return str[i-1];
	return str[i];
}


int main(int argc, char **argv)
{
	char *str = *(argv+1);
	int i = 0;

	int nbparouv = 0;
	int nbparferm = 0;
	int err = 0;

	while(str[i] != '\0' && !err)
	{
		
		if(str[i] == '(')
		{
			nbparouv++;
			if(nextChar(str,i) == '+' || nextChar(str,i) == '-'|| nextChar(str,i) == '*' || nextChar(str,i) == '/')
			{
				err = 1;
			}

		}

		if(str[i] == ')')
		{
			nbparferm++;
			if(prevChar(str,i) == '+' || prevChar(str,i) == '-' || prevChar(str,i) == '*' || prevChar(str,i) == '/')
			{
				err = 1;
			}
			if(nbparferm > nbparouv) err = 1;
		}

		i++;
	}

	if(err || (nbparouv != nbparferm)) {printf("Parenthèses INcorrectes");}

	else {printf("Parenthèses CORrectes");}

	return 0;
}
