// OOP CG Lab Assignment 8 :
// Write C++ program to implement Cohen Southerland line clipping algorithm.
// Compiler used :- Turbo C++

#include <iostream.h>
#include <stdlib.h>
#include <math.h>
#include <graphics.h>
#include <dos.h>

// Class coordinate contains code and variable
class Coordinate
{
public:
	int x, y;
	char code[4];
};

// Class lineclip contains functions
class Lineclip : public Coordinate
{
	int i;

public:
	void drawwindow();
	void drawline(Coordinate p1, Coordinate p2);
	Coordinate setcode(Coordinate p);
	int visibility(Coordinate p1, Coordinate p2);
	Coordinate resetendpt(Coordinate p1, Coordinate p2);
};

// Drawing window
void Lineclip::drawwindow()
{
	line(150, 100, 450, 100);
	line(450, 100, 450, 350);
	line(450, 350, 150, 350);
	line(150, 350, 150, 100);
}

// Drawing line as per user inputs
void Lineclip::drawline(Coordinate p1, Coordinate p2)
{
	line(p1.x, p1.y, p2.x, p2.y);
}

// Setting code of points
Coordinate Lineclip::setcode(Coordinate p)

{
	// It is a temperary object
	Coordinate ptemp; 

	if (p.y < 100)
		ptemp.code[0] = '1';
	else
		ptemp.code[0] = '0';

	if (p.y > 350)
		ptemp.code[1] = '1';
	else
		ptemp.code[1] = '0';

	if (p.x > 450)
		ptemp.code[2] = '1';
	else
		ptemp.code[2] = '0';

	if (p.x < 150)
		ptemp.code[3] = '1';
	else
		ptemp.code[3] = '0';

	ptemp.x = p.x;
	ptemp.y = p.y;

	return (ptemp);
};

// Visibility check
int Lineclip::visibility(Coordinate p1, Coordinate p2)
{
	int flag = 0; 

	for (i = 0; i < 4; i++)
	{
		if (p1.code[i] != '0' || (p2.code[i] == '1'))
			flag = '0';
	}

	if (flag == 0)
		return (0);

	for (i = 0; i < 4; i++)
	{
		if (p1.code[i] == p2.code[i] && (p2.code[i] == '1'))
			flag = '0';
	}

	if (flag == 0)
		return (1);

	return (2);
}

// Resetting end points
Coordinate Lineclip::resetendpt(Coordinate p1, Coordinate p2)
{
	Coordinate temp;
	int x, y, i;
	float m, k;

	if (p1.code[3] == '1')
		x = 150;
	if (p1.code[2] == '1')
		x = 450;
	if ((p1.code[3] == '1') || (p1.code[2]) == '1')
	{
		m = (float)(p2.y - p1.y) / (p2.x - p1.x);
		k = (p1.y + (m * (x - p1.x)));
		temp.y = k;
		temp.x = x;

		for (i = 0; i < 4; i++)
			temp.code[i] = p1.code[i];

		if (temp.y <= 350 && temp.y >= 100)
			return (temp);
	}

	if (p1.code[0] == '1')
		y = 100;
	if (p1.code[1] == '1')
		y = 350;
	if ((p1.code[1] == '1') || (p1.code[1] == '1'))
	{
		m = (float)(p2.y - p1.y) / (p2.x - p1.x);
		k = (float)p1.x + (float)(y - p1.y) / m;
		temp.x = k;
		temp.y = y;

		for (i = 0; i < 4; i++)
			temp.code[i] = p1.code[i];

		return (temp);
	}
	else
		return (p1);
}

// Main menu
int main()
{
	Lineclip lc;
	int gd = DETECT, v, gm;
	Coordinate p1, p2, p3, p4, ptemp;

	cout << "\n |-----------> Cohen Sutherland Line Clipping Algorithm <-----------| \n";
	cout << "\n Enter coordinates of line \n" cout << "\n Enter x1 and y1: ";
	cin >> p1.x >> p1.y;
	cout << "\n Enter x2 and y2: ";
	cin >> p2.x >> p2.y;

	initgraph(&gd, &gm, "C:/TurboC3/BGI");
	lc.drawwindow();
	delay(10);

	lc.drawline(p1, p2);
	delay(10);
	cleardevice();

	delay(10);
	p1 = lc.setcode(p1);
	p2 = lc.setcode(p2);
	v = lc.visibility(p1, p2);
	delay(10);

	switch (v)
	{
	case 0:
		lc.drawwindow();
		lc.drawline(p1, p2);
		delay(10);
		break;
	case 1:
		lc.drawwindow();
		delay(2000);
		break;
	case 2:
		p3 = lc.resetendpt(p1, p2);
		p4 = lc.resetendpt(p2, p1);
		lc.drawwindow();
		lc.drawline(p3, p4);
		delay(10);
		break;
	}
	delay(10);
	closegraph();
	return 0;
}
