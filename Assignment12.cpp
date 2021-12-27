// Assignment 12:
// Write a C++ program to control a ball using arrow keys.
// Apply the concept of polymorphism
// Compiler Used :- Turbo cpp

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void main()
{
	// gm is Graphics mode which is a computer display mode that
    // generates image using pixels.
    // DETECT is a macro defined in "graphics.h" header file
	int gd = DETECT, gm, x, y, radii = 40;
	char ch;
	int running = 1;

	// initgraph initializes the graphics system by loading a graphics driver from disk
	initgraph(&gd, &gm, "C:/TURBOC3/BGI");

	// setbkcolor() sets the background color as 3 -> cyan
	setbkcolor(3);

	// getmaxx() function which returns the maximum X coordinate
	x = getmaxx() / 2;

	// getmaxy() function which returns the maximum Y coordinate
	y = getmaxy() / 2;

	setfillstyle(1, BLUE);
	circle(x, y, radii);
	// getmaxcolor() function, which returns maximum color value
	floodfill(x, y, getmaxcolor());

	while ((ch = getch()) != 113)
	{
		switch (ch)
		{

			// 72 is ASCII value of UP Arrow key
			case 72:
				if (y >= radii + 1)
				{
					cleardevice();
					circle(x, y -= 10, radii);
					floodfill(x, y, getmaxcolor());
				}
				break;

			// 80 is ASCII value of DOWN Arrow key
			case 80:
				
				if (y <= (getmaxy() - radii - 10))
				{
					cleardevice();
					circle(x, y += 10, radii);
					floodfill(x, y, getmaxcolor());
				}

			// 75 is ASCII value of LEFT Arrow key
			case 75:
				if (x >= radii + 1)
				{
					cleardevice();
					circle(x -= 10, y, radii);
					floodfill(x, y, getmaxcolor());
				}
				break;

			// 77 is ASCII value of RIGHT Arrow key
			case 77:
				
				if (x <= (getmaxx() - radii - 10))
				{
					cleardevice();
					circle(x += 10, y, radii);
					floodfill(x, y, getmaxcolor());
				}
				break;
			
			// 113 is ASCII value of q key
			case 113:
				// Here it exits the graph
				running = 0;
				closegraph();
		}
	}
	getch();
	// closegraph function closes the graphics mode and deallocates
    // all memory allocated by graphics system.
	closegraph();
}
