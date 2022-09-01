#include <iostream>

using namespace std;

int main(){
    // declare an int
    int x = 11;
    // declare another int
    int y = 3;
    // divide one int by the other USING INTEGER DIVISION, print result
    cout << x / y << endl;
    // divie one int by the other USING FLOATING POINT DIVISION, print result
    cout << x / static_cast<float>(y) << endl;
    // print out remainder of dividing one int by the other (hint: modulo operator)
    cout << x % y << endl;

    return 0;
}