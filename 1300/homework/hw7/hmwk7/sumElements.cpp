#include <iostream>
#include <vector>

using namespace std;

int sumElements(vector<int> vect, int start_index, int end_index)
{
    if (start_index > end_index)
    {
        return -1;
    }
    int size = vect.size();
    if (start_index < 0 || start_index >= size || end_index < 0 || end_index >= size)
    {
        return -2;
    }

    int sum = 0;
    for (int i = start_index; i <= end_index; i++)
    {
        sum += vect.at(i);
    }

    return sum;
}

int main()
{
    vector<int> vect1{10, 20, 30, 40, 50};
    int start_index = 0, end_index = 4;
    cout << sumElements(vect1, start_index, end_index) << endl;

    return 0;
}