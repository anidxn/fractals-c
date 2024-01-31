#include<math.h>
#include<graphics.h>

float rangle = 60 ;
float dtr=3.14159/180.0;
float rtd=180.0/3.14159;

class Point{
public:
 int X,Y;
 Point()
   { X=0; Y=0; }
 Point(int x1,int y1)
   {
	X=x1;Y=y1;
   }
};

void DrawTriangle(Point P1,Point P2,Point P3)
{
     line(P1.X,P1.Y,P2.X,P2.Y);
     line(P2.X,P2.Y,P3.X,P3.Y);
     line(P1.X,P1.Y,P3.X,P3.Y);
}

int FindTri(Point P1,Point P2,Point P3,int itr)
{
   if(itr==1)
    {
	return 0;
    }
    
    Point P4=Point(P1.X+(P2.X-P1.X)/2,P1.Y+(P2.Y-P1.Y)/2);
    Point P5=Point(P2.X+(P3.X-P2.X)/2,P2.Y+(P3.Y-P2.Y)/2);
    Point P6=Point(P3.X+(P1.X-P3.X)/2,P3.Y+(P1.Y-P3.Y)/2);
    DrawTriangle( P4, P5, P6);
    FindTri(P1,P4,P6,itr-1);
    FindTri(P4,P2,P5,itr-1);
    FindTri(P6,P5,P3,itr-1);
}

int main()
{
    int gd=DETECT,gm;
    initwindow(800,600);
    cleardevice();
    float len=400;
    Point P1(150,400);
    Point P2(P1.X+len*cos(60*dtr),P1.Y-len*sin(60*dtr));
    Point P3(P1.X+len,P1.Y);
    //Point P1(100,400),P2(200,100),P3(280,500);
    //Point P1(100,400),P2(100,100),P3(280,500);
    //Point P1(100,400),P2(100,100),P3(300,400);
    setcolor(9);
    DrawTriangle( P1, P2, P3);
    FindTri(P1,P2,P3,8);
   while(!kbhit());
}
