/* 
* Assignment #2, CPSC 2150, Test Program
* Gladys Monagan
* September 11, 2019
*/
#include "LList.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::cin;
using std::string;


int main() {
   // use the default constructor
   LList p;
   cout << "expecting [ ]\n";
   cout << "actual " << p.toString() << endl;

   p.cons(10);
   p.cons(20);
  p.cons(15);

   cout << "actual " << p.toString() << endl;
   cout << "Length: " << p.length() << endl;
   cout << "First: " << p.first() << endl;
   cout << "Last: " << p.last() << endl;

   /*
   cout << p.remove(20) << endl;
   cout << p.remove(200) << endl;
   */

  p.reverse();
   
   cout << "actual " << p.toString() << endl;

   return 0;
}

