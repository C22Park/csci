#include <iostream>

using namespace std;

int main(){
    
    string input;
    cout << "Please enter a string:" << endl;
    getline(cin, input);  
    for (int i = 0; i < input.length(); i++) {
        if (int(input[i]) <= 122 && int(input[i]) >= 97) {
            input[i] -= 32;
        }
    }
    cout << input << endl;
    return 0;
}