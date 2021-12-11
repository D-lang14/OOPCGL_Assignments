// OOP CG Lab Assignment 9 :
// Write C++ program to generate fractal patterns by using Koch curves
// Compiler Used :- Turbo Cpp

#include <iostream.h>
#include <math.h>
#include <conio.h>
#include <stdlib.h>
#include <dos.h>
#include <graphics.h>

// Class KochCurve
class KochCurve
{
	// private specifier contains variables
private:
	int x1, y1, x5, y5, it;

	// public specifier
public:
	// koch member function
	void koch(int it, int x1, int y1, int x5, int y5)
	{
		int x2, y2, x3, y3, x4, y4;
		int dx, dy;
		if (it == 0)
		{
			line(x1, y1, x5, y5);
		}
		else
		{
			delay(10);
			// Dividing the line into 3 parts
			dx = (x5 - x1) / 3;
			dy = (y5 - y1) / 3;

			x2 = x1 + dx;
			y2 = y1 + dy;

			x3 = (int)(0.5 * (x1 + x5) + sqrt(3) * (y1 - y5) / 6);
			y3 = (int)(0.5 * (y1 + y5) + sqrt(3) * (x5 - x1) / 6);

			x4 = 2 * dx + x1;
			y4 = 2 * dy + y1;

			koch(it - 1, x1, y1, x2, y2);
			koch(it - 1, x2, y2, x3, y3);
			koch(it - 1, x3, y3, x4, y4);
			koch(it - 1, x4, y4, x5, y5);
		}
	}
};

// Main Function
int main()
{
	KochCurve k;
	int itr;
	char ch = 'y';
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

	cout << "\n |------------> Koch Curve <------------| \n";
	while (ch == 'y')
	{
		cout << "\tEnter Number Of Iterations : ";
		cin >> itr;

		// Side of triangle
		k.koch(itr, 240, 70, 110, 330);
		k.koch(itr, 370, 330, 240, 70);
		k.koch(itr, 110, 330, 370, 330);

		delay(3000);

		// Clearing screen
		clrscr();

		delay(30);

		cleardevice();
		cout << "\n Do you want to continue (y/n) ?: ";
		cin >> ch;
		if (ch == 'y')
		{
			continue;
		}
	}

	getch();
	closegraph();
	return 0;
}
