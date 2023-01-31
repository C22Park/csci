/*
	Charles Park
	Section 5
	1/31/23
	Assignment 3	
*/

/*
    Extra Work:
        -Checked if user input is 0 as that doesn't fit in any of the categories
*/

#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    double input;
    bool integer, even, positive;
    bool repeat = true;
    string restart;

    while (repeat)
    {
        integer = true;
        even = true;
        positive = true;

        cout << "Enter any number to have it be sorted\n" 
            << "It will be catagorized as an integer or decimal, even or odd, and positive or negative: ";
        cin >> input;

        if (abs(int(input)) - abs(input) < 0)
        {
            integer = false;
            even = false;
        } else if (int(input) / 2 == 0)
        {
            even = false;
        }
        if (input < 0)
        {
            positive = false;
        }
        
        if (input == 0)
        {
            cout << "The number 0 is neither an integer or decimal, even or odd, nor positive or negative.\n";
        } else
        {
            cout << "The number " << input << " is a";
            if (integer)
            {
                cout << "n integer and ";
            } else
            {
                cout << " decimal and ";
            }
            if (even) 
            {
                cout << "even and ";
            } else
            {
                cout << "odd and ";
            }
            if (positive)
            {
                cout << "positive.\n";
            } else
            {
                cout << "negative.\n";
            }
        }
        cout << "Would you like to enter a new number? (Y/N): ";
        cin >> restart;
        if (restart == "N" || restart == "n")
        {
            repeat = false;
        }
    }

    return 0;
}