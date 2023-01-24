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
	bool keepOn = true;

	while(keepOn)
	{
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
			} else
			{
				output = x / y;
			}
		} else
		{
			cout << "Invalid operand.\n";
			output = 0;
		}

		cout << "Result: " << output << "\n"
			 << "Restart? (Y/N): ";
		cin >> operand;
		if (operand == "N")
		{
			keepOn = false;
		}
	}


    return 0;
}