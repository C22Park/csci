#include<iostream> 
#include<string>
#include"pet.h"
using namespace std; // declaration of the pet class 

int main() {
   // Ask the user how many pets they want 
   system("clear");
   int num_pets;
   cout << "How many pets do you want to have?\n";
   cin >> num_pets;
   cin.ignore();
   // Create and initialize that many pets
   pet pets[num_pets];
   // Game loop:
   bool run = true;
   int temp;
   while (run) {
      system("clear");
      // Ask the player which pet they want to interact with
      cout << "Which pet do you want to interact with?\n";
      for (int i = 0; i < num_pets; i++) {
         cout << i + 1 << ". ";
         pets[i].print_name();
         if (i + 1 == num_pets) {
            cout << i + 2 << ". Quit\n";
         }
      }
      // Have the player interact with that pet
      cin >> temp;
      cin.ignore();
      if (temp > 0 && temp <= num_pets) {
         pets[temp - 1].interact();
      } else if (temp == num_pets + 1) {
         run = false;
      } else {
         cout << "Invalid Input. Press enter to continue.\n";
         cin.ignore();
         cin.ignore();
      }
      cout << "Press enter to continue.\n";
      cin.ignore();
      system("clear");
      // Add 2 hunger and subtract 2 happy from every pet
      for (int i = 0; i < num_pets; i++) {
         pets[i].change_stats(2, -2);
      }
      // Print all of the pets
      if (run) {
         for (int i = 0; i < num_pets; i++) {
            pets[i].print();
         }
         cout << "Press enter to continue.\n";
         cin.ignore();
      }
      // Use check_health to see if all of the pets are healthy
      for (int i = 0; i < num_pets; i++) {
         if (pets[i].check_health()) {
            run = false;
         }
      }
      // If a pet died, or the player asked to quit, exit the loop, otherwise loop
   }
   // Print an appropriate exit message
   cout << "Thanks for playing!\n"
        << "Press enter to exit.\n";
   cin.ignore();
   return 0;
}