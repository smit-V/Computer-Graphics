#include<graphics.h>
#include<stdlib.h>
#include<iostream>
#include<conio.h>
#include<dos.h>
int main()
{  
	void boundary_fill(int x,int y,int f,int b);
	/* request auto detection */
	int gdriver = DETECT, gmode;
	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI");
	setcolor(getmaxcolor());

	/* draw the circle */
	circle(100, 100, 10);
	boundary_fill(100,100,4,15);

	/* clean up */
	getch();
	closegraph();
}
void boundary_fill(int x,int y,int f,int b)
{
	if(getpixel(x,y)!=b && getpixel(x,y)!=f)
	{
		putpixel(x,y,f);
		delay(10);
		boundary_fill(x+1,y,f,b);
		boundary_fill(x-1,y,f,b);
		boundary_fill(x,y+1,f,b);
		boundary_fill(x,y-1,f,b);
	}
}
