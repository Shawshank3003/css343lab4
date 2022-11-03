//---------------------------------------------------------------------------
// _PATRON_ACTION.H
// Class PatronAction is a support class of Patron.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// PatronAction class: contains all the functions/actions a patron can do.
//               -- has the getters and setters for associated patron and
//                  item.
//
// Assumptions/implementation:
//      -- patron.h has been implemented
//      -- item.h has been implemented
//---------------------------------------------------------------------------
#ifndef _PATRON_ACTION_H
#define _PATRON_ACTION_H

#include <iostream>
#include <fstream>
#include "patron.h"
#include "item.h"
#include "hashtable.h"
#include "itemFactory.h"
#include "bintree.h"


// Only for class code, OK to use namespace
using namespace std;

class Library;

//---------------------------------------------------------------------------
// PatronAction class represents actions a patron can take.
class PatronAction {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const PatronAction &);

public:
  // Constructor - Creates the PatronAction
  PatronAction();

  // Destructor - Deallocates the PatronAction
  virtual ~PatronAction();

  // Getter - gets the associated Patron
  virtual Patron* getAssociatedPatron() const;

  // Getter - gets the associated item
  virtual Item* getAssociatedItem() const;

  // Sets the data for the member variables
  virtual bool setData(Library*, ifstream&) = 0;

  // operator<< helper
  virtual void display() const = 0;
  
  // creates the patron action
  virtual PatronAction* create() const = 0;

  // Performs the patron action
  virtual bool perform() = 0;

  virtual string getAction() const;

protected:
  Library* lib;
  Patron* associatedPatron;  // the patron associated with the action
  Item* associatedItem;      // the item associated with the action
  string action;         // the type of action
};

#endif