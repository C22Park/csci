#include <iostream>
#include <iomanip> // adds manipulators to code for formatting output

using namespace std;

int main(){
    
    // static_cast<new type>(data to convert)
    
    int x = 25;
    int y = 10;
    cout << x / static_cast<double>(y) << endl; // makes y a double so it doesn't do integer division, result should be 2.5

    x = x + y; // this is equivalent to x += y;
    x *= y; // this is equivalent to x = x * y
    cout << x << endl; // result should be (x+y)y = (25+10)10 = 350
    
    return 0;
}