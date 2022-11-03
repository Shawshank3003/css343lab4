//---------------------------------------------------------------------------
// RETURN.H
// Class return checks out an item and is the subclass of patronAction.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Return class: contains a create and perform function which help with the
//               checkout action.
//        Derived from PatronAction
// Assumptions:
//      -- Patron and PatronAction have been implemented
//---------------------------------------------------------------------------
#ifndef _RETURN_H
#define _RETURN_H

#include <iostream>
#include <fstream>
#include "patronAction.h"

// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
// Return class represents the checkout action a patron can take.
class Return : public PatronAction {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const Return &);

public:
  // Constructor
  Return();

  // Destructor
  virtual ~Return();

  // Returns an instance of PatronAction that is a Return object
  virtual PatronAction* create() const;

  // Sets the data for the member variables
  virtual bool setData(Library*, ifstream&);

  //Displays the return
  virtual void display() const;
  
  // Performs the return action
  virtual bool perform();

private:
  char itemType;
  Item* tempItem;
};
#endif