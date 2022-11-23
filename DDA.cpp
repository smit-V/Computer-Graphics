#include<iostream>
#include<graphics.h>
using namespace std;
class dda{
	public:
		int x1,x2,y1,y2,len,xinc,yinc,x,y,dx,dy;
		
		void input(){
			cout<<"enter the coordinates of\nx1:";
			cin>>x1;
			cout<<"x2;";
			cin>>x2;
			cout<<"y1:";
			cin>>y1;
			cout<<"y2:";
			cin>>y2;
		}
		
		void set(){
			dx=x2-x1;
			dy=y2-y1;
			if(abs(dx)>abs(dy)){
				len=abs(dx);
				
			}
			else{
				len=abs(dy);
			}
			xinc=dx/len;
			yinc=dy/len;
			
			
			x=x1;
			y=y1;
			while(x<x2){
				putpixel(x,y,1);
				x+=xinc;
				y+=yinc;
				delay(10);
				
			}
		}
		
};
int main(){
	dda ob;
	initwindow(1000,1000);
	ob.input();
	ob.set();
	getch();
//	return 0;
}
