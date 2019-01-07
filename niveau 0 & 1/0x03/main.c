#include <stdio.h>

void freqAscii(char *filename)
{
	int c;
	int i;
	int freqchar[128] = {0};

	FILE* f = fopen(filename, "r");
	if(f!=NULL)
	{
		while((c=fgetc(f))!= EOF)
		{
			freqchar[c]++;
			printf("char: \"%c\"\n", c);
		}	

		for(i=0; i<128; i++)
		{
			if(freqchar[i] > 0)
			{
				printf("char: %c freq: %d\n", i, freqchar[i]);
			}
		}
	}

}

int main()
{
	freqAscii("test.txt");
	return 0;
}
