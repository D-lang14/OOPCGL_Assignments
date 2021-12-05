// OOP CG Lab Assignment 6 : 
// Write a C++ program that creates an output file, writes information to it, closes the file, open 
// it again as an input file and read the information from the file.
// Compiler used :- Turbo C++

#include <iostream.h>
#include <fstream.h>
#include <string.h>
#define max 30

class Details
{
public:
	int serialno, roll;
	char name[max];
	int age;
	float marks;

	// Constructor
	Details()
	{
		serialno = 0;
		roll = 0;
		strcpy(name, " ");
		age = 0;
		marks = 0.0;
	}
	void readDetails();
	void display();
};

// Taking inputs in readDetails function
void Details::readDetails()
{
	cout << "\nEnter serial number: ";
	cin >> serialno;
	cout << "\nEnter roll number: ";
	cin >> roll;
	cout << "\nEnter name: ";
	cin >> name;
	cout << "\nEnter age: ";
	cin >> age;
	cout << "\nEnter marks: ";
	cin >> marks;
}

// Display Function
void Details::display()
{

	cout << "\nSerail No.: " << serialno;
	cout << "\nRoll No.: " << roll;
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nMarks: " << marks << endl;
}

// Main menu
int main()
{
	fstream file;
	Details det;

	int choice, i, snr, mod, loc, del, dloc;
	char choose = 'y';
	do
	{
		cout << "\n****************MENU******************";
		cout << "\n1.Create new file ";
		cout << "\n2.Add record ";
		cout << "\n3.Display ";
		cout << "\n4.Modify ";
		cout << "\n5.Delete";
		cout << "\nEnter your choice:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			file.open("Studetails.dat", ios::binary | ios::in | ios::out | ios::ate | ios::trunc);
			for (i = 0; i < 100; i++)
				file.write((char *)&det, sizeof(det));

			file.close();
			cout << "\nSuccessfuly new file has been created\n";

			cout << "\nDo you want to continue (y/n)?: ";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
				continue;

			break;

		case 2:
			file.open("Studetails.dat", ios::binary | ios::in | ios::out | ios::ate);
			det.readDetails();

			snr = (det.serialno - 1) * sizeof(det);
			if (file.eof())
				file.clear();

			file.seekp(snr);
			file.write((char *)&det, sizeof(det));

			file.close();

			cout << "\nDo you want to continue (y/n)?: ";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
				continue;

			break;

		case 3:
			file.open("Studetails.dat", ios::binary | ios::in | ios::out | ios::ate);
			file.seekg(0, ios::beg);

			while (file.read((char *)&det, sizeof(det)))
			{
				if (det.serialno != 0)
					det.display();
			}

			file.close();

			cout << "\nDo you want to continue (y/n)?: ";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
				continue;

			break;

		case 4:
			file.open("Studetails.dat", ios::binary | ios::in | ios::out | ios::ate);
			cout << "\nEnter serial no to be modified: ";
			cin >> mod;

			loc = (mod - 1) * sizeof(det);
			if (file.eof())
				file.clear();

			file.seekp(loc);

			cout << "\nEnter new data:  ";
			det.readDetails();
			file.write((char *)&det, sizeof(det));

			file.close();

			cout << "\nDo you want to continue (y/n)?: ";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
				continue;

			break;

		case 5:
			file.open("Studetails.dat", ios::binary | ios::in | ios::out | ios::ate);
			cout << "\nEnter item no to be deleted:";
			cin >> del;

			dloc = (del - 1) * sizeof(det);
			if (file.eof())
				file.clear();

			file.seekp(dloc);

			det.serialno = 0;
			det.roll = 0;
			strcpy(det.name, " ");
			det.age = 0;
			det.marks = 0.0;
			file.write((char *)&det, sizeof(det));

			file.close();

			cout << "\nDo you want to continue (y/n)?: ";
			cin >> choose;
			if (choose == 'y' || choose == 'Y')
				continue;

			break;
		}
	} while (choose == 'y' || choose == 'Y');
	return 0;
}
