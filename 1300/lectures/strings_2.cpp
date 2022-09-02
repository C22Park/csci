#include <iostream>
#include <string>
using namespace std;

int main()
{
    // string declaration and initialization
    string first_name, last_name, space;
    first_name = "Leslie";
    last_name = "Knope";
    space = " ";

    // concatenation
    string full_name = first_name + space + last_name;

    // length of a string
    cout << "Name :" << full_name << endl;
    double len = full_name.length();
    cout << "The length of " << full_name << " is " << len << endl;

    // accepting string input
    string phrase;
    cout << "enter a phrase that contains spaces: ";
    cin >> phrase;
    cout << "phrase: " << phrase << endl;

    // DO NOT USE BOTH cin and getline in the same program
    string phrase1;
    cout << "enter a phrase that contains spaces: ";
    getline(cin, phrase1);
    cout << "phrase: " << phrase1 << endl;


    // referencing individual characters in a string
    /*
        L  e  s  l  i  e     K  n  o  p  e
        0  1  2  3  4  5  6  7  8  9  10 11
    */

    // find a character or string 
    // string_var.find("string")
    // string_var.find("string",starting_position)
    cout << full_name.find("L") << endl;    //  
    cout << full_name.find("l") << endl;    //  
    cout << full_name.find("e") << endl;    //  
    cout << full_name.find("ie") << endl;   // 
    cout << full_name.find("e", 3) << endl; //  

    // substring
    // string_var.substr(starting_position,num_of_characters)
    cout << full_name.substr(0,3) << " is a substring of " << full_name << endl;
    cout << full_name.substr(2,8) << " is a substring of " << full_name << endl;
    cout << full_name.substr(7) << " is a substring of " << full_name << endl;  // Knope / K
    cout << full_name.substr() << " is a substring of " << full_name << endl;  // full string


    // replace a character or string; http://www.cplusplus.com/reference/string/string/replace/
    // string.replace(starting_position,number_of_characters,"string")
    // cout << full_name.replace(7,7,"rocks") << endl;
    // cout << full_name.replace(0,4,"") << endl;
    // cout << full_name.replace(4,3,"") << endl;
    // cout << full_name << endl; // full_name has been updated

    return 0;
}