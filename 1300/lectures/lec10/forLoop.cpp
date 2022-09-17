#include <iostream>
#include <string>

using namespace std;

int main(){

    string my_string = "Hello this is String speaking.";

    /*int index = 0;
    while (index < my_string.length())
    {
        cout << "The " << index
            << " letter is " << my_string[index] << endl;
        index++;
    }*/

    for (int i = 0 ; i < my_string.length() ; i++)
    {
        cout << "The " << i
            << " letter is " << my_string[i] << endl;
    }

    return 0;
}