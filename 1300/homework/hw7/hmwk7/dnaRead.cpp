#include <iostream>
#include <vector>

using namespace std;

string dnaRead (vector<string> dna)
{
    string sequence;
    bool start_reading = false;

    for (int i = 0; i < dna.size(); i++)
    {
        if (dna.at(i).length() != 3)
        {
            return "Invalid sequence.";
        } else
        {
            for (int j = 0; j < 3; j++)
            {
                if (dna.at(i)[j] != 'A' && dna.at(i)[j] != 'C' && dna.at(i)[j] != 'G' && dna.at(i)[j] != 'T')
                {
                    return "Invalid sequence.";
                }
            }
        }
        if (!start_reading && dna.at(i) == "ATG")
        {
            start_reading = true;
        } else if (start_reading)
        {
            if (dna.at(i) == "TAA" || dna.at(i) == "TAG" || dna.at(i) == "TGA")
            {
                return sequence;
            }
            sequence += dna.at(i);
        }
    }

    return sequence;
}