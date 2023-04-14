#include<iostream>
#include<string>
using namespace std;

class node{
   private:
     node *next;
     string name;
   public:
     void setnext(node *n){next = n;} // inline function
     void setdata(string n){name = n;}  // inline function
     void print(); // defined below
     void reverseprint();
};

void node::print(){
   cout << name << "\n";
   if(next != NULL)
      next -> print();
}

void node::reverseprint() {
  if (next == NULL) {
    cout << name << "\n";
    return;
  }
  next -> reverseprint();
  cout << name << "\n";
}

int main(){
  node *head, *temp;  // pointers to a node object
  temp = new node();  // create a new node object
  temp -> setdata("Sally"); // add data
  temp -> setnext(NULL);  // make the next object Null
  head = temp;           // make head point to the beginning of the list
  temp = new node();  // create another new node object
  temp -> setdata("Fred"); // add data
  temp -> setnext(head); // 'point' the new object to the beginning of the list
  head = temp;          // make head point to the new beginning of the list
  temp = new node();    // repeat
  temp -> setdata("Anne");
  temp -> setnext(head);
  head = temp;
  temp = new node();
  temp -> setdata("Alan");
  temp -> setnext(head);
  head = temp;
  cout << "How many Bob's do you want to add to the list?\n";
  int input;
  cin >> input;
  for (int i = 0; i < input; i++) {
    temp = new node();
    temp -> setdata("Bob");
    temp -> setnext(head);
    head = temp;
  }
  head->print();       // print the list
  head -> reverseprint();
}
