#include<iostream>
 #include<string>
 #include<fstream>
 #include<ctime>
 #include<cstdlib>
 using namespace std;
                            // Declaration of the square class
class square{
  private:
    int move;
    string message;
    char symbol;
  public:
    square();
    void print();
    int action();
    void set(int,char,string);
};
                            // Function Prototypes
void print_board(square[], int, int);
void read_board(square[]);
void check_position(int &);
                           // Global variables
const int board_length = 20;

int main(){
  cout << "Welcome to Gold Run\n"
       << "The goal of this game is to obtain the most gold possible in the map before someone finishes.\n"
       << "You will roll each turn and depending on the space either move or get gold.\n"
       << "First person to finish gets 10 additional gold and the winner is whoever has the most at the end.\n"
       << "Have fun! Press enter to continue.\n";
  cin.ignore();
  int current_player = 1, roll;
  int player1_position = 0, player2_position = 0;
  int player1_gold = 0, player2_gold = 0;
  int position_check = 0;
  square the_board[board_length];  // declare an array of squares
  srand(time(NULL));
  read_board(the_board);
  cout << "Player 1 Gold: " << player1_gold << "  |  Player 2 Gold: " << player2_gold << "\n";
  print_board(the_board,player1_position,1);
  print_board(the_board,player2_position,2);
  do{
     cout<<"\n\n\nPlayer "<<current_player<<" press enter to roll.\n";
     cin.ignore();
     roll = 1 + (rand() % 5);
     cout << "Player "<<current_player<<" rolled a "<<roll<<".\n";
     if(current_player == 1){
         player1_position += roll;
         check_position(player1_position);
         position_check = player1_position;
         player1_position += the_board[player1_position].action();
         position_check -= player1_position;
         if (position_check == 0) {
          if (player1_position == 2 || player1_position == 10 || player1_position == 13 || player1_position == 18) {
               player1_gold += 5;
          }
         }
         check_position(player1_position);
     }
     else{
        player2_position += roll;
        check_position(player2_position);
        position_check = player2_position;
        player2_position += the_board[player2_position].action();
        position_check -= player2_position;
        if (position_check == 0) {
          if (player2_position == 2 || player2_position == 10 || player2_position == 13 || player2_position == 18) {
               player2_gold += 5;
          }
         }
        check_position(player2_position);
     }
     cout << "Player 1 Gold: " << player1_gold << "  |  Player 2 Gold: " << player2_gold << "\n";
     print_board(the_board,player1_position,1);
     print_board(the_board,player2_position,2);
     current_player = (current_player % 2) + 1;
  }while((player1_position<board_length-1) && (player2_position<board_length-1));
  current_player = (current_player % 2) + 1;
  if (current_player == 1) {
     player1_gold += 10;
  } else {
     player2_gold += 10;
  }
  cout << "\nPlayer 1 Gold: " << player1_gold << "  |  Player 2 Gold: " << player2_gold << "\n";
  if (player1_gold > player2_gold) {
     cout << "\nPlayer 1 Wins!!!\n";
  } else if (player2_gold > player1_gold) {
     cout << "\nPlayer 2 Wins!!!\n";
  } else {
     cout << "\nIt's a Tie!!!\n";
  }
  cin.ignore();
  return 0;
}


void read_board(square b[]){
     ifstream infile;
     infile.open("game.txt");
     int square_number, square_move;
     string square_message;
     char square_symbol;
     while(!infile.eof()){
         infile >> square_number >> square_move >> square_symbol;
         getline(infile,square_message);
         if(square_number < board_length)
               b[square_number].set(square_move,square_symbol,square_message);
     }
}
void print_board(square b[], int player_position, int player_number){
    cout << " ";
    for(int i = 2; i < board_length; i++)
         cout << "__";
    cout << "_\n";
     for(int i = 0; i < board_length; i++){
         cout << "|";
         if(i != player_position)
             b[i].print();
        else
             cout << player_number;
          
    }
    cout << "Goal\n";
    cout << " ";
    for(int i = 2; i < board_length; i++)
         cout << "‾‾";
    cout << "‾\n";
}
void check_position(int &p){
    if(p < 0)
         p = 0;
    if(p >= board_length)
         p = board_length-1;
}
                           // Functions of the class square
square::square(){
     symbol = ' ';
     move = 0;
     message = "";
}
int square::action(){
     cout << message << endl;
     return move;
}
void square::print(){
     cout << symbol;
}
void square::set(int m, char s, string a_message){
     move = m;
     symbol = s;
     message = a_message;
}