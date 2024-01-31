#include<graphics.h>
#include<math.h>
#include<iostream.h>

#define MAXCOUNT 64

int main()
{

int count,i,j;
float xs,ys,left,top,xside,yside,x,y,x1,y1,mx,my,tempx;


initwindow(400,300);
left=-2.0;
top=1.5;
xside=4.0;
yside=-3.0;

//double t = 1.5, b = -1.5, l = -2.0, r = 2.0;
int res=10;


mx=getmaxx();my=getmaxy();
xs=xside/mx;
ys=yside/my;

for(j=1 ; j<my ; j+=res)
 {                    //go through each pixel
  for(i=1 ; i<mx ; i+=res)
  {
    x = i*xs + left;
    y = j*ys + top;
   
    for(count=0 ; count<30 ; count++)
      {
         x1 = x - 0.05 * sin(y + tan(3 * y));
         y1 = y - 0.05 * sin(x + tan(3 * x));
         x = x1;  y = y1;
         
//         cout<< x << "    " << y << endl;

         putpixel((int)((double)(x - left)/xs),(int)((double)(y - top)/ys), WHITE);
 
      }
   }
 }

while(!kbhit());
return 0;
}


