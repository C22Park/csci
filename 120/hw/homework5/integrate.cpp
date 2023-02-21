/*

*/
#include <iostream>

using namespace std;


int main(){
  //function y = x

  int startingX = 0;
  int stoppingX = 0;
  cout << "Enter the lower bounds, then upper bounds for integrating y = x\n";
  cin >> startingX >> stoppingX;

  double height = 0.0;
  double width = 0.0;
  double area = 0.0;
  double stepSize = 0.0;
  double sum = 0.0;
  double Steps = 100000.0;

  stepSize = stoppingX / Steps;

  for(int i = 0; i < Steps; i++){
  double s = startingX + i * stepSize;
  double f = s + stepSize;

  height = (f + s) / 2; // did a middle bound reimann sum versus a right or left
  width = f - s;
  area = height * width;
  sum += area;
  //cout << "Step " << i+1 << " area " << area << endl;
  }
  cout << "Total area: " << sum << endl;



}
