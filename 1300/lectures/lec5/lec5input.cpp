#include <iostream>

using namespace std;

int main(){
    // print prompt asking user for their favorite LETTER
    cout << "Enter your favorite letter: ";
    // get the input from the user
    char favLetter;
    cin >> favLetter;
    // print out their favorite letter
    cout << "Your favorite letter is " << favLetter << endl;
    // print out the INTEGER representation of their favorite letter 
    // (remember our friend, the ASCII table?)
    cout << "The integer that represents your favorite number is " << static_cast<int>(favLetter) << endl;

    return 0;
}