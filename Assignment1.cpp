// OOP CG Lab Assignment 1:

//Develop a program in C++ to create a database of student's information system containing the 
//following information: Name, Roll number, Class, Division, Date of Birth, Blood group, Contact 
//address, Telephone number, Driving license no. and other. Construct the database with 
//suitable member functions. Make use of constructor, default constructor, copy constructor, 
//destructor, static member functions, friend class, this pointer, inline code and dynamic 
//memory allocation operators-new and delete as well as exception handling.

#include<iostream>
#include<string.h>
using namespace std;

class StudentData
{
	string name;
    int roll_no;
    string cls;
    string division;
    string dob;
    string city;
    string bloodgroup;
    string telno;
    string dlicenseno;
    
    public:
    	static int studentCount;
    	
    	StudentData(){
    		roll_no=7;
		    name = "";
		    cls = "";
		    division = "";
		    dob = "";
		    bloodgroup = "";
		    city = "";
		    telno = "9123456789";
		    dlicenseno = "A1023";
		    ++studentCount;
		}
		
		void getStudData(){
			cout<<"Enter Student Name : ";
		    fflush(stdin);
		    getline(cin, name);
		    
		    cout<<"Enter Roll Number : ";
		    cin>>roll_no;
		    
		    cout<<"Enter Class : ";
			fflush(stdin);
		    getline(cin, cls);
		    
		    cout<<"Enter Division : ";
		    cin>>division;
		    
		    cout<<"Enter Date of Birth : ";
			fflush(stdin);
		    getline(cin,dob);
		    
		    cout<<"Enter Blood Group : ";
		    cin>>bloodgroup;
		    
		    cout<<"Enter Contact City : ";
			fflush(stdin);
	        getline(cin, city);
	        
	        cout<<"Enter Telephone Number : ";
	        cin>>telno;
	        
	        cout<<"Enter Driving License Number : ";
	        cin>>dlicenseno;
		}
		
		friend void display(StudentData sd);    // Declaration of friend function
		
		~StudentData(){
			cout<<"\n\n"<<this->name<<"(Object) is destroyed!\n"; 
		}
		
};

void display(StudentData sd){
	cout<<"\n Name:"<<sd.name;
    cout<<"\n Roll_No:"<<sd.roll_no;
    cout<<"\n Class:"<<sd.cls;
	cout<<"\n Div:"<<sd.division;
    cout<<"\n DOB:"<<sd.dob;
    cout<<"\n Blood group:"<<sd.bloodgroup;
    cout<<"\n City:"<<sd.city;
    cout<<"\n Phone_No:"<<sd.telno;
	cout<<" \n Liacense_No:"<<sd.dlicenseno; 
}

int StudentData :: studentCount;

int main(){
	StudentData sdt;
	cout<<"------------------Enter your details------------------"<<endl<<endl;
	sdt.getStudData();
	cout<<endl<<"------------------Here are your details------------------"<<endl;
	display(sdt);
	
	return 0;
}


