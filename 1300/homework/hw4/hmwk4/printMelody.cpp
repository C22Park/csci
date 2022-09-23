#include <iostream>
#include <cmath>

using namespace std;

int main(){

    string scale = "CdDeEFgGaAbB";
    int frequency, note;
    int note_octave = 1; 

    cout << "What is your frequency?:" << endl;
    cin >> frequency;
    if (frequency < 33 || frequency > 4186) {
        cout << "Your note is not on a piano." << endl;
    }
    else {
        note = 12*log2(frequency/32.7);
        while (note > 12) {
            note -= 13;
            ++note_octave;
        }
        cout << "The nearest note is:\n" << scale[note] << note_octave << endl;
        if (scale[note] == 'd' || scale[note] == 'e' || scale[note] == 'g' || scale[note] == 'a' || scale[note] == 'b') {
            cout << "Your melody is: ";
            for (int i = 0; i < 4; ++i) {
                cout << scale[note] << note_octave << ", ";
                ++note;
                while (note > 12) {
                    note -= 13;
                    ++note_octave;
                } 
            }
        }
        else {
            cout << "Your melody is: ";
            for (int i = 0; i < 7; ++i) {
                cout << scale[note] << note_octave << ", ";
                --note;
                while (note < 0) {
                    note += 13;
                    --note_octave;
                } 
                if (note_octave < 1) {
                    break;
                }
            }
        }
        cout << endl;
    }
    
    return 0;
}