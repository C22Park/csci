#include <cstdlib>
#include <ctime>

using namespace std;

int randomNum (int min, int max)
{
    srand(time(NULL)^2);
    return rand() % (max - min) + min;
}