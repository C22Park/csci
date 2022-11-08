#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

int randomNum (int min, int max)
{
    default_random_engine generator(time(0));
    uniform_real_distribution<float> distribution(min, max + .5);
    random_device rd;
    default_random_engine generator1(rd());
    return distribution(generator1);
}