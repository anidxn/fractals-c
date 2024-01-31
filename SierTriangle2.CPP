#include<graphics.h>

int main()
{
	char Direct;
	long iterate;
	unsigned int x1, y1, x2, y2;
	
	initwindow(800,800);

	x1 = x2 = 320;
	y1 = y2 = 0;

	for(iterate = 0; iterate < 100000; iterate++)
	{
		Direct = rand()%3;

		if(Direct == 0)
		{
			x1 = (x2 + 320) / 2;
			y1 = (y2 + 0) / 2;
		}
		else if(Direct == 1)
		{
			x1 = (x2 + 0) / 2;
			y1 = (y2 + 480) / 2;
		}
		else if(Direct == 2)
		{
			x1 = (x2 + 640) / 2;
			y1 = (y2 + 480) / 2;
		}
		putpixel(x1, y1, WHITE);

		x2 = x1;
		y2 = y1;
	}
    while(!kbhit());
    return 0;
}
