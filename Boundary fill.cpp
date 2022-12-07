#include<graphics.h>
#include<iostream>

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

int main()
{  
	void boundary_fill(int x,int y,int f,int b);
	
	/* int gdriver = DETECT, gmode;
	initgraph(&gdriver, &gmode, "C:\\TC\\BGI"); */
	initwindow(800,800);
	setcolor(getmaxcolor());
	
	circle(100, 100, 10);
	boundary_fill(100,100,4,15);
	
	getch();
	closegraph();
}
