#include <graphics.h>
#include <dos.h>
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>

void Bresenham(int xa, int ya, int xb, int yb)
{
	int dx = abs(xa - xb), dy = abs(ya - yb);
	int p = 2*dy - dx;
	int twoDy = 2*dy, twoDyDx = 2*(dy - dx);
	int x, y, xEnd;
	/*Determine which points to start and End */
	if(xa>xb){
	   x = xb;
	   y = yb;
	   xEnd = xa;
	}
	else{
	  x = xa; y = ya ; xEnd =  xb;
	}
	putpixel(x, y, WHITE);
	while(x < xEnd){
	   x++;
	   if(p<0){
	     p = p + twoDy;
	   }
	   else{
	     y++;
	     p = p + twoDyDx;
	   }
	   putpixel(x,y,WHITE);
	}

}

int main()
{
    int gd=DETECT, gm, err;
    initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
    err = graphresult();
    if(err!=grOk){
	       printf(" error: %s\n", grapherrormsg(err));
    }
    Bresenham(100, 5, 200, 110);
    getch();
    return 0;
}
