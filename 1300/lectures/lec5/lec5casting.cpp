#include <iostream>

using namespace std;

int main(){
    // create a floating point number
    float testFloat = 97.7;

    // cast it to an integer
    cout << static_cast<int>(testFloat) << endl;
    // then cast it to a char
    cout << static_cast<char>(testFloat) << endl;


    return 0;
}