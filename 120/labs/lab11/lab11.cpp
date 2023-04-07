#include<iostream>
using namespace std;

void fill(int a[][6], int, int);
void increment(int a[][6], int, int);

int main(){
   int a[3][6];
   fill(a,3,6);
   increment(a,3,4);
   int *p; 
   p = (int *)a;
   *p = 99;
   p[6] = 77;
   p = &a[2][2];
   p--;
   *p = 66;
   p = (int *)(a[0]+4);
   *p = 44;
   p = (int *)(a+2);
   *p = 55;
   for(int r = 0; r < 3; r++){
     for(int c = 0; c < 6; c++){
        cout << a[r][c] << ", ";
     }
     cout << endl;  // Why?
   }
}


void fill(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] = (r+1)*(c+1);
     }
  }
}

void increment(int data[][6], int rows, int columns){
  for(int r = 0; r < rows; r++){
     for(int c = 0; c < columns; c++){
        data[r][c] += 1;
     }
  }
}
