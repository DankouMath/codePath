#include "ppm.h"
#include <time.h>

typedef unsigned int color;

struct cv
{
	color col;
	point p[4];
};
typedef struct cv* curve;

PPM img;

int randi(int a, int b){ return (rand() % (b - a)) + a;}

color newColor(int r, int g, int b) { return ((r%256)<<16) + ((g%256)<<8) + (b%256); }

color randColor(){return newColor(randi(0,255), randi(0,255), randi(0,255));}

point cubebezier(point p0, point p1, point p2, point p3, float t)
{
	point p; float tt = 1 - t;
	p.x =  (int)(tt*tt*tt * p0.x + 3*t*tt*tt*p1.x + 3*t*t*tt*p2.x + p3.x*t*t*t );
	p.y =  (int)(tt*tt*tt * p0.y + 3*t*tt*tt*p1.y + 3*t*t*tt*p2.y + p3.y*t*t*t );
	
	return p;
}

curve initCurve(int WIDTH, int HEIGHT)
{
	int i;
	curve c = (curve)malloc(sizeof(struct cv));
	if(c == NULL) return c;
	for(i=0; i<4;i++)
	{	
		c->p[i].x = randi(0, WIDTH);c->p[i].y = randi(0, HEIGHT);
	}
	c->col = randColor();
	return c;
}

curve *initCurveTab(int nb, int WIDTH, int HEIGHT)
{
	int i;
	curve *tab = (curve*)malloc(sizeof(curve) * nb);
	if(tab == NULL) return tab;
	for(i=0;i<nb;i++)
	{
		tab[i] = initCurve(WIDTH, HEIGHT);
	}
	return tab;
}

void freecurvetab(curve *tab, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		free(tab[i]);
	}
	free(tab);
}

void drawCubBezier(PPM img, curve c)
{
	float t;
	point p; point pp = {c->p[0].x, c->p[0].y};
	
	for(t=0;t<1;t+=0.01)
	{
		p = cubebezier(c->p[0],c->p[1],c->p[2],c->p[3],t);
		ppmDrawLine(img, p, pp, c->col);
		pp = p;
	}
}

void drawCurveTab(PPM img, curve *tab, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		drawCubBezier(img, tab[i]);
	}
}

int main(int argc, char **argv)
{
	//Exécution: ./bezier WIDTH HEIGHT nbcurve
	
	const int WIDTH = atoi(argv[1]);
	const int HEIGHT = atoi(argv[2]);
	
	srand(time(NULL));
	
	int nbcurve = atoi(argv[3]);
	
	PPM img = ppmCreate("bezier.ppm", WIDTH, HEIGHT);
	curve *c = initCurveTab(nbcurve, WIDTH, HEIGHT);
	drawCurveTab(img,c,nbcurve);
	
	ppmExport(img);
	freecurvetab(c, nbcurve);
	ppmClose(img);
	return 0;
}
