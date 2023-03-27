#include<iostream>
#include<string>
using namespace std;
class pet{
   private:
      int hunger;           // private data member
      string name;          // private data member
      int happy;            // private data member
   public:
      pet();                // constructor
      void interact();      // public member function
      void play();          // public member function
      void feed();          // public member function
      void print();         // public member function
      void print_name();    // public member function
      void change_stats(int change_hunger, int change_happy);
      int check_health();   // public member function
};

/* Constructor, creates a new pet with starting values. */
pet::pet(){
     hunger = 50;
     happy = 50;
     cout << "Pet's name? ";
     getline(cin,name);  // allows spaces in the name
}

/* Member function interact(), allows player to interact with a pet. */
void pet::interact(){
    system("clear");
    print();
    int choice;
    cout << "What would you like to do with your pet?\n";
    cout << " Play (1) \n Feed (2) \n";
    cin >> choice;
    cin.ignore();
    switch(choice){
       case 1:
          play();
          break;
       case 2:
          feed();
          break;
    }
}

/* Member function play(), allows playing with a pet. */
void pet::play(){
    int choice = 0;
    cout << "What should we play?\n";
    cout << " Fetch (1) \n Roll over (2) \n";
    cin >> choice;
    cin.ignore();
    switch(choice){
    case(1):
         happy += 15;
         hunger += 3;
         break;
    case(2):
         happy += 4;
         hunger += 1;
         break;
    default:
         cout << "Not a valid choice." << endl;
   }
}

/* Member function feed(), allows the user to feed a pet. */
void pet::feed(){
    cout << "\nMMM, Yummy!\n";
    hunger -= 5;
}

/* Member function print(), prints information about a pet. */
void pet::print(){
    cout << "Your pet " << name << " is:\n";
    cout << " Happy: " << happy << endl;
    cout << " Hungry: " << hunger << endl;
}

/* Member function print_name(), prints the pets name. */
void pet::print_name() {
     cout << name << "\n";
}

/* Member function change_stats(), changes the pets stats. */
void pet::change_stats(int change_hunger, int change_happy) {
     hunger += change_hunger;
     happy += change_happy;
}

/* Member function check_health(), checks the health of a pet. */
int pet::check_health(){
    if(hunger >= 100){
         cout << "\nYour pet has starved.\n";
         return 1;
    }
    if(happy <= 0){
         cout << "\nYour pet has died of a broken heart.\n";
         return 1;
    }
    return 0;
}    