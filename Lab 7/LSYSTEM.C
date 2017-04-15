#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void draw(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4){
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x4,y4);
	line(x4,y4,x1,y1);
}


void main(){
	int gdriver=DETECT,gmode;
	int x,y,x1,y1,x2,y2,x3,y3,x4,y4,i,tempx,tempy;
	initgraph(&gdriver,&gmode,"C:\\TurboC3\\BGI");
	x=getmaxx();
	y=getmaxy();
	x1=0;
	y1=y/2;
	x2=x/2;
	y2=0;
	x3=x;
	y3=y/2;
	x4=x/2;
	y4=y;
	draw(x1,y1,x2,y2,x3,y3,x4,y4);
	for(i=0;i<12;i++){
		tempx=x1,tempy=y1;
		x1=(x1+x2)/2;
		y1=(y1+y2)/2;
		x2=(x2+x3)/2;
		y2=(y2+y3)/2;
		x3=(x3+x4)/2;
		y3=(y3+y4)/2;
		x4=(x4+tempx)/2;
		y4=(y4+tempy)/2;
		draw(x1,y1,x2,y2,x3,y3,x4,y4);
	}
	delay(9000);
}