/*
	Charles Park
	Section 5
	2/10/23
	Assignment 4	
*/

/*  
   Missing Work: 
      - There is no running commentary
   
   Extra Work:
      - Game menu
      - Customizable playing options
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class NimGame {
   private:
      int num_objects; 
      int min_moves;
      int max_moves;
      string player;
      string computer;

   public:
      NimGame() {
         num_objects = 23; 
         min_moves = 1;
         max_moves = 3;
         player = "Player";
         computer = "Computer";
      }
      NimGame(int _num_objects, int _min_moves, int _max_moves, string _player, string _computer) {
         num_objects = _num_objects;
         min_moves = _min_moves;
         max_moves = _max_moves;
         player = _player;
         computer = _computer;
      }

      int getObjects() {
         return num_objects;
      }
      void setObjects(int _num_objects) {
         num_objects = _num_objects;
      }

      int getMinMoves() {
         return min_moves;
      }
      void setMinMoves(int _min_moves) {
         min_moves = _min_moves;
      }

      int getMaxMoves() {
         return max_moves;
      }
      void setMaxMoves(int _max_moves) {
         max_moves = _max_moves;
      }

      string getPlayer() {
         return player;
      }
      void setPlayer(string _player) {
         player = _player;
      }

      string getComputer() {
         return computer;
      }
      void setComputer(string _computer) {
         computer = _computer;
      }

      int nim() 
      {
         system("clear");
         srand(time(NULL));
         int current_player = rand() % 2;
         if (current_player) {
            cout << player << " goes first\n";   
         } else {
            cout << computer << " goes first\n";
         }
         cout << "Press enter to continue.\n";
         cin.ignore();
         
         string temp;
         int move; 
         do {
            system("clear");
            cout << "Remaining objects (" << num_objects << "):\n";
            for (int i = 1; i <= num_objects; i++)
            {
               cout << "*";
            }
            cout << "\n";

            if (current_player) {   
                  cout << player << " enter your move (" << min_moves << "-" << max_moves << "): "; 
                  getline(cin, temp);
                  if (isdigit(temp[0])) {
                     move = stoi(temp);
                  } else {
                     move = 0;
                  }
                  while (move < min_moves || move > max_moves || move > num_objects){
                     if (min_moves >= num_objects) {
                        break;
                     }
                     cout << "Illegal move. \nEnter a new move (" << min_moves << "-" << max_moves << "): "; 
                     getline(cin, temp);
                     if (isdigit(temp[0])) {
                     move = stoi(temp);
                     } else {
                        move = 0;
                     }
                  }
            } else {   
                  if (num_objects <= max_moves) {
                     if (num_objects <= min_moves) {
                        move = min_moves;
                     } else {
                        move = num_objects - 1;
                     }
                  } else {
                        move =  min_moves + (rand() % (max_moves - min_moves + 1));
                  }
                  cout << computer << " removed " << move << endl;
            }
            num_objects = num_objects - move; 
            cout << "Press enter to continue.\n";
            cin.ignore();

            current_player = (current_player + 1) % 2; 
         } while (num_objects > 0);
         
         return current_player;
      }
};


int main() {
   int winner;
   NimGame game;
   NimGame settings;
   bool run = true;
   int input;
   string str_input;

   while (run) {
      system("clear");
      cout << "---------- NIM ----------\n"
           << "1. Play Game\n"
           << "2. How to Play\n"
           << "3. Settings\n"
           << "4. Quit\n";
      getline(cin, str_input);
      if (isdigit(str_input[0])) {
      input = stoi(str_input);
      } else {
         input = 0;
      }
      if (input == 1) {
         game = settings;
         winner = game.nim();
         if (winner) {
            cout << game.getPlayer() << " wins!!!\n";
         } else {
            cout << game.getComputer() << " wins!!!\n";
         }
         cout << "Press enter to continue.\n";
         cin.ignore();
      } else if (input == 2) {
         system("clear");
         cout << "---------- How to Play ----------\n"
              << "You or the computer will be picked to go first\n"
              << "Take turns removing objects\n"
              << "Whoever has to take the last object loses\n"
              << "Press enter to go back.\n";
         cin.ignore();
      } else if (input == 3) {
         while (run) {
            system("clear");
            input = 0;
            cout << "--------- Settings ----------\n"
               << "1. Change number of objects\n"
               << "2. Change minimum number of moves\n"
               << "3. Change maximum number of moves\n"
               << "4. Change player name\n"
               << "5. Change computer name\n"
               << "6. Back\n";
            getline(cin, str_input);
            if (isdigit(str_input[0])) {
            input = stoi(str_input);
            } else {
               input = 0;
            }
            if (input == 1) {
               cout << "Number of objects: " << settings.getObjects() << "\n"
                    << "Enter new starting amount: ";
               getline(cin, str_input);
               if (isdigit(str_input[0])) {
               input = stoi(str_input);
               } else {
                  input = 0;
               }
               if (input <= 0) {
                  cout << "Invalid input. Settings unchanged.\n";
               } else {
                  settings.setObjects(input);
               }
               cout << "Press enter to continue.\n";
               cin.ignore();
            } else if (input == 2) {
               cout << "Minimum moves: " << settings.getMinMoves() << "\n"
                    << "Enter new amount: ";
               getline(cin, str_input);
               if (isdigit(str_input[0])) {
               input = stoi(str_input);
               } else {
                  input = 0;
               }
               if (input <= 0 || input > settings.getMaxMoves()) {
                  cout << "Invalid input. Settings unchanged.\n";
               } else {
                  settings.setMinMoves(input);
               }
               cout << "Press enter to continue.\n";
               cin.ignore();
            } else if (input == 3) {
               cout << "Maximum moves: " << settings.getMaxMoves() << "\n"
                    << "Enter new amount: ";
               getline(cin, str_input);
               if (isdigit(str_input[0])) {
               input = stoi(str_input);
               } else {
                  input = 0;
               }
               if (input < settings.getMinMoves()) {
                  cout << "Invalid input. Settings unchanged.\n";
               } else {
                  settings.setMaxMoves(input);
               }
               cout << "Press enter to continue.\n";
               cin.ignore();
            } else if (input == 4) {
               cout << "Current name: " << settings.getPlayer() << "\n"
                    << "Enter new name: ";
               getline(cin, str_input);
               settings.setPlayer(str_input);
               cout << "Press enter to continue.\n";
               cin.ignore();
            } else if (input == 5) {
               cout << "Current computer name: " << settings.getComputer() << "\n"
                    << "Enter new name: ";
               getline(cin, str_input);
               settings.setComputer(str_input);
               cout << "Press enter to continue.\n";
               cin.ignore();
            } else if (input == 6) {
               run = false;
            } else {
               cout << "Invalid input. Press enter to continue.\n";
               cin.ignore();
            }
         }
         run = true;
      } else if (input == 4) {
         system("clear");
         cout << "Thanks for playing!\n";
         run = false;
      } else {
         cout << "Invalid input. Press enter to continue.\n";
         cin.ignore();
      }
   }

   return 0;
}