#include <stdio.h>
#include <stdlib.h>

char *mostLongWord(char *str, int *wordlen)
{
	int i = 0;
	int len = 0;
	int lenmax = 0;
	int indicemax = 0;
	char *word;

	while(str[i] != '\0')
	{
		if(str[i] != ' '){len++;}
		else
		{
			if(len > lenmax)
			{ 
				lenmax = len;
				indicemax = i - (len);
			}
			len = 0;
		}
		
		i++;
	}

	if(len > lenmax)
	{ 
		lenmax = len;
		indicemax = i - (len);
	}

	*wordlen = lenmax;
	word = (char*)malloc(sizeof(char)*lenmax);
	if(word!=NULL)
	{
		i = 0;
		while(i<lenmax)
		{
			word[i] = str[indicemax + i];
			i++;
		}
	}
	
	return word;	
}

int main()
{
	int n;
	char *w = mostLongWord("hello everyone, it's time to party !", &n);

	printf("word:\"%s\"\ntaille: %d", w, n);

	return 0;
}
