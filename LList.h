#ifndef LLIST_H
#define LLIST_H
/* 
 Last Name:
 First Name:
 Student Number:
 Assignment #2, CPSC 2150 (expanded on code started by Gladys Monagan) Fall 2019

 ASSIGNMENT: Comment on what the class does
*/

#include <string>
class  LList {
   public:
      // create an empty list
      LList();

      // determine if the list is empty
      bool isEmpty() const;

      // insert x at the beginning of the list
      // precondition: there is enough heap memory
      // postcondition: x is placed in the list as first element
      void cons(int x);

      // append x to the end of the list
      // precondition: there is enough heap memory
      // postcondition: x is placed as the last element
      void append(int x);

      // return a string consisting of all the elements of the list
      // in the order in which they are in the list from first to last in this format:
      //    -> the string starts with "[" followed by the LList::DELIMITER
      //    -> for each element: the element's value followed by the LList;:DELIMITER
      //    -> the string finishes with "]"
      // e.g. a string of 3 elements  "[ 41 36 999 ]"
      std::string toString() const;

      // return the number of elements in the list
      int length() const;

      // search x in the list
      // postcondition: return true if found, false otherwise
      bool found(int x) const;

      // return the first element of the list and LList::NOT_DEFINED if the list is empty
      int first() const;

      // return the last element of the list and LList::NOT_DEFINED if the list is empty
      int last() const;

      // delete the first occurrence of x in the list 
      // postcondition: return true if x was removed, false otherwise
      // give the length of the list, i.e. the number of elements in this list
      bool remove(int x);

      // mutator method (function) that reverses the list
      void reverse();

      // mutator method to transfer all the elements from the 'other' list into 
      // this list and place them at position pos of this list
      //    e.g. when pos == 0, all the elements of the 'other' list will
      //    be placed before the (original) elements of this list
      //    if pos >= length(), (i.e. if pos is greater than the length of this list),
      //    then all the elements of the 'other' list are appended to this list
      // precondition: pos >= 0, length() >= 0, other.length() >= 0
      // postcondition: all the elements of the 'other' list are removed from the 'other' list 
      // and placed into this list starting at position pos
      // The lengths of both lists change: 
      //    other.length() becomes 0 (all the elements get removed)
      // All the elements of the 'other' list are now in this list and the first element
      // of the 'other' list is at position pos of this list or at the end if pos >= length()
      void splice(LList& other, int pos);

      // return true if the lfSide list is equal to the rtSide list
      friend bool operator == (const LList& lfSide, const LList& rtSide);

      // copy constructor
      // we assuming that there is enough heap memory to make a copy
      LList(const LList&);

      // overloaded assignment operator
      // we assuming that there is enough heap memory to make a copy
      LList& operator = (const LList&);

      // destructor
      ~LList();

      // string that separates the values of the list in toString 
      static const std::string DELIMITER;

      // value returned when there is no last or no first element in the list
      static const int NOT_DEFINED;

   private:
      struct Node {
         int item;
         Node* next;
      };
      
      //-----------------------------------------------------------------------
      // ASSIGNMENT requirement: you CANNOT have a tail pointer
      // you can only have a head pointer pointing to the beginning of the list
      //-----------------------------------------------------------------------
      Node* head;
      
      // returns a string with an opening "[", 
      // followed by the delimiter followed by each element of the 
      // list which is followed by a delimiter with a "]" closing the list
      static std::string toString(Node * p, std::string delimiter);
 
};
 
#endif
