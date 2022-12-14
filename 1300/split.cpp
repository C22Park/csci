#include <string>

using namespace std;

/*
    Algorithm:
    1. Empty the temp array that split will empty results into
    2. If the string is empty return 0
    3. Add each character into the index 0 of temp array until you reach a separator then increment the index
    4. if the index becomes greater than or equal to arr_size return -1 otherwise move on
    5. Once you reach the end of the input_string add one more to index and return that #
*/

int split(string input_string, char separator, string arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
    {
        arr[i] = "";
    }

    if (input_string == "")
    {
        return 0;
    }

    int num_elements = 0;
    
    for (int i = 0; i < input_string.length(); i++)
    {
        if (num_elements >= arr_size) 
        {
    
            return -1;
        } else if (input_string[i] == separator)
        {
            num_elements++;
        } else
        {
            arr[num_elements] += input_string[i];
        }
    }
        
    num_elements++;

    return num_elements;
}