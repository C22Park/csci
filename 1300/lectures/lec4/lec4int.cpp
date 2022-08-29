#include <iostream>

using namespace std;

int main() {
    const int myConstInt = 101;
    
    int mySubtraction = myConstInt - 100;

    double myDivision = myConstInt / 3.0;

    cout << "The value of myConstInt is " << myConstInt << endl;
    cout << "The value of mySubtraction is " << mySubtraction << endl;
    cout << "The value of myDivision is " << myDivision << endl;

    return 0;
}