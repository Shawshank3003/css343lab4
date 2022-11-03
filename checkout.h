//---------------------------------------------------------------------------
// CHECKOUT.H
// Class Checkout checks out an item from the libary
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
// Checkout class: 
//      -- Checks out an item from the library
//      -- Updates the library database
//      -- Updates the patron's history
//      -- Derived from PatronAction
// Assumptions:
//      -- The text format is correct
//      -- The action is checkout
//---------------------------------------------------------------------------

#ifndef _CHECKOUT_H
#define _CHECKOUT_H

#include <iostream>
#include <fstream>
#include "patronAction.h"


// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Checkout class represents the checkout action a patron can take.
class Checkout : public PatronAction {
public:
  // Constructor - creates a checkout action
  Checkout();

  // Destructor - deallocates the checkout
  virtual ~Checkout();

  // Sets the data for the member variables
  virtual bool setData(Library*, ifstream&);

  // Creates a PatronAction that is a checkout
  virtual PatronAction* create() const;

  // Performs the checkout
  virtual bool perform();

  // displays the checkout
  virtual void display() const;

private:
  char itemType;
  Item* tempItem;
  int patronID;
};

#endif