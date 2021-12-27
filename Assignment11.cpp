// OOP CG Lab Assignment 11:
// Write C++ program using STL for sorting and searching user defined records such as Item
// records (Item code, name, cost, quantity etc) using vector container.
// Compiler Used :- Dev cpp

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Created a class Item
class Item
{
// Public specifier 
public:
    string name;
    int quantity;
    int cost;
    int code;

    // Comparison operator overloading
    bool operator ==(const Item &i1)
    {
        if (code == i1.code)
            return 1;
        return 0;
    }

    bool operator <(const Item &i1)
    {
        if (code < i1.code)
            return 1;
        return 0;
    }
};

// Declared a vector of class type 
vector<Item> objectItem;

// Declaration of functions to perform on the items
bool compare(const Item &, const Item &);
void print(Item &);
void displayItems();
void insertItem();
void searchItem();
void deleteItem();

// Compare Function return type is bool, 
// it returns true or false
bool compare(const Item &iter1, const Item &iter2)
{
    return iter1.quantity < iter2.quantity;
}

// Insert Function it takes input from user as name, quantity, cost, code
void insertItem()
{
    Item iter1;
    cout << "\nEnter Item Name: ";
    // fflush(stdin) is used to clear buffer 
	// getline() function is used to take input of string variable. 
    // It stores the characters untill the delimitor is found
    fflush(stdin);
    getline(cin, iter1.name);
    cout << "\nEnter Item Quantity: ";
    cin >> iter1.quantity;
    cout << "\nEnter Item Cost: ";
    cin >> iter1.cost;
    cout << "\nEnter Item Code: ";
    cin >> iter1.code;
    // Here we are pushing or inserting all the items taken from the user at the back as a stack 
    objectItem.push_back(iter1);
}

// Print Function to print the inputs taken from user to the console
void print(Item &iter1)
{
    cout << "\n";
    cout << "\nItem Name: " << iter1.name;
    cout << "\nItem Quantity: " << iter1.quantity;
    cout << "\nItem Cost: " << iter1.cost;
    cout << "\nItem Code: " << iter1.code;
}

// Display function is to make a sequence of details 
// of a item in one stack and other to another stack
void displayItems()
{
    for_each(objectItem.begin(), objectItem.end(), print);
}

// Search function is to search any item by its code
void searchItem()
{
    vector<Item>::iterator pointer;
    Item iter1;
    cout << "\nEnter Item Code to search: ";
    cin >> iter1.code;
    // find() function is, in built function in vector
    pointer = find(objectItem.begin(), objectItem.end(), iter1);

    if (pointer == objectItem.end())
    {
        cout << "\nNot found.";
    }

    else
    {
        cout << "\nFound." << endl;
        cout << "Item Name : " << pointer->name << endl;
        cout << "Item Quantity : " << pointer->quantity << endl;
        cout << "Item Cost : " << pointer->cost << endl;
        cout << "Item Code: " << pointer->code << endl;
    }
}

// Deleting the Items by its code
void deleteItem()
{
    vector<Item>::iterator pointer;
    Item iter1;
    cout << "\nEnter Item Code to delete: ";
    cin >> iter1.code;
    pointer = find(objectItem.begin(), objectItem.end(), iter1);

    if (pointer == objectItem.end())
    {
        cout << "\nNot found.";
    }

    else
    {
        // erase() function remove item at given code
        objectItem.erase(pointer);
        cout << "\nDeleted.";
    }
}

// Main Function
int main()
{
    int choice;
    do
    {
        // List of operations to be performed
        cout << "\n------------ Menu ------------";
        cout << "\n1.Insert";
        cout << "\n2.Display";
        cout << "\n3.Search";
        cout << "\n4.Sort";
        cout << "\n5.Delete";
        cout << "\n6.Exit";
        
        cout << "\nEnter your choice (1 to 6): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertItem();
                break;

            case 2:
                displayItems();
                break;

            case 3:
                searchItem();
                break;

            case 4:
                sort(objectItem.begin(), objectItem.end(), compare);
                cout << "\n\n\t Sorted on Quantity";
                displayItems();
                break;

            case 5:
                deleteItem();
                break;

            case 6:
                cout<<"\nDone!!";
                exit(0);

            default:
                cout<<"\nInvalid Inputs";
        }

    } while (choice != 7);

    // End of Program
    return 0;
}
