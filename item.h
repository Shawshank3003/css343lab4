//---------------------------------------------------------------------------
// ITEM.H
// Class Item represents an item from the library
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Item class:
//      -- Represents an item from the library
//      -- Derived from nodedata
// Assumptions and Implementations:
//      -- Pure virtual most functions for implementations in subclasses.
//      -- Increase, decrease, get number of copies in the library and number
//         of copies that were checked out.
//---------------------------------------------------------------------------
#ifndef _ITEM_H
#define _ITEM_H

#include <iostream>
#include <fstream>
#include "nodedata.h"
#include <iomanip>

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Item class represents the items in a library.
class Item : public NodeData {

public:
  // Constructor - Creates the Item object
  Item();

  // Destructor - Deallocates the Item object
  virtual ~Item();

  // Increases the number of copies by 1
  void incrementCopies();

  // Decreases the number of copies by 1
  void decrementCopies();

  // Returns the number of copies in the library
  int getNumOfCopiesIn();

  //Returns the number of copies checked out
  int getNumOfCopiesOut();

  // creates an item
  virtual Item* create() const = 0;

  virtual string getBookTitle() const = 0;

  // Sets the data for the member variables
  virtual void setData(ifstream&) = 0;

  virtual void setCommandData(ifstream&) = 0;

  virtual void display() const = 0;
  
  virtual void displayHeader() const = 0;

  virtual void displayData() const = 0;

  virtual bool operator<(const NodeData&) const = 0;

  virtual bool operator==(const NodeData&) const = 0;

protected:
  int numOfCopiesIn;
  int totalCopies; // number of copies of the book owned by the library
};
#endif