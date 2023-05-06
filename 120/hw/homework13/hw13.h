// First Define a node class, then define a linked list class
class node{
   private:
     node *next;
     string name;
   public:
     void setnext(node *n){next = n;} // inline function
     void setdata(string n){name = n;}  // inline function
     void print(); // defined below
     void clear();
     void append(string);
     int find(string);
     string get(int);
};

void node::clear(){
   if(next != NULL)
      next -> clear();
   delete this;
}

void node::print(){
   cout << name << endl;
   if(next != NULL)
      next -> print();
}

void node::append(string _name) {
  if (next != NULL) {
    next -> append(_name);
  } else {
    node *addition;
    addition = new node();
    addition -> setdata(_name);
    addition -> setnext(NULL);
    next = addition;
  }
}
int node::find(string _name) {
   if (next != NULL) {
      if (name == _name) {
         return 1;
      }  
      if (next -> find(_name) == 1) {
         return 1;
      }
   }
   if (name == _name) {
      return 1;
   }
   return 0;
}

string node::get(int n) {
   n--;
   if (n == 0) {
      return name;
   } else {
      return next -> get(n);
   }
}

// Definition of the linked list class

class linkedlist{
   private:
     node *head;
     int len;
   public:
     linkedlist();
     void push(node *);
     int length() {return len;}
     void print();
     void clear();
     void append(string);
     int find(string);
     string get(int);
};

linkedlist::linkedlist(){ // constructor
   head = NULL;
   len = 0;
}

void linkedlist::push(node *n){
  n->setnext(head);
  head = n;
  len = len + 1;
}

void linkedlist::print(){
  if(head != NULL){
     head -> print();
  }
}

void linkedlist::clear(){
  if(head != NULL){
     head-> clear();
  }
  head = NULL;
  len = 0;
}

void linkedlist::append(string name) {
   head -> append(name);
   len++;
}

int linkedlist::find(string name) {
   int found;
   found = head -> find(name);
   return found;
}

string linkedlist::get(int n) {
   if (n > len || len == 0) {
      return "";
   }
   return head -> get(n);
}