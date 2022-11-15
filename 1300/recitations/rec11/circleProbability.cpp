#include <iostream>
#include <cmath>

using namespace std;

void circleProbability(double side_length)
{
    srand(time(NULL));
    double radius = (double(rand()) / double(RAND_MAX)) * (side_length / 2);
    double probability = (radius * radius * M_PI) / side_length * side_length;

    cout << "The radius of the circle is: " << radius << "\n"
         << "The probability of landing in the circle is " << probability << "\n";
}

int main()
{
    double input;
    cout << "Enter side length: ";
    cin >> input;
    cout << "\n";
    circleProbability(input);

    return 0;
}