#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <math.h>

int bezier (int pointx[10],int pointy[10])
{
    int c,d,k,i,sumx=0,sumy=0;
    double t,tag[4];
    double mat[4][4]={1,0,0,0,-3,3,0,0,3,-6,3,0,-1,3,-3,1};
    //int mat[5][5]={1,-4,6,-4,1,-4,12,-12,4,0,6,-12,6,0,0,-4,4,0,0,0,1,0,0,0,0};
    double multiplyx[5][5],multiplyy[5][5];
    for(d=0;d<4;d++){
	for(k=0;k<4;k++){
	    sumx=sumx+mat[k][d]*pointx[k];
	    sumy=sumy+mat[k][d]*pointy[k];
	}
	multiplyx[d][0] = sumx;
	multiplyy[d][0] = sumy;
	sumx = sumy = 0;
    }
    for(t=0.0;t<1.0;t+=0.0005){
	double c,d;
	c=t*t*t;d=t*t;
	tag[0]=c;tag[1]=d;tag[2]=t;tag[3]=1;
	for (k = 0; k < 4; k++) {
	    sumx = sumx + tag[k]*multiplyx[k][0];
	    sumy = sumy + tag[k]*multiplyy[k][0];
	    }
	    putpixel(sumx,sumy,10);
	    sumx = sumy = 0;
	}
	getch();
	closegraph();
	return 0;
}
void main()
{
    int i;
    int x[4], y[4];
    int gd=DETECT,gm;
    printf ("Enter the x- and y-coordinates of the four control points.\n");
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    for (i=0;i<4;i++){
    scanf ("%d%d", &x[i], &y[i]);
    }
    /*
    line(x[0],y[0],x[1],y[1]);
    line(x[1],y[1],x[2],y[2]);
    line(x[2],y[2],x[3],y[3]);
    */
    for (i = 0; i < 3;i++){
    	line(x[i],y[i],x[i+1],y[i+1]);
    	/* code */
    }

    bezier (x, y);
}