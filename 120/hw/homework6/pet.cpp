/*
Charles Park
Section 5
2/21/23
Assignment 6	
*/

#include<iostream>
#include<string>
#include <cstdlib>

using namespace std;

// declaration of the pet class
class pet {
     private:
     int hunger;           // private data member
     string name;          // private data member
     int happy;            // private data member
     int health;           // private data member

     public:
     pet();                // constructor
     void play();          // public member function
     void feed();          // public member function
     void rest();          // public member function
     void print();         // public member function
     int check_health();   // public member function
};

int main() {
     pet pet1;
     int choice;
     int health_check;
     do {
          pet1.print();
          cout << "What would you like to do with your pet?\n";
          cout << " Play (1) \n Feed (2) \n Rest (3) \n Exit (0) \n";
          cin >> choice;
          switch (choice) {
               case 1:
                    pet1.play();
                    break;
               case 2:
                    pet1.feed();
                    break;
               case 3:
                    pet1.rest();
                    break;
               case 0:
                    cout << "Your pet will miss you!\n";
                    break;
          }
          health_check = pet1.check_health();
     } while (choice != 0 && health_check != 1);
     cin.ignore();
     cout << "Press enter to exit." << endl;
     cin.ignore();
     return 0;
}

/* Constructor, creates a new pet with starting values. */
pet::pet() {
     hunger = 50;
     happy = 50;
     health = 50;
     cout << "Pet's name? (One word) ";
     cin >> name;
}
/* Member function play(), allows playing with a pet. */
void pet::play() {
     int choice = 0;
     cout << "\nWhat should we play?\n";
     cout << " Fetch (1) \n Roll over (2) \n";
     cin >> choice;
     switch (choice) {
          case(1):
               happy += 10;
               hunger += 5;
               health -= 5;
               break;
          case(2):
               happy += 5;
               hunger += 1;
               break;
          default:
               cout << "Not a valid choice." << endl;
     }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed() {
     srand(time(NULL));
     switch (rand() % 4 + 1) {
          case 1:
               cout << "\nMMM, Yummy!\n";
               break;
          case 2:
               cout << "\nYay my favorite!\n";
               break;
          case 3:
               cout << "\nThat hit the spot.\n";
               break;
          case 4:
               cout << "\nThat shit bussing fr.\n";
               break;
     }     
     hunger -= 5;
     health += 1;
}

/* Member function rest(), allows the user to let the pest rest. */
void pet::rest() {
     cout << "\nZZZzzzZZZZ, so sleepy.\n";
     health += 5;
     happy += 1;
     hunger += 1;
}

/* Member function print(), prints information about a pet. */
void pet::print() {
     bool no_answer = false;
     cout << name << " says, \"";
     if (hunger >= 50) {
          if (hunger >= 75) {
               cout << "I'm starving! ";
          } else {
               cout << "I'm a little hungry. ";
          }
          no_answer = true;
     }
     if (happy <= 30) {
          cout << "I'm feeling a little sad, play with me sometime. ";
          no_answer = true;
     }
     if (health <= 30) {
          cout << "I'm worn out and could do with some rest. ";
          no_answer = true;
     }
     if (no_answer == false) {
          cout << "I'm doing great! ";
     }
     cout << "\"\n";
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health() {
     if (hunger >= 100) {
          cout << "\nYour pet has starved.\n";
          return 1;
     }
     if (happy <= 0) {
          cout << "\nYour pet has died of a broken heart.\n";
          return 1;
     }
     if (health <= 0) {
          cout << "\nYour pet has died of injuries.\n";
          return 1;
     }
     return 0;
}