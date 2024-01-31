#include<graphics.h>
#include<math.h>

#define MAXCOUNT 64

int main()
{

int x,y,count;
float xs,ys,left,top,xside,yside,zx,zy,cx,cy,mx,my,tempx;
int color[4];
//arrange from dark to white
color[0]=0;
color[1]=8;
color[2]=7;
color[3]=15;

initwindow(600,480);
left=-1.5;
top=-1.5;
xside=3.0;
yside=3.0;

mx=getmaxx();my=getmaxy();
xs=xside/mx;
ys=yside/my;
cx=0.285; cy=0.01;

for(y=1;y<=my-1;y++)
 {                    //go through each pixel
  for(x=1;x<=mx-1;x++)
  {
    zx=x*xs+left;
    zy=y*ys+top;
    count=0;
     while((zx*zx + zy*zy< 4) && (count<MAXCOUNT))
      {
        tempx=zx*zx -zy*zy+cx;
        zy=2*zx*zy +cy;
        zx=tempx;
        count=count+1;
      }
     //all bove thing is used to know color val of the scanning pixel by "count"
     
     if(count==MAXCOUNT)
        putpixel(x,y,WHITE);
     else
        putpixel(x,y,BLACK);
       // putpixel(x,y,count%16);
  }
 }
while(!kbhit());
}
