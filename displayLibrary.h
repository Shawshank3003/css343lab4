//---------------------------------------------------------------------------
// DISPLAY_LIBRARY.H
// Class DisplayLibrary displays all the contents of the library
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// DisplayLibrary class:
//      -- Displays all the media in the library grouped in categories
//      -- Displayed in a sorted order
//      -- Derived from PatronAction
// Assumption:
//      -- DisplayLibrary is read from the text
//---------------------------------------------------------------------------
#ifndef _DISPLAYLIBRARY_H
#define _DISPLAYLIBRARY_H

#include <iostream>
#include <fstream>
#include "patronAction.h"
// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//displayLibrary class prints out the contents in the Library
class DisplayLibrary : public PatronAction {
// << operator - prints class data to output stream
friend ostream & operator<<(ostream &, const DisplayLibrary &);

public:
  // Constructor - creates a new DisplayLibrary object
  DisplayLibrary();

  // Destructor
  virtual ~DisplayLibrary();

  // Returns an instance PatronAction that is a displayLibrary
  virtual PatronAction* create() const;

  // Sets the data for the member variable
  virtual bool setData(Library *, ifstream&);

  virtual void display() const;
  
  // Prints out the contents of the library
  virtual bool perform();
private:
  
};

#endif