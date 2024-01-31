/*					*/
/* 	Julia Fractals	*/
/*	Written By Mithun Aiyswaryan	*/
/*	Master Student @ University Of Kiel	*/
/*	Please Drop Me An E-Mail At		*/
/*	s.mithun@indiatimes.com		*/

/*	Tip: Use Turbo C++ For Execution	*/
/*	Also set the path of your graphics enviromment	*/

#include <graphics.h>
#include <conio.h>

  int sx;				//X-Axis resolution
  int sy;           //Y-Axis resolution
  double xmin=-2;
  double xmax=1.25;
  double ymin=-1.25;
  double ymax=1.25;
  double maxiter=512;	// Maximum number of iterations
  double ix=0.42;
  double iy=0.23;

void main()
{
  double old_x;
  double fx,fy;
  int m,gd,gm;
  double dx,dy;
  int px;
  int py=0;
  double x;
  double y=ymin;

detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\tc\\bgi");
cleardevice();
sx=getmaxx(); sy=getmaxy();
dx=(xmax-xmin)/sx;
dy=(ymax-ymin)/sy;

  while (py<sy) {
	 px=0;
	 x=xmin;
	 py++;
	 while (px<sx) {
		px++;

		fx=x;  //Xmin +dx +dx +....
		fy=y;  //Ymin
		m=0;   //prepare for iteration
		do {
		  old_x=fx;
		  fx= fx*fx - fy*fy + ix;
		  fy= 2* old_x * fy + iy;
		  m++;
		} while (((fx*fx+fy*fy)<4) && (m<maxiter));
	 putpixel(px,py,m);
	 x+=dx;
	 }
  y+=dy;
  }
  getch();
closegraph();

}