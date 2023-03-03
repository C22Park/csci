/*
Charles Park
Section 5
3/2/23
Assignment 7	
*/

#include <iostream>

using namespace std;

class Fraction {
    private:
        int numerator;
        int denominator;

    public:
        Fraction() {
            numerator = 1;
            denominator = 1;
        }
        Fraction(int _numerator, int _denominator) {
            numerator = _numerator;
            denominator = _denominator;
        }

        void set(int _numerator, int _denominator) {
            if (_denominator == 0) {
                numerator = 0;
                denominator = 1;
            } else {
                numerator = _numerator;
                denominator = _denominator;
            }
        }

        void printImproper() {
            cout << numerator << "/" << denominator << "\n";
        }
        void printMixed() {
            cout << double(numerator) / double(denominator) << "\n";
        }

};

int main() {
    Fraction fraction1 = Fraction(3, 2);
    fraction1.printMixed();
    Fraction fraction2;
    fraction2.printImproper();
    Fraction fraction3;
    fraction3.printImproper();
    fraction3.set(5, 9);
    fraction3.printImproper();
    fraction3.printMixed();
}