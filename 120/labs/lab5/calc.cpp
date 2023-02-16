/*
	Charles Park
	Section 5
	2/16/23
	Lab 5	
*/

/* A simple calculator program,
controlled by a menu and 
divided into separate functions */

#include <iostream>
#include <math.h>

using namespace std;

//---------- Function Prototypes -----------
void print_menu();
double get_value();
double divide(double, double);
double cyl_sa(double, double);
double cyl_vol(double, double);
double cone_sa(double, double);
//--------------  Main -------------------
int main()
{
       double operand1, operand2, answer;
       int choice, valid_choice;
       do{
              print_menu();
              cin >> choice;
              valid_choice = 1;           // assume choice is valid
              switch(choice){
                     case 0:                    // program will exit
                            valid_choice = 0;
                            break;
                     case 1:                    // addition
                            operand1 = get_value();
                            operand2 = get_value();
                            answer = operand1 + operand2;
                            cout << operand1 << " + " << operand2 << " = " << answer << "\n";
                            break;
                     case 2:
                            operand1 = get_value();
                            operand2 = get_value();
                            answer = operand1 - operand2;
                            cout << operand1 << " - " << operand2 << " = " << answer << "\n";
                            break;
                     case 3:                    // division
                            operand1 = get_value();
                            operand2 = get_value();
                            answer = divide(operand1,operand2);
                            cout << operand1 << " / " << operand2 << " = " << answer << "\n";
                            break;
                     case 4:
                            cout << "Choose a radius. ";
                            operand1 = get_value();
                            cout << "Choose a height. ";
                            operand2 = get_value();
                            answer = cyl_sa(operand1, operand2);
                            cout << "Your answer: " << answer << "\n";
                            break;
                     case 5:
                            cout << "Choose a radius. ";
                            operand1 = get_value();
                            cout << "Choose a height. ";
                            operand2 = get_value();
                            answer = cyl_vol(operand1, operand2);
                            cout << "Your answer: " << answer << "\n";
                            break;
                     case 6:
                            cout << "Choose a radius. ";
                            operand1 = get_value();
                            cout << "Choose a height. ";
                            operand2 = get_value();
                            answer = cone_sa(operand1, operand2);
                            cout << "Your answer: " << answer << "\n";
                            break;
                     default:
                            valid_choice = 0;   // choice is invalid
                            cout << "Invalid Choice." << endl;
              }
       }while(choice != 0);    // if not 0, loop back to start
       return 0;
}

//--------------  Functions -------------------
double divide(double dividend, double divisor){
      if(divisor == 0){
            return 0;  // avoids divide by zero errors
      }
      else
            return (dividend/divisor);
}
//----------------- get_value function ----------------
double get_value(){
      double temp_value;
      cout << "Please, enter a value: ";
      cin >> temp_value;
      cout << "Thanks." << endl;
      return temp_value;
}
//-------------------- print_menu function -------------
void print_menu(){
       cout << "\nAdd (1)\n"
            << "Subtract (2)\n"
            << "Divide (3)\n"
            << "Surface Area of a Right Cylinder (4)\n"
            << "Volume of a Right Cylinder (5)\n"
            << "Surface Area of a Right Circular Cone (6)\n"
            << "Exit (0)\n"
            << "Enter your choice: ";
}
//-------------------- cyl_sa function -------------
double cyl_sa(double radius, double height) {
       return ((2 * M_PI * radius * height) + (2 * M_PI * radius * radius));
}
//-------------------- cyl_vol function -------------
double cyl_vol(double radius, double height) {
       return (M_PI * radius * radius * height);
}
//-------------------- cone_sa function -------------
double cone_sa(double radius, double height) {
       double temp = (height * height) + (radius * radius);
       temp = sqrt(temp);
       return ((M_PI * radius) * (radius + temp));
}