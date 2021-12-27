// OOP CG Lab Assignment 10 :
// Write a function template for selection sort that inputs, sorts and outputs an integer array and a float array.
// Compiler Used :- Dev Cpp

#include <iostream>
#define size 20
using namespace std;

// Declaration of a global variable
int n;

// Initialization of template
template <typename P>

// Function of selection sort
void selectionSort(P arr[size])
{
    int i, j, min;
    // temp is a template variable because we want to swap array elements of any datatype
    P temp;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }
        // Swaping the elements
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    cout << "\n\tSorted elements: ";
    for (i = 0; i < n; i++)
    {
        cout << " " << arr[i];
    }
}


// Main Function
int main()
{
    // Variables of various datatypes to be sorted
    int A[size];
    float B[size];
    char C[size];
    double D[size];

    int choice, i;

    do
    {
        // Created a menu where user can choose one of them to sort any datatype
        cout << "\n-----------Menu-----------\n";
        cout << "\n 1. Integer ";
        cout << "\n 2. Float ";
        cout << "\n 3. Char ";
        cout << "\n 4. Double ";
        cout << "\n 5. Exit \n";

        cout << "\n Enter Choice (1 to 5) : ";
        cin >> choice;

        switch (choice)
        {
            // Case 1 sorting integer datatype
            case 1:
            {
                cout << "\nEnter Total Number Of Integer Elements: ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    // Taking Inputs from user
                    cout << "\nEnter Integer Elements [" << i + 1 << "]: ";
                    cin >> A[i];
                }
                // Calling function to sort the given inputs
                selectionSort(A);
                cout << endl;

                break;
            }

            // Case 2 sorting float datatype
            case 2:
            {
                cout << "\nEnter Total Number Of Float Elements: ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    // Taking Inputs from user
                    cout << "\nEnter Float Elememts [" << i + 1 << "]: ";
                    cin >> B[i];
                }
                // Calling function to sort the given inputs
                selectionSort(B);
                cout << endl;

                break;
            }

            // Case 3 sorting char datatype
            case 3:
            {
                cout << "\nEnter Total Number Of Char Elements: ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    // Taking Inputs from user
                    cout << "\nEnter Char Elememts [" << i + 1 << "]: ";
                    cin >> C[i];
                }
                // Calling function to sort the given inputs
                selectionSort(C);
                cout << endl;

                break;
            }

            // Case 4 sorting double datatype
            case 4:
            {
                cout << "\nEnter Total Number Of Double Elements: ";
                cin >> n;
                for (i = 0; i < n; i++)
                {
                    // Taking Inputs from user
                    cout << "\nEnter Double Elememts [" << i + 1 << "]: ";
                    cin >> D[i];
                }
                // Calling function to sort the given inputs
                selectionSort(D);
                cout << endl;

                break;
            }

            // Case 5 to exit from loop
            case 5:
            {
                cout << "\n**********Program Exited Successfully**********" << endl;
                exit(0);
            }

            // Default case when invalid input is given
            default:
            {
                cout << "\n Invalid";
            }
        }
    } while (choice != 6);
    return 0;
}
