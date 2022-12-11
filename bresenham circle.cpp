// 1
// C-program for circle drawing
// using Bresenham’s Algorithm
// in computer-graphics
#include <stdio.h>
#include <dos.h>
#include <graphics.h>

// Function to put pixels
// at subsequence points
void drawCircle(int xc, int yc, int x, int y)
{
	putpixel(xc+x, yc+y, RED);
	putpixel(xc-x, yc+y, RED);
	putpixel(xc+x, yc-y, RED);
	putpixel(xc-x, yc-y, RED);
	putpixel(xc+y, yc+x, RED);
	putpixel(xc-y, yc+x, RED);
	putpixel(xc+y, yc-x, RED);
	putpixel(xc-y, yc-x, RED);
}

// Function for circle-generation
// using Bresenham's algorithm
void circleBres(int xc, int yc, int r)
{
	int x = 0, y = r;
	int d = 3 - 2 * r;
	drawCircle(xc, yc, x, y);
	while (y >= x)
	{
		// for each pixel we will
		// draw all eight pixels
		
		x++;

		// check for decision parameter
		// and correspondingly
		// update d, x, y
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		drawCircle(xc, yc, x, y);
		delay(50);
	}
}


// Driver code
int main()
{
	int xc = 50, yc = 50, r = 30;
	int gd = DETECT, gm;
	initgraph(&gd, &gm, ""); // initialize graph
	circleBres(xc, yc, r); // function call
	return 0;
}



// 2
#include<iostream>
#include<graphics.h>
using namespace std;
class bresh
{
	public:
		int xc,yc,x,y,r,d;
		void input()
		{
			cout<<"Enter the coordinates :";
			cin>>xc>>yc;
			cout<<"Enter the Radius:";
			cin>>r;
		}
		void drawcircle()
		{
			putpixel(xc+x,yc+y,5);
			putpixel(xc-x,yc+y,5);
			putpixel(xc-x,yc-y,5);
			putpixel(xc+x,yc-y,5);
			putpixel(xc+y,yc+x,5);
			putpixel(xc+y,yc-x,5);
			putpixel(xc-y,yc-x,5);
			putpixel(xc-y,yc+x,5);
		}
		void breshcircle()
		{
			x=0;
			y=r;
			d=3-2*r;
			drawcircle();
			
			while(y>=x)
			{
				x++;
				if(d>0)
				{
					y--;
					d=d+4*(x-y)+10;
				}
				else
				{
					d=d+4*x+6;
				}
				 drawcircle();
				 delay(10);
			}
			
		}
};

int main()
{

	bresh obj;
	obj.input();
	initwindow(1000,1000);
	obj.breshcircle();
	getch();
	return 0;
}
