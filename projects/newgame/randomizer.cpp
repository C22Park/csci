#include <cstdlib>
#include <ctime>

using namespace std;

int randomNum (int min, int max)
{
    srand(time(NULL));
    return rand() % (max - min + 1) + min;
}