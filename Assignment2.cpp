// OOP CG Lab Assignment 2:

// Imagine a publishing company which does marketing for book and audio cassette versions. 
// Create a class publication that stores the title (a string) and price (type float) of publications. 
// From this class derive two classes: book which adds a page count (type int) and tape which 
// adds a playing time in minutes (type float).
// Write a program that instantiates the book and tape class, allows user to enter data and 
// displays the data members. If an exception is caught, replace all the data member values with 
// zero values.

# include<iostream>
# include<stdio.h>
# include<stdlib.h>
using namespace std;

class Publication
{
	string title;
	float price;
	public:
		void getdata(){
			cout<<"Enter Title of the Publication: ";
			fflush(stdin);
			getline(cin, title);
			cout <<"Enter Price of Publication : ";
			cin >> price;
		}
		
		void display(){
			cout<<"Title: "<<title<<endl;
			cout<<"Price: "<<price<<endl;
		}
	
};

class Book: public Publication
{
	int pageCount;	
	public:
		void addBook(){
			try{
				getdata();
				cout << "Enter Page Count of Book : ";
				cin >> pageCount;
 				
				if (pageCount <= 0){
					throw pageCount;
				}
			}
			catch(...){
				cout << "\nInvalid Page Count!!!";
				pageCount = 0;
			}
		}
		
		void displayBook(){
			display();
			cout<<"Total number of pages are: "<<pageCount<<endl;
		}
	
};

class Tape: public Publication
{
	float playTime;
	public:
		void addTape(){
			getdata();
			cout<<"How much time will it take to read this book: ";
			cin>>playTime;
		}
		
		void displayTape(){
			display();
			cout<<"Time taken to read this book: "<<playTime<<endl;
		}
};

int main(){
	
	Book b1[10];
	Tape t1[10];
	int ch, b_count = 0, t_count = 0;
	do
	{
		cout << "\n* * * * * PUBLICATION DATABASE SYSTEM * * * * *";
		cout << "\n--------------------MENU-----------------------";
		cout << "\n1. Add Information to Books";
		cout << "\n2. Add Information to Tapes";
		cout << "\n3. Display Books Information";
		cout << "\n4. Display Tapes Information";
		cout << "\n5. Exit";
		cout << "\n\nEnter your choice : ";
		cin >> ch;
		switch(ch)
		{
			case 1:
				b1[b_count].addBook();
				b_count ++;
				break;
 			case 2:
				t1[t_count].addTape();
				t_count ++;
				break;
 			case 3:
				cout << "\n* * * * BOOK PUBLICATION DATABASE SYSTEM * * * *"<<endl;
				for (int j=0;j < b_count;j++)
				{
					b1[j].displayBook();
				}
				break;
 			case 4:
				cout << "\n* * * * TAPE PUBLICATION DATABASE SYSTEM * * * *"<<endl;
				for (int j=0;j < t_count;j++)
				{
					t1[j].displayTape();
				}
				break;
 			case 5:
				cout<<"Exit!!"<<endl;
				exit(0);
		}
	}while (ch != 5);
	
	return 0;
}


