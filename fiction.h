//---------------------------------------------------------------------------
// FICTION.H
// Class Fiction represents the fiction genre of a book
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Fiction class: 
//      -- Represents the fiction genre of a book
//      -- Derived from book
// Assumptions:
//      -- The text is formatted correctly when reading
//      -- The genre is a fiction book
//---------------------------------------------------------------------------
#ifndef _FICTION_H
#define _FICTION_H


#include <iostream>
#include <fstream>
#include "book.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//Fiction class represents the fiction genre/subclass of the book object
class Fiction : public Book {

public:
  // Default constructor
  Fiction();

  // Destructor
  virtual ~Fiction();

  // Creates an Item that is a fiction book
  virtual Item* create() const;

  // Sets the data for the member variables
  virtual void setData(ifstream&);

  //sets the data of the fiction object
  virtual void setCommandData(ifstream&);

    //Displays the data of the fiction book object without the number of copies
    virtual void display() const;

    //Displays the data of the fiction book object with the number of copies
    virtual void displayData() const;

    // Displays the headers
    virtual void displayHeader() const;
  
  // Comparison operators
  virtual bool operator==(const NodeData &) const;
  virtual bool operator<(const NodeData &) const;

private: 
  string author;  // the author of the book
};

#endif