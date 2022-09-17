#include <iostream>

using namespace std;

int main(){
    
    int a = 5;
    int b = a++; // adds one to a but prints original a for b or b = 5
    cout << "b is " << b << endl;
    b = ++a; // adds one to a then make b the final a or b = 7
    cout << "b is " << b << endl;

    return 0;
}