#include<graphics.h>
#include<math.h>
#include<iostream.h>

/*
int main()
{
    initwindow(400,400);
    int xc=200,yc=200;
    int x1,y1,x2,y2;
    float L=100,l;
    
    for(int ang=30 ; ang<=330 ; ang+=60)
      {
          x1=xc + L*cos(ang*3.14159/180);
          y1=yc - L*sin(ang*3.14159/180);
          
          x2=xc + L*cos((ang+60)*3.14159/180);
          y2=yc - L*sin((ang+60)*3.14159/180);
          line(x1,y1,x2,y2);
          getch();
      }
    
    l=L*sqrt(3)/2; //trigonmetri math
    
    for(int ang=0 ; ang<=300 ; ang+=60)
      {
          x1=xc + l*cos(ang*3.14159/180);
          y1=yc - l*sin(ang*3.14159/180);
          
          x2=xc + (L/2)*cos((ang+90)*3.14159/180);
          y2=yc - (L/2)*sin((ang+90)*3.14159/180);
          line(x1,y1,x2,y2);
          getch();
      }
    
    while(!kbhit());
    return 0;
}*/

int main()
{
    int ch;
    cout<<"Enter ur choice [1 or 2] : "; cin>>ch;

    initwindow(800,800);
    int xc=400,yc=400;
    int x1,y1,x2,y2;
    float L=350,l;

    while(L>=5)
    {
    setcolor(10);
    for(int ang=30 ; ang<=330 ; ang+=60)
      {
          x1=xc + L*cos(ang*3.14159/180);
          y1=yc - L*sin(ang*3.14159/180);
          
          x2=xc + L*cos((ang+60)*3.14159/180);
          y2=yc - L*sin((ang+60)*3.14159/180);
          line(x1,y1,x2,y2);
      }
    
    l=L*sqrt(3)/2; //trigonmetri math
    setcolor(14);
    for(int ang=0 ; ang<=300 ; ang+=60)
      {
          x1=xc + l*cos(ang*3.14159/180);
          y1=yc - l*sin(ang*3.14159/180);
          
          x2=xc + (L/2)*cos((ang+90)*3.14159/180);
          y2=yc - (L/2)*sin((ang+90)*3.14159/180);
          line(x1,y1,x2,y2);
          delay(50);
      }
     
     if(ch==1)
         L=l;  //Graphics 1
     else
         L=L/2; //Graphics 2
    }
    while(!kbhit());
    return 0;
}
