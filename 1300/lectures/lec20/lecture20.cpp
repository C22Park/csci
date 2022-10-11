#include <iostream>

using namespace std;

class Counter {

   private:
      int value;

   public:
      void count() {

         value += 1;
      }

      void reset() {

         value = 0;
      }

      int getCount() {
         return value;
      }

   Counter() {
      'value = 0;
   }
};

int main() {

   Counter my_counter;

   //my_counter.reset();
   cout << my_counter.getCount() << endl;

   return 0;
}