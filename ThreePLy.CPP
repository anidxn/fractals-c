#include<graphics.h>
#include<math.h>

int main()
{

int count,i,j;
float xs,ys,left,top,xside,yside,x,y,x1,y1,mx,my;


initwindow(400,300);
left=-2816.0;
top=2112.0;
xside=5632;
yside=-4224;

/*double t , b , l , r ;
t = 2112.0; b = -2112.0; l = -2816.0; r = 2816.0;*/
double d=-55,e=-1,f=-42;
int res=40;
int dots=2500;


mx=getmaxx();my=getmaxy();
xs=xside/mx;
ys=yside/my;
j=150;

  for(i=70;i<mx-70;i+=res)
  {
    x = i*xs + left;
    y = j*ys + top;
    
    /* x = (double)i / mx * (r - l) + l;
     y = (double)j / my * (b - t) + t;*/
   
    for(count=0 ; count<dots ; count++)
      {
         int sgn = (x>0)?1:(x<0)?-1:0;

         x1 = y - sgn*abs(sin(x)*cos(e) + f - x*sin(d + e + f));
         y1 = d - x;
         
         x = x1;  y = y1;

         putpixel((int)((x - left)/xs),(int)((y - top)/ys), i/res);
         //putpixel((int)((double)(x - l) / (r - l) * mx),(int)((double)(y - t) / (b - t) * my), i/res);
      }
}


while(!kbhit());
return 0;
}
