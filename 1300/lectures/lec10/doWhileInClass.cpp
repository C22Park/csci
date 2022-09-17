#include <iostream>

using namespace std;

int main(){
    
    int input; 
    //bool first_time_flag = true;

    do {
    //first_time_flag = false;

    cout << "Enter a positive number: ";

    cin >> input;

    if (input <= 0){
        cout << "That is a negative number" << endl;
    }
    } while (input <= 0);
    
    cout << "The number you entered is " << input << endl;

    return 0;
}