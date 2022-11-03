//---------------------------------------------------------------------------
// NODEDATA.H
// Class nodedata is the super class that mimics Object (it is all
// encompassing).
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// NodeData class: Contains all the pure virtual functions needed.
//
// Assumptions/implementation:
//      -- Implements an empty default constructor, destructor, and prints
//      out an empty string.
//---------------------------------------------------------------------------
#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   NodeData();          // default constructor, data is set to an empty string
   virtual ~NodeData();          
   
   // set class data from data file
   // returns true if the data is set, false when bad data, i.e., is eof
   virtual void setData(ifstream&) = 0;                

   // Returns true if this and the parameter is the same and false if not
   virtual bool operator==(const NodeData &) const = 0;
   // Returns true if this is smaller than the parameter and false is not
   virtual bool operator<(const NodeData &) const = 0;

   virtual void display() const = 0;

   virtual void displayData() const = 0;

   virtual void displayHeader() const = 0;
   
private:
  // operator<< helper
  //virtual void displayHelper(ostream &) const = 0;    
};

#endif
