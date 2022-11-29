#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int randomNum (int min, int max)
{
    min;
    int random_number = min - 1;
    while (random_number < min)
    {
        random_number = (double(rand()) / double(RAND_MAX)) * max;
    }
    return random_number;
}