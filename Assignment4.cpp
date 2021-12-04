// OOP CG Lab Assignment 4 :

// Implement a class Complex which represents the Complex Number data type. Implement the following :
// 1. Constructor (including a default constructor which creates the complex number 0+0i).
// 2. Overload operator+ to add two complex numbers.
// 3. Overload operator* to multiply two complex numbers.
// 4. Overload operators << and >> to print and read Complex Numbers.

#include<iostream>
using namespace std;

class Complex{
	float real, imaginary;
	
	public:
		Complex(){
			real = 0;
			imaginary = 0;
		}
		
		Complex(float real, float imaginary){
			this->real = real;
			this->imaginary = imaginary;
		}
		
		Complex operator + (Complex);
		Complex operator * (Complex);
		
		friend ostream &operator << (ostream &, Complex &);
		friend istream &operator >> (istream &, Complex &);
};

Complex Complex::operator +(Complex num2){
	Complex add;
	add.real = real + num2.real;
	add.imaginary = imaginary + num2.imaginary;
	return add;
}


Complex Complex::operator *(Complex num2){
	Complex mul;
	mul.real = (real * num2.real)-(imaginary * num2.imaginary);
	mul.imaginary = (real * num2.imaginary)+(imaginary * num2.real);
	return mul;
}


ostream& operator << (ostream& outputStream, Complex& comNum1){
	outputStream << comNum1.real << "+" << comNum1.imaginary << "i" << endl;
	return outputStream;
}


istream& operator >> (istream& inputStream, Complex& comNum2){
	inputStream >> comNum2.real;
	inputStream >> comNum2.imaginary;
	return inputStream;
}


int main(){
	Complex num1, num2, num3, num4;
	string ch = "yes";
	
	while (ch == "yes"){
		
		cout<<"\n-------------------------Main Menu-------------------------\n";
		
		cout<<"\nEnter real and imaginary part of 1st complex number: ";
		cin>>num1;
		cout<<"Enter real and imaginary part of 2nd complex number: ";
		cin>>num2;
		
		num3=num1+num2;
		num4=num1*num2;
		
		cout<<"\nFirst complex number is: "<<num1;
		cout<<"Second complex number is: "<<num2;
		cout<<"\nAddition is: "<<num3;
		cout<<"Multiplication is: "<<num4;
		
		cout<<"\n\nDo you want to continue (yes/no) ? ";
		cin>>ch;
		if (ch == "no"){
			exit(0);
		}
		else{
			continue;
		}
	}
	
	return 0;
}

