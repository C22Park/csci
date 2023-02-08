#include <iostream>
#include <cstdlib>

using namespace std;

int main() {

    srand(time(NULL));
    int random = (rand() % 100) + 1;
    int count = 0, guess = 0;
    bool incorrect = true;
    
    while (incorrect) {
        cout << "Guesses: " << count << "\n"
             << "Guess a number between 1-100: ";
        cin >> guess;
        if (guess >= 1 && guess <= 100) {
            count++;
            if (guess == random) {
                cout << "You guessed correctly!!! It only took you " << count << " attempts.\n";
                incorrect = false;
            } else if (guess < random) {
                cout << "Too low.\n";
            } else if (guess > random) {
                cout << "Too high.\n";
            }
        } else {
            cout << "Invalid Input. Please try again\n";
        }
    }

    return 0;
}