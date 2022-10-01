#include <iostream>
#include <string>
#include <cassert>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

/*void chooseClass() {

}

void chooseRace() {

}

int charBaseStats() {

}
*/

int menu(string options, int size) {

    string options_arr[size];
    int last_newline = -1;
    int counter = 0;
    int length;
    for (int i = 0; i < options.length(); i++) {
        if (options.substr(i, 1) == "\n") {
            length = i - last_newline - 1;
            options_arr[counter] = options.substr(last_newline + 1, length);
            counter++;
            last_newline = i;
        }
    }

    string input;
    int result = -1;

    do {
        system("clear");
        cout << "*************************TERRASSA*************************\n\n";
        for (int i = 0; i < size; i++) {
            cout << options_arr[i] << "\n";
        }
        cout << "\n";

        getline(cin, input);

        for (int i = 0; i < size; i++) {
        if (input == options_arr[i]) {
                result = i;
        }
       }

     if (result == -1) {
            cout << "Invalid input." << "\n\n";
            sleep(1);
        }
    
    } while (result == -1);

    return result;
}

int main() {
    
    int input;

    input = menu("say hi\nsay bye\nclose\n", 3);
    
    switch (input) {
        case 0:
            cout << "Hi" << endl;
            break;
        case 1:
            cout << "Bye" << endl;
            break;
        case 2:
            cout << "Closing" << endl;
            break;
    }

    return 0;
}