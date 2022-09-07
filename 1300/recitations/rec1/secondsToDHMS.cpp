#include <iostream>

using namespace std;

int main(){
    
    int working; // used for input in seconds and for storing values when preforming operations
    int days;
    int hours;
    int minutes;
    int seconds;

    cout << "Input the amount of seconds between 0-1,000,000 to convert to D/H/M/S format: ";
    cin >> working;
    cout << endl;

    if (!cin) // if user enters a non integer end program
    {
            cout << "Invalid response." << endl;
    }
    else if (working > 1000000) // if user enters number outside of bounds end program
    {
        cout << "Invalid response." << endl;
    }
    else if (working < 0) // if user enters number outside of bounds end program
    {
        cout << "Invalid response." << endl;
    }
    else 
    {
        days = working / 86400; // 86400 is the amount of seconds in one day
        working = working % 86400;

        hours = working / 3600; // 3600 is the amount of seconds in an hour
        working = working % 3600;

        minutes = working / 60; // 60 is the amount of seconds in a minute
        
        seconds = working % 60;

        cout << "The time is " << days << " days, " << hours << " hours, " << minutes << " minutes, and " << seconds << " seconds." << endl;
    }
    return 0;
}