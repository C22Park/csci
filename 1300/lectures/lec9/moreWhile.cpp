#include <iostream>

using namespace std;

int main(){
    
  /*  int a = 0;
    while (a < 1000)
    {
        a++;
        cout << a << endl;
    }
*/
    string my_string = "I love to program!";
    int index = 0;
    while (index < my_string.length())
    {
        cout << my_string[index] << endl;
        index++;
    }

    return 0;
}