/*
    Assignment 13
Write a program in C++ to use map associative container. The keys will be the names of states
and the values will be the populations of the states. When the program runs, the user is
prompted to type the name of a state. The program then looks in the map, using the state
name as an index and returns the population of the state.
*/
// Compiler Used :- Dev cpp

#include <iostream>
#include <iomanip>
#include <map>
using namespace std;

// Main Function
int main()
{
    // A standard container made up of (key,value) pairs,
    // which can be retrieved based on a key.
    map<string, int> mappingPopulationOnState;

    // insert() is in-built function in map 
    // pair<keyvalue, mapvalue> adds a new element to the map
    mappingPopulationOnState.insert(pair<string, int>("Maharashtra", 112));
    mappingPopulationOnState.insert(pair<string, int>("Rajasthan", 68));
    mappingPopulationOnState.insert(pair<string, int>("Karanataka", 61));
    mappingPopulationOnState.insert(pair<string, int>("Punjab", 27));
    mappingPopulationOnState.insert(pair<string, int>("West Bengal", 91));
    mappingPopulationOnState.insert(pair<string, int>("Uttar Pradesh", 199));
    mappingPopulationOnState.insert(pair<string, int>("Bihar", 104));
    mappingPopulationOnState.insert(pair<string, int>("Andhra Pradesh", 84));
    mappingPopulationOnState.insert(pair<string, int>("Madhya Pradesh", 72));
    mappingPopulationOnState.insert(pair<string, int>("Tamil Nadu", 72));
    mappingPopulationOnState.insert(pair<string, int>("Gujarat", 60));
    mappingPopulationOnState.insert(pair<string, int>("Orissa", 41));
    mappingPopulationOnState.insert(pair<string, int>("Kerala", 33));
    mappingPopulationOnState.insert(pair<string, int>("Jharkhand", 32));
    mappingPopulationOnState.insert(pair<string, int>("Assam", 31));
    mappingPopulationOnState.insert(pair<string, int>("Chhattisgarh", 25));
    mappingPopulationOnState.insert(pair<string, int>("Haryana", 25));
    mappingPopulationOnState.insert(pair<string, int>("Uttarakhand", 10));
    mappingPopulationOnState.insert(pair<string, int>("Himachal Pradesh", 6));
    mappingPopulationOnState.insert(pair<string, int>("Tripura", 3));
    mappingPopulationOnState.insert(pair<string, int>("Meghalaya", 2));
    mappingPopulationOnState.insert(pair<string, int>("Manipur", 2));
    mappingPopulationOnState.insert(pair<string, int>("Nagaland", 1));
    mappingPopulationOnState.insert(pair<string, int>("Goa", 1));
    mappingPopulationOnState.insert(pair<string, int>("Arunachal Pradesh", 13));
    mappingPopulationOnState.insert(pair<string, int>("Mizoram", 1));
    mappingPopulationOnState.insert(pair<string, int>("Sikkim", 6));
    mappingPopulationOnState.insert(pair<string, int>("Delhi", 16));
    mappingPopulationOnState.insert(pair<string, int>("Jammu & Kashmir", 12));
    mappingPopulationOnState.insert(pair<string, int>("Puducherry", 1));
    mappingPopulationOnState.insert(pair<string, int>("Dadra and Nagar Haveli", 5));
    mappingPopulationOnState.insert(pair<string, int>("Daman and Diu", 5));
    mappingPopulationOnState.insert(pair<string, int>("Andaman and Nicobar Islands", 6));

    // iterator is used to iterate through map elements
    map<string, int>::iterator iter;

    // Here setw() it manipulate with widths, it gives padding from left
    cout << endl << setw(15) << "Population" << setw(45) << "States" << endl
         << endl;

    // for loop is to print all the population and state in order of state
    for (iter = mappingPopulationOnState.begin(); iter != mappingPopulationOnState.end(); iter++)
    {
        cout << setw(6) << iter->second << " million" << setw(53) << iter->first << endl;
    }

    // Here it prints in size of map
    cout << "\n\n========Population of states in India==========\n";
    cout << "\n Size of population Map: " << mappingPopulationOnState.size() << "\n";

    string state_name;
    
    char choice = 'y';
    
    do
    {
        cout << "\n Enter name of the state: ";
        // fflush(stdin) is used to clear buffer 
		    // getline() function is used to take input of string variable. 
        // It stores the characters untill the delimitor is found
        fflush(stdin);
        getline(cin, state_name);

        // find() is in-built function in map header file
        iter = mappingPopulationOnState.find(state_name);

        if (iter != mappingPopulationOnState.end())
            cout << state_name << " 's population is " << iter->second << " million";

        else
            cout << "\nKey is not population Map";

        cout << "\n\nDo you want to continue (y/n) ? : ";
        cin >> choice;

    } while (choice == 'y');

    // To clear all the elements from the map
    mappingPopulationOnState.clear();
}
 
