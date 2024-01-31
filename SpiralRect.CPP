#include<graphics.h>
#include<math.h>

#define pi 3.14159

int main()
{
    int ang,a1,i,xc=300,yc=300,x[4],y[4];
    float l=200.0;
    initwindow(600,600);
    ang=0;
    setcolor(9);
    while(l>=2)
    {
       a1=45+ang;
       for(i=0 ; i<=3 ; i++)
        {
           x[i]=xc+l*cos(a1*pi/180);
           y[i]=yc-l*sin(a1*pi/180);
           a1+=90;
        }
        line(x[0],y[0],x[1],y[1]);
        line(x[1],y[1],x[2],y[2]);
        line(x[2],y[2],x[3],y[3]);
        line(x[3],y[3],x[0],y[0]);
       ang+=3;//10
       l=l*0.95;//88
       delay(50);
    }
    getch();
    return 0;
}
