#include <iostream>

using namespace std;

int main()
{
    
    int enemy_gold = 0;
    int counter = 0;
    for (int j = 1; j <= 30; j++)
    {
        
        if ((j - 1) % 5 == 0)
        {
            counter++;
        }
        enemy_gold = enemy_gold + counter;
        cout << enemy_gold << "\n";
    }

    return 0;
}