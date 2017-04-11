#include<graphics.h>
#include<conio.h>

int main() {
	int gd = DETECT, gm, x, y;
	int i,total=0,elements;
	int startangle[20],endangle[20],data[20];

	printf("Enter the number of elements:");
	scanf("%d",&elements);
	
	for(i=0;i<elements;i++){
		printf("Enter the %d elements \n",i+1);
		scanf("%d",&data[i]);
	}
	
	for(i=0;i<elements;i++){
		total=total+data[i];
	}
	startangle[0]=0;
	
	for(i=0;i<elements;i++){
		endangle[i]=startangle[i]+((data[i]*360)/total);
		startangle[i+1]=endangle[i];
	}
	
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	settextstyle(BOLD_FONT,HORIZ_DIR,2);
	outtextxy(220,10,"PIE CHART");
	
	x = getmaxx()/2;
	y = getmaxy()/2;

	settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);

	for(i=0;i<elements;i++){
		setfillstyle(SOLID_FILL,i+1);
		pieslice(x, y, startangle[i],endangle[i], 120);
	}
	
	getch();
	closegraph();
	return 0;
}