#include <stdio.h>

int main(int argc, char **argv)
{
	const int WIDTH = 800;
	const int HEIGHT = 600;
	
	const float MIN_RE = -2;
	const float MAX_RE = 1;
	const float MIN_IM = -1;
	const float MAX_IM = 1;
	
	FILE *f;
	f = fopen("Mandelbrot.ppm","w");
	if(f==NULL) return -1;
	//Basic Info
	fprintf(f, "P3\n%d %d\n255\n", WIDTH, HEIGHT);
	
	int j,i;
	float a,b;
	float aa, bb, ca, cb;
	
	int maxiter = 50;
	int stoprad;
	float n;
	
	int color;
	
	for(j=0; j<HEIGHT; j++)
	{
		for(i=0; i<WIDTH; i++)
		{
			a = MIN_RE + (i/(float)WIDTH)*(MAX_RE-MIN_RE);
			b = MIN_IM + (j/(float)HEIGHT)*(MAX_IM-MIN_IM);
			
			stoprad = 0;
			n = 0;
			aa = 0;
			bb = 0;
			ca = a;
			cb = b;
			
			while(n < maxiter && !stoprad)
			{
				aa = a*a - b*b;
				bb = 2*a*b;
				
				a = aa + ca;
				b = bb + cb;
				if(a*a+b*b > 4)
				{
					stoprad = 1;
				}
				n++;
			}
			
			color = (int)(255 - (n/maxiter)*255);
			fprintf(f, "%d %d %d ", color, color, color);
		}
	}
	fprintf(f,"\n");
	fclose(f);
	return 0;
}
