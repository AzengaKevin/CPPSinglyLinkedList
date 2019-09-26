/* 
 Last Name:
 First Name:
 Student Number:
 Assignment #2, CPSC 2150 (expand code started by Gladys Monagan) Fall 2019
 The class LList .....
*/

#include "LList.h"
#include <string>
#include <sstream>

using std::string;

const string LList::DELIMITER = string(" ");
const int LList::NOT_DEFINED = -1;

// constructor with no arguments, create the empty list
LList::LList() {
   this->head = nullptr;  
}

/**
 * Retruns true if the list is empty and false otherwise
 * @return bool
 */
bool LList::isEmpty() const {
   return this->head == nullptr;
}

/**
 * 
 * Checks whether theList null first
 * if null it sets the item to be th head 
 * else it prepends the item on the list
 * 
 */
void LList::cons(int x){
   Node *newNode = new Node;
   newNode->item = x;
   newNode->next = nullptr;
   
   if(this->head == nullptr){
      this->head = newNode;
   }else{
      newNode->next = head;
      head = newNode;
   }
}

/**
 * 
 * 
 * 
 */

void LList::append(int x){

   Node *newNode = new Node;
   newNode->item = x;
   newNode->next = nullptr;

   if(head == nullptr){
      head = newNode;
   }else{

      Node *tempNode = head;
      Node *prevNode = nullptr;

      while (tempNode != nullptr)
      {
         prevNode = tempNode;

         tempNode = tempNode->next;
      }

      prevNode->next = newNode;
      
   }
}

// make a string from the values of the list in this->head and return it
// precondition:
//   LList::DELIMETER has been initialized
// postcondition:
//    return a string of the form [ DELIMITER element ... DELIMITER element ]
string LList::toString() const {
   string str = "[";
   str += toString(this->head, DELIMITER);
   str += "]";
   return str;
}

// make a string from the elements in p using the delimiter to separated the elements
// postcondition:
//    return a string of the form [ delimiter element ... delimiter element ]
string LList::toString(Node * p, string delimiter) {
   if (p == nullptr) {
      return delimiter;
   }
   std::stringstream ss;
   ss << delimiter;
   ss << p->item;
   ss << toString(p->next, delimiter);
   return ss.str();
}

/**
 * Getting the length of the list
 * 
 * Loop through the data until you get to the null pointer from the heade
 * 
 * @return int size
 */

int LList::length() const {
   int count = 0;

   Node *tempNode = head;

   while (tempNode != nullptr)
   {
      count++;

      tempNode = tempNode->next;
   }
   
   return count;
}

/**
 * Search for an Item in the list
 * 
 * @return bool found
 * 
 */

bool LList::found(int x) const {
   bool returnValue = false;

   Node *tempNode = head;

   while (tempNode != nullptr)
   {
      if(tempNode->item == x){
         returnValue = true;
         break;
      }
   }

   return returnValue;

}

/**
 * Retursn the first element of the lisr
 * 
 * @return int first item
 * 
 */
int LList::first() const {
   if(head == nullptr) return NOT_DEFINED;
   else return head->item;
}

/**
 * Returns the last element of the array
 */

int LList::last() const{
   if(head == nullptr) return NOT_DEFINED;

   Node *lastNode = nullptr;
   Node *tempNode = head;

   while (tempNode != nullptr)
   {
      lastNode = tempNode;

      tempNode = tempNode->next;
   }

   return lastNode->item;
   
}

/**
 * 
 * Checks whether the element is the first on the list first
 * if so checks whether the list has one element or whether it has more and change the pointers or delete the list entirely
 * else checks whether the element is the last is btwn other elements and behave accordingly
 * 
 */

bool LList::remove(int x){

   if(head->item == x){

      if(head->next == nullptr){
         delete head;

         head = nullptr;
      }else{
         Node *nodeToDelete = head;

         head = head->next;

         delete nodeToDelete;

      }

      return true;

   }

   Node *beforeNode;
   Node *currentNode = head;
   bool itemFound = false;

   while(currentNode != nullptr){

      if(currentNode->item == x){
         itemFound = true;
         break;
      }

      beforeNode = currentNode;

      currentNode = currentNode->next;

   }

   if(!itemFound)return false;

   if(currentNode->next == nullptr){
      beforeNode->next = nullptr;
      delete currentNode;
   }else{
      beforeNode->next = currentNode->next;
      delete currentNode;
   }


   return true;

}

void LList::reverse(){

   if(head == nullptr || head->next == nullptr) return;

   Node *tempNode = head;

   head = nullptr;
   
   while (tempNode != nullptr){

      cons(tempNode->item);

      tempNode = tempNode->next;
      
   }
   
}



// destructor
// postcondition: 
//   NEEDS comment
LList::~LList(){
   // NEEDS code .... empty for now
}
