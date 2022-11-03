//---------------------------------------------------------------------------
// LIBRARY.H
// Class library reads off a file and builds a library and patrons in it.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Library class: contains all the books, items, and Patrons.
//               -- able to add and remove items/patrons from the library.
//               -- able to build the library and patrons while reading the
//                  file.
//
// Assumptions/implementation:
//      -- data files to read exist
//      -- data files are formatted correctly
//---------------------------------------------------------------------------
#ifndef _LIBRARY_H
#define _LIBRARY_H

#include <iostream>
#include <fstream>
#include "actionFactory.h"
#include "itemFactory.h"
#include "bintree.h"
#include "hashtable.h"
//#include "patronAction.h"

// Only for class code, OK to use namespace
using namespace std;

const int MAX_GENRES = 26;
//class PatronAction;

//---------------------------------------------------------------------------
// Library class represents the collection of all the books, items, Patrons
class Library {
public:
  // Constructor - creates library
  Library();

  // Destructor - deallocates library
  virtual ~Library();

  // Adds item to the library database
  //bool addItem(Item&);

  // Removes item from library database
  bool removeItem(Item&);

  // Finds the item in library database
  //Item* findItem(Item&) const;

  // Adds a patron to library
  //bool addPatron(Patron);

  // Removes a patron from library
  //bool removePatron(Patron);

  Item* inLibrary(char, Item*&) const;

  // Mass build of library items using datafile
  void buildLibrary(ifstream&);

  // Mass build library patrons using datafile
  void buildPatrons(ifstream&);

  // Performs patron actions
  void performCommands(ifstream&);

  void display() const;

  //getters
  Patron* getPatron(int) const;


private:
  BinTree itemTypes[MAX_GENRES];
  HashTable libraryPatrons; // stores all the library patrons
  ActionFactory patronActionFactory;  // factory to create patron actions
  ItemFactory libraryItemFactory;   // factory to create library items
  char itemType;
  char actionType;
};

#endif