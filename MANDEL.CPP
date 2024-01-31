#include<graphics.h>
#include<math.h>

#define MAXCOUNT 64

int main()
{

int x,y,count;
float xs,ys,left,top,xside,yside,zx,zy,cx,cy,mx,my,tempx;

initwindow(400,300);
left=-2.2;//-1.75;
top=-1.2;//-0.25;                  /*change values 2 Zoom in/out any part*/
xside=3.2;//1.15;
yside=2.4;//0.45;

mx=getmaxx();my=getmaxy();
xs=xside/mx;
ys=yside/my;

for(y=1;y<=my-1;y++)
 {                    //go through each pixel
  for(x=1;x<=mx-1;x++)
  {
    cx=x*xs+left;
    cy=y*ys+top;
    zx=0;  //real part of an imaginary number
    zy=0;  //imaginary part of an imaginary number
    count=0;
     while((zx*zx + zy*zy< 4) && (count<MAXCOUNT))
      {
        tempx=zx*zx -zy*zy+cx;
        zy=2*zx*zy +cy;
        zx=tempx;
        count=count+1;
      }
     //all bove thing is used to know color val of the scanning pixel by "count"
    putpixel(x,y,count%16); //fill each pixel with color
  }
 }

while(!kbhit());
}
