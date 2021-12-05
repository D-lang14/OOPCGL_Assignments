// OOP CG Lab Assignment 5 :
// Write C++ program to implement Cohen Southerland line clipping algorithm.
// Compiler used :- Turbo C++

#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>

// Typedef structure named edge
typedef struct edge{
	int x, y;
}edge;

// Base class named Shape
class Shape {
	// Protected specifier
	protected:
		int vertex, xmin, ymin, xmax, ymax;
		int internal[20], x, y;
		// edge structure 
		edge e[20];

	public:
		int c, color, pattern;
		// Public member functions
		void readvertices();
		void display();
		// Pure virtual functions are used 
		// to define these functions in derived class
		// So, that they can get access to base class protected variables
		virtual void fillPolygon(float) = 0;
		virtual void sortEndpoints(float) = 0;
};

// Derived class Polygon 
// Inherited from base class Shape as public specifier
class Polygon: public Shape{
	public:
		void fillPolygon(float);
		void sortEndpoints(float);
		void findingIntersections();
};

// Read vertices function of base class
void Shape::readvertices(){
	int i;
	cout<<"\n\t\t\tSCANLINE POLYGON FILL ALGORITHM\n";
	cout<<"\n\tEnter number of vertices: ";
	cin>>vertex;
	if(vertex > 2)
	{
		for(i=0; i<vertex; i++)
		{
			cout<<"\n\tEnter the co-ordinate of vertices "<<i+1<<" : ";
			cout<<"\n\tx"<<(i+1)<<": ";
			cin>>e[i].x;
			cout<<"\n\ty"<<(i+1)<<": ";
			cin>>e[i].y;
		}
		e[i].x = e[0].x;		
		e[i].y = e[0].y;
		xmin = xmax = e[0].x;		
		ymin = ymax = e[0].y;
	}
	else{
		cout<<"\n\tEnter valid number of vertices";
	}
}

// Fill polygon funtion is our pure virtual function 
// of base class defined in derived class
void Polygon::fillPolygon(float z){
	int i, j;
//	Drawing a line of a polygon
	for(i=0; i<vertex; i++)
	{
		line(e[i].x, e[i].y, e[i+1].x, e[i+1].y);
	}
	delay(100);
//	Filling the polygon
	for(i=0; i<c; i+=2)
	{
		delay(100);
		line(internal[i],z,internal[i+1],z);
	}
}

// Sorting of Endpoints funtion is our pure virtual function 
// of base class defined in derived class

// z = incrementing Value from ymax to ymin to fill color

void Polygon::sortEndpoints(float z){ 
	int i, x1, y1, x2, y2, temp;
	c = 0;
	for(i=0; i<vertex; i++)
	{
		x1 = e[i].x; 
		y1 = e[i].y; 
		x2 = e[i+1].x; 
		y2 = e[i+1].y;  
		
		if(y2 < y1)
		{
			temp = x1;
			x1 = x2;
			x2 = temp;
			
			temp = y1;
			y1 = y2;
			y2 = temp;
		}
		
		if(z <= y2 && z >= y1)
		{
			if((y1 - y2) == 0)
				x = x1;
				
			// Used to make changes in x, so that we can fill our polygon after certain distance
			else
			{
				x = ((x2 - x1) * (z - y1)) / (y2 - y1); 
				x += x1; 
			}
			if(x <= xmax && x >= xmin)
				internal[c++] = x;
		}
	}
}

// Display function of base class
void Shape::display()
{

	int choice, pattern, color;
	float s;
	char choice1 = 'y';
	cout<<"\n\t\t\tSCANLINE POLYGON FILL ALGORITHM\n";
	do{
		cout<<"\n\nMenu: ";
		cout<<"\n\n\t1. Choose any pattern and colour";
		cout<<"\n\n\t2. Scan-line fill algorithm";
		cout<<"\n\n\t3. Exit";
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		// Switch case is used to give choices as per user
		switch(choice)
		{
			case 1:
				cout<<"\n\tEnter the colour you want (0-15) : ";
				cin>>color;
				setcolor(color);
				break;

			case 2:
				s = ymin + 0.01;
				delay(100);
				cleardevice();
				while(s <= ymax)	
				{
					sortEndpoints(s);
					fillPolygon(s);
					s++;
				}
				cout<<"\nScanline filling complete\n\n";
				break;

			case 3:
				exit(0);
		}
		cout<<"Do you want to continue (y/n) ?: ";
		cin>>choice1;
	}while(choice1=='y' || choice1=='Y');
}

// Finding Intersections function of derived class
void Polygon::findingIntersections()
{
	int i;
	for(i=0; i<vertex; i++)
	{
		if(xmin > e[i].x)
			xmin = e[i].x;
		if(xmax < e[i].x)
			xmax = e[i].x;
		if(ymin > e[i].y)
			ymin = e[i].y;
		if(ymax < e[i].y)
			ymax = e[i].y;
	}
}

// Main Function
int main()
{
	int gd = DETECT, gm;
	initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");
	cleardevice();
	Polygon poly;
	poly.readvertices();
	poly.findingIntersections();
	cleardevice();
	poly.display();
	closegraph();
	return 0;
}

// Example inputs:
// 200 300
// 300 400
// 200 400
// 300 300
