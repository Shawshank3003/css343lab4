//---------------------------------------------------------------------------
// BOOK.H
// Class Book represents a book
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// Book class: 
//      -- Represents a book in the library
//      -- Derived from Item
// Assumptions:
//      -- The format in the texts are correct
//---------------------------------------------------------------------------
#ifndef _BOOK_H
#define _BOOK_H

#include <iostream>
#include <fstream>
#include <string>
#include "item.h"


// Only for class code, OK to use namespace
using namespace std;

//---------------------------------------------------------------------------
//Book class represents a book object
class Book : public Item {

public:
  // Constructor - creates a book
  Book();

  // Destructor - deallocates the book
  virtual ~Book() = 0;

  // returns the number of copies of the book that are currently 
  //    checked out
  int getYear() const; 

  string getBookTitle() const;

  string getBookFormat() const;

  // creates an Item that is a Book
  virtual Item* create() const = 0;

  // Sets the data for the member variables
  virtual void setData(ifstream&) = 0;

  virtual void setCommandData(ifstream&) = 0;

  virtual void display() const = 0;
  
  virtual void displayData() const = 0;

  virtual void displayHeader() const = 0;

  // == operator - returns if two books are equal
  virtual bool operator==(const NodeData &) const = 0;

  // < operator - returns true if current book is less than given book
  virtual bool operator<(const NodeData &) const = 0;

protected:
  static const int MAX_TITLE_LENGTH = 26;
  static const int MAX_AUTHOR_LENGTH = 26;

  int year; // the year of publication of the book
  string bookTitle; // the title of the book
  string bookFormat; // the format --> 'H' = hardcover
  string genre;
};

#endif