#include<stdio.h>
#include<graphics.h>
#include<pthreads.h>

struct data {
	int x1, int x2, int y1, int p;
};

int dx, dy;

void* draw(void* _arg){
        struct data* arg = _arg;
             int x = arg->x1;
             int x2 = arg->x2;
             int y = arg->y1;
             int p = arg->p; 
      while(x < x2)
      {
            x = x + 1;
            if(p < 0)
            {
                  p = p + 2 * dy;
            }
            else
            {
                  y = y + 1;
                  p = p + 2 * (dy - dx);
            }
            putpixel(x, y, 10);
      }
  return NULL;
}
void main()
{
      int gd = DETECT, gm;
      int end;
      float x1, x2, y1, y2, x, y;
      initgraph(&gd, &gm, NULL);
      printf("Enter Value of X1: ");
      scanf("%f", &x1);
      printf("Enter Value of Y1: ");
      scanf("%f", &y1);
      printf("Enter Value of X2: ");
      scanf("%f", &x2);
      printf("Enter Value of Y2: ");
      scanf("%f", &y2);

      dx = abs(x1 - x2);
      dy = abs(y1 - y2);
      
      if(x1 > x2)
      {
            x = x2;
            y = y2;
            end = x1;
      }
      else
      {
            x = x1;
            y = y1;
            end = x2;
      }
      putpixel(x, y, 10);

      int xm=(x1+x2)/2;

      pthread_t p1,p2;
      struct data d1 = {x,xm,y1,2*dy-dx};
      struct data d2 = {xm,end,y1,2*dy-dx};

      pthread_create(&p1,NULL,draw, &d1);
      pthread_create(&p2,NULL,draw, &d2);
      pthread_join(p1,NULL);
      pthread_join(p2,NULL);      
      getch();
      closegraph();
}