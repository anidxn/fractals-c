/*																						*/
/*						L-System Fractals											*/
/*						Written By Mithun Aiyswaryan							*/
/*						Master Student @ University Of Kiel					*/
/*						Please Drop Me An E-Mail At							*/
/*						s.mithun@indiatimes.com									*/
/*																						*/
/*						Tip: Use Turbo C++ For Execution						*/
/*						Also set the path of your graphics enviromment	*/
/*																						*/
/*																						*/

#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
#include<stdlib.h>

#define rads 0.0174

int x=280,y=350,j=0;
int numbranch[17]={4,3,3,3,3,4,3,3,4,2,3,3,4,4,4,4};
float spreadratio[17]={2,1,1,1.25,1.25,1.25,1.5,1.5,1.5,1,1,1,1,1,2,1};
float lenratio[17]={0.5,0.75,0.5,0.75,0.5,0.5,0.75,0.5,0.5,0.5,0.5,0.625,0.625,0.5,0.5,0.5};

int drawtree(int x1,int y1,float a,float l,float f,int n);

void main(){
int gd,gm;
detectgraph(&gd,&gm);
initgraph(&gd,&gm,"c:\\tc\\bgi");
label:
cleardevice();
drawtree(x,y,300,150,180,10);
if(j>=18)
{exit(0);}
else{
j++;
goto label;
}
getch();
closegraph();
}

drawtree(int x1,int y1,float a,float l,float f,int n){
int i,num,x2,y2;
float delang,ang;

if(n>0)
{
x2=x1+l*cos(rads*a);
y2=y1+l*sin(rads*a);
setcolor(30);
line(x1,y1,x2,y2);
num=numbranch[j];

	if(num>1)
	delang=f/(num-1);
	else
	delang=0;
	ang=a-f/2-delang;

	for(i=1;i<=num;i++){
	ang+=delang;
	drawtree(x2,y2,ang,l*lenratio[j],f*spreadratio[j],n-1);
	}
	}
	else
	{
	setcolor(20);
	ellipse(x2,y2,0,276,2,4);
if( ( (numbranch[j]==4)&&(spreadratio[j]==1.25)&&(lenratio[j]==0.5)||( (numbranch[j]==3)&&(spreadratio[j]==1.5)&&(lenratio[j]==0.75) )||( (numbranch[j]==3)&&(spreadratio[j]==1.5)&&(lenratio[j]==0.5) ) ) )
{
goto hi;
}
else{
	fillellipse(x2,y2,2,4);}
	hi:
	}
	return 0;

}
