/*
	Charles Park
	Section 5
	1/12/23
	Assignment 1	
*/

/*
	Extra Work:
	* Made it check to make sure birth month is entered correctly
	* Changed formatting to how I like to write my code
*/

/* The fortune Teller -
    * a simple program introducing some
    * fundimental programming concepts.
*/

#include <iostream> // include a library
using namespace std;

int main()  // main() starts the program
{
	// -------------- Variable Declarations ------------------
 	int favorite;    // create a variable to store the favorite number
    int disliked;    // create a variable to store the disliked number
	int lucky;       // create a variable to store the lucky number
	int birth_month = 0; // create a variable to store the users birth month

	// ------------- Get user input -------------------------
	cout << "Enter your favorite number (no decimals): ";  // output
	cin >> favorite; 							   		   // user input
	cout << "Enter a number you don't like (no decimals): ";
	cin >> disliked;
	while (birth_month < 1 || birth_month > 12)
	{
		cout << "Enter your birth month (1 - 12): ";
		cin >> birth_month;
		if (birth_month < 1 || birth_month > 12)
		{
			cout << "Invalid input. Please enter a valid month.\n";
		}
	}

	lucky = (favorite * disliked * birth_month) % 10;
	cout << "\nYour secret, lucky number is: " << lucky << "\n";
	if(lucky < 0) // conditional, values less than 0
	{  
		cout << "Try to be less negative.\n";
	}
	if(lucky >= 0 && lucky < 4) // 0 to 3 inclusive
	{ 
		cout << "Think bigger!\n";
	}
	if(lucky >= 4 && lucky < 7) // 4 to 7 inclusive
	{ 
		cout << "Today you should embrace technology.\n";
	}
	if(lucky >= 7 && lucky <= 8) // 7 to 8 inclusive
	{ 
		cout << "You should buy some lotto tickets.\n";
	}
	if(lucky == 9) // exactly 9
	{ 
		cout << "Today is your lucky day!\n";
	}

	// ---------- Code to help the program exit "gracefully" -----
	cin.ignore();
 	cout << "Press enter to quit.\n";
	cin.ignore();
	return 0;
}