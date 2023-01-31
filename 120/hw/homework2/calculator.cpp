/*
	Charles Park
	Section 5
	1/24/23
	Assignment 2	
*/

/*
	Additional Work:
		-Made operand checking a string instead of numbered menu, and added a check for a valid operand
		-Made the calculator repeating unless you exit
		-Checked to protect against divide by 0
*/

#include <iostream>

using namespace std;

int main()
{
	cout << "Welcome to Calcutron, the worlds simplest calculator!\n"			// Explanation 
		 << "Enter two numbers below and then the operand you wish to use.\n";

	double x, y; // Initializers
	double output = 0;
	string operand;
	bool keep_on = true;
	bool valid_input = true;

	while(keep_on)
	{
		valid_input = true;
		cout << "Input 1: ";
		cin >> x;
		cout << "Input 2: ";
		cin >> y;
		cout << "Operand (+, -, *, /): ";
		cin >> operand;

		if (operand == "+")
		{
			output = x + y;
		} else if (operand == "-")
		{
			output = x - y;
		} else if (operand == "*")
		{
			output = x * y;
		} else if (operand == "/")
		{
			if (y == 0)
			{
				cout << "Invalid denominator (Divide by 0)\n";
				output = 0;
				valid_input = false;
			} else
			{
				output = x / y;
			}
		} else
		{
			cout << "Invalid operand.\n";
			output = 0;
			valid_input = false;
		}

		if (valid_input)
		{
			cout << "Result: " << output << "\n";
		}

		cout << "Restart? (Y/N): ";
		cin >> operand;
		if (operand == "N" || operand == "n")
		{
			keep_on = false;
		}
	}


    return 0;
}