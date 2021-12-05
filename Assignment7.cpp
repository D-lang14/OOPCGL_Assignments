// OOP CG Lab Assignment 7:
// Write C++ program to implement translation, rotation and scaling transformations on
// equilateral triangle and rhombus. Apply the concept of operator overloading.
// Compiler used :- Turbo C++

#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>

class Transformation
{
	// Variables which member functions can use as
	// it is privately specified in this class
	float A[20][3];
	float rotangle;
	int i, j, k, n, tx, ty, sx, sy, angle;

	// Member functions of class transformation
	// Public specifier
public:
	void getVertices();
	void unit();
	void translation();
	void scaling();
	void rotation();
	Transformation operator*(Transformation x);
	void display();
};

// Taking vertex inputs from user from this function
void Transformation ::getVertices()
{
	cout << "\nEnter the number of vertices: ";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cout << "\n enter the values of (x" << i + 1 << ",y" << i + 1 << "): ";
		cin >> A[i][0] >> A[i][1];
		A[i][2] = 1;
	}
}

// * Operator overloading
Transformation Transformation ::operator*(Transformation x)
{
	// Multiplication of 2 matrix
	Transformation mul;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < 3; j++)
		{
			mul.A[i][j] = 0;
			for (k = 0; k < 3; k++)
			{
				mul.A[i][j] = mul.A[i][j] + (A[i][k] * (x.A[k][j]));
			}
		}
	}
	mul.n = n;
	return mul;
}

// Funtion to make matix and program will work accordingly
void Transformation ::unit()
{
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == j)
				A[i][j] = 1;
			else
				A[i][j] = 0;
		}
	}
}

// Function of translation
void Transformation ::translation()
{
	cout << "\nEnter the value of tx and ty: ";
	cin >> tx >> ty;
	A[2][0] = tx;
	A[2][1] = ty;
}

// Function of scaling
void Transformation ::scaling()
{
	cout << "\nEnter the value of sx and sy: ";
	cin >> sx >> sy;
	A[0][0] = sx;
	A[1][1] = sy;
}

// Function of rotation
void Transformation ::rotation()
{
	cout << "\nEnter the value of angle: ";
	cin >> angle;
	rotangle = ((3.142) / (180)) * angle;
	A[0][0] = A[1][1] = cos(rotangle);
	A[1][0] = -sin(rotangle);
	A[0][1] = sin(rotangle);
}

// Function to display axis and user put inputs accordingly
void Transformation ::display()
{
	// Creating x axis and y axis line
	line(320, 0, 320, 480);
	line(0, 240, 640, 240);
	for (i = 0; i < n - 1; i++)
		line(A[i][0] + 320, 240 - A[i][1], A[i + 1][0] + 320, 240 - A[i + 1][1]);
	line(A[n - 1][0] + 320, 240 - A[n - 1][1], A[0][0] + 320, 240 - A[0][1]);
}

// Main function
int main()
{
	// Objects been created
	Transformation trans, trf, result;
	// Few variables
	int gd = DETECT, gm, i, ch;
	char ans;
	// Here is the do while loop to iterate thorugh menu
	do
	{
		clrscr();
		// Here is the menu
		cout << "\n************TRANSFORMATIONS************";
		cout << "\n 1. Translation";
		cout << "\n 2. Scaling";
		cout << "\n 3. Rotation";
		cout << "\n 4. Exit;";
		cout << "\nEnter your choice: ";
		cin >> ch;
		initgraph(&gd, &gm, "C:\\TURBOC3\\BGI");

		// Switch case to program according to user's need
		switch (ch)
		{
		case 1:
			//  Taking input from user so calling the member function of class
			trans.getVertices();
			cleardevice();

			// displaying before transformating diagram
			cout << "\nBefore transformation ";
			trans.display();
			getch();
			cleardevice();

			// Creating matrix 
			// and taking input of translating coefficient 
			// and then displaying after transforming
			trf.unit();
			trf.translation();
			result = trans * trf;
			result.display();
			break;

		case 2:
			//  Taking input from user so calling the member function of class
			trans.getVertices();
			cleardevice();

			// displaying before transformating diagram
			cout << "\nBefore transformation ";
			trans.display();
			getch();
			cleardevice();

			// Creating matrix 
			// and taking input of scaling coefficient 
			// and then displaying after transforming
			trf.unit();
			trf.scaling();
			result = trans * trf;
			result.display();
			break;

		case 3:
			//  Taking input from user so calling the member function of class
			trans.getVertices();
			cleardevice();

			// displaying before transformating diagram
			cout << "\nBefore transformation ";
			trans.display();
			getch();
			cleardevice();

			// Creating matrix 
			// and taking input of rotation angle 
			// and then displaying after transforming
			trf.unit();
			trf.rotation();
			result = trans * trf;
			result.display();
			break;

		case 4:
			cout << "\n Do you wish to continue(y/n): ";
			cin >> ans;
			if (ans == 'y')
			{
				continue;
			}
			exit(0);

		default:
			cout << "\nWrong Input";
		}
		getch();
		closegraph();
		// If user want's to continue with it
		cout << "\n Do you wish to continue(y/n):";
		cin >> ans;

	} while (ans == 'Y' || ans == 'y');
	return 0;
}
