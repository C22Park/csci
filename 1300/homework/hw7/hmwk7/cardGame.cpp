#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int card = 0;
    int counter = 0;
    vector<int> deck;
    
    while(card != 14)
    {
        cout << "Please enter a number:\n";
        cin >> card;
        if (card > 0 && card <= 14)
        {
            deck.push_back(card);
            if (card == 1)
            {
                if (deck.size() > 1)
                {
                    deck.erase(deck.begin(), deck.begin() + 2);
                    counter += 2;
                } else if (deck.size() == 1)
                {
                    deck.erase(deck.begin());
                    counter++;
                }
            } else if (card >= 11 && card <= 13)
            {
                if (deck.size() > 1)
                {
                    deck.pop_back();
                    deck.pop_back();
                    counter += 2;
                } else if (deck.size() == 1)
                {
                    deck.pop_back();
                    counter++;
                }
            } else if (card == 14)
            {
                for (int i = 0; i < deck.size(); i++)
                {
                    if (deck.at(i) == 14)
                    {
                        deck.erase(deck.begin() + i);
                    }
                }
            }

        } else
        {
            cout << "The number should be an integer between 1 and 14.\n";
        }
    }

    cout << "Your remaining cards are: ";
    for (int i = 0; i < deck.size(); i++)
    {
        cout << deck.at(i) << " ";
    }
    cout << "\n";

    cout << "I have " << counter << " card(s).\n";

    if (counter > deck.size())
    {
        cout << "I win!\n";
    } else if (counter < deck.size())
    {
        cout << "You win!\n";
    } else
    {
        cout << "Tie!\n";
    }

    return 0;
}