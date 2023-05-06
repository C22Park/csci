#include<iostream>
using namespace std;
#include"hw13.h"

int main(){
   linkedlist animals;
   node *p;
   p = new node();
   p->setdata("cat");
   animals.push(p);

   p = new node();
   p->setdata("dog");
   animals.push(p);

   p = new node();
   p->setdata("unicorn");
   animals.push(p);

   p = new node();
   p->setdata("donkey");
   animals.push(p);

   p = new node();
   p->setdata("dragon");
   animals.push(p);

   animals.print();
   cout << animals.length() << "\n";
   animals.append("giraffe");
   animals.print();
   cout << animals.length() << "\n";
   cout << animals.find("giraffe") << "\n"
        << animals.find("gorilla") << "\n"
        << animals.get(6) << "\n"
        << animals.get(5) << "\n";
}