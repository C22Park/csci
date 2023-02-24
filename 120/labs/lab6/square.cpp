/*
	Charles Park
	Section 5
	2/21/23
	Lab 6
*/

#include<iostream>

using namespace std;

// *** Prototypes of functions ****
int get_side();
char get_symbol();
int print_rectangle(int,int,char);

int main(){
  int side1, side2, num_symbols;
  char c;

  side1 = get_side();
  side2 = get_side();
  c = get_symbol();
  num_symbols = print_rectangle(side1,side2,c);
  cout << num_symbols << " characters were printed.\n\n";
}

//*** put your functions here ****
int get_side() {
  int size;
  bool valid;

  cout << "Please enter a side length between 1 and 10: ";
  cin >> size;
  cin.ignore();
  if (size >= 1 && size <= 10) {
    valid = true;
  } else {
    valid = false;
  }

  while (valid == false) {
    cout << "The side must be between 1 and 10.\n"
         << "Please try again: ";
    cin >> size;
    cin.ignore();
    if (size >= 1 && size <= 10) {
    valid = true;
    } else {
      valid = false;
    }
  }

  cout << "Thank you.\n";
  return size;
}

char get_symbol() {
  char character;

  cout << "Please enter a character: ";
  cin >> character;
  cin.ignore();

  return character;
}

int print_rectangle(int length, int width, char character) {
  int count = 0;

  for (int i = 0; i < length; i++) {
    for (int j = 0; j < width; j++) {
      cout << character;
      count++;
    }
    cout << "\n";
  }

  return count;
}