#include <iostream>
#include <string>

using namespace std;

int main(){
    int gold; // used to store input of gold
    int goldToSilver = 100; // used to convert gold to silver
    int goldToCopper = 10000; // used to convert gold to copper
    string silverOrCopper; // used to decide what the user wants to convert their gold into
    int result; // used to display final result

    cout << "1 gold = 100 silver = 10000 copper" << endl;
    cout << "Enter the amount of gold you have: ";
    cin >> gold;
    cout << endl;

    if (!cin ) // if the user puts in a non integer then display "Invalid response." and move to the end of the program
    {
        cout << "Invalid response." << endl;
    }
    else if (gold >= 0)
    {
    cout << "You have " << gold << " gold. Would you like to convert this to silver or copper? ";
    cin >> silverOrCopper;
    cout << endl;

    if (silverOrCopper == "silver") 
    {
        result = gold * goldToSilver;
        cout << "You now have " << result << " silver." << endl;
    }
    else if (silverOrCopper == "copper")
        {
            result = gold * goldToCopper;
            cout << "You now have " << result << " copper." << endl;
        }
        else
        {
            cout << "Invalide response." << endl;
        }
    }
    else
    {
        cout << "Invalid response." << endl;
    }
    return 0;
}