#include <iostream>
#include <vector>

using namespace std;

vector<float> addToVector(vector<float> my_vector, float temp_arr[15])
{
    for (int i = 0; i < 15; i ++)
    {
        my_vector.push_back(temp_arr[i]);
    }
    return my_vector;
}

int averageVector(vector<float> my_vector)
{
    int average = 0;
    for (int i = 0; i < my_vector.size(); i++)
    {
        average += my_vector.at(i);
    }
    average /= my_vector.size();

    return average;
}

vector<float> removeLessThanAverage(vector<float> my_vector, float average)
{
    for (int i = 0; i < my_vector.size(); i++)
    {
        if (my_vector.at(i) < average)
        {
            my_vector.erase(my_vector.begin() + i);
            i--;
        }
    }
    return my_vector;
}

int main()
{
    cout << "Enter 15 floating point values:\n";
    float temp_arr[15];
    vector<float> my_vector;
    for (int i = 0; i < 15; i++)
    {
        cin >> temp_arr[i];
    }
    my_vector = addToVector(my_vector, temp_arr);
    for (int i = 0; i < my_vector.size(); i++)
    {
        cout << my_vector.at(i) << "\n";
    }
    float average = averageVector(my_vector);
    cout << "The average of the vector is: " << average << "\n";
    my_vector = removeLessThanAverage(my_vector, average);
    for (int i = 0; i < my_vector.size(); i++)
    {
        cout << my_vector.at(i) << "\n";
    }
    return 0;   
}