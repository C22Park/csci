#include <iostream>

using namespace std;

string reverseString(string input)
{
    if (input.length() <= 1)
    {
        return input;
    } else 
    {
        return reverseString(input.substr(1)) + input.substr(0, 1);
    }
}

int main()
{
    string input;
    cout << "Enter a sentence to reverse: ";
    getline(cin, input);
    cout << "\nReversed sentence: " << reverseString(input) << "\n";
}