#include <iostream>

using namespace std;

int main(){
    
    string firstName, lastName;
    cout << "Enter the first name: " << endl;
    cin >> firstName;
    cout << "Enter the last name: " << endl;
    cin >> lastName;
    cout << "Hello " << firstName[0] << firstName[1] << lastName[0] << lastName[1] << firstName.length() << lastName.length() << "!" << endl;

    return 0;
}