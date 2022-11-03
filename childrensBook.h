//---------------------------------------------------------------------------
// CHILDRENSBOOK.H
// Class ChildrensBook represents a book from the children's book genre
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// ChildrensBook class:
//      -- stores information regarding a children's book
//      -- Derived from Book
// Assumptions:
//      -- The text is formatted correctly when reading
//      -- The genre is a childrens book
//---------------------------------------------------------------------------
#ifndef _CHILDRENSBOOK_H
#define _CHILDRENSBOOK_H

#include <iostream>
#include <fstream>
#include "book.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// ChildrensBook class represents a book from the children's book genre
class ChildrensBook : public Book {

public:
  // Constructor - creates a children's book
  ChildrensBook();

  // Destructor - deallocates children's book
  virtual ~ChildrensBook();

  string getAuthor() const;

  // Creates an Item that is a children's book
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  virtual void setCommandData(ifstream&);

  // operator<< helper
  //virtual void displayHelper(ostream &) const;

  //Displays the data of the childrens book object without the number of copies
  virtual void display() const;

  //Displays the data of the childrens book object with the number of copies
  virtual void displayData() const;

  // Displays the headers
  virtual void displayHeader() const;
  
  // == operator - returns if two  children's books are equal
  virtual bool operator==(const NodeData &) const;

  // < operator - returns true if current children's book is less than 
  //    given children's book
  virtual bool operator<(const NodeData &) const;

private:
  string author;
};

#endif