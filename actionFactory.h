//---------------------------------------------------------------------------
// ACTION_FACTORY.H
// Class ActionFactory creates different types of patron actions
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// ActionFactory class:
//      -- Follows the Factory design pattern
//      -- Factory design pattern is used for creating families of related
//            or dependent objects without specifying their concrete classes
//      -- Creates the desired patron action
// Assumptions:
//      -- The commands text is correctly formatted
//---------------------------------------------------------------------------

#ifndef _ACTION_FACTORY_H
#define _ACTION_FACTORY_H


#include "checkout.h"
#include "displayHistory.h"
#include "displayLibrary.h"
#include "return.h"

class PatronAction;

const int MAX_COMMAND_TYPES = 26;

using namespace std;
// Action Factory class is factory for creating different types of patron 
//    actions
class ActionFactory {
public:
  // Constructor - creates an action factory
  ActionFactory();

  // Destructor - deallocates the action factory
  virtual ~ActionFactory();

  // Creates a specific type of action based on the given char
  PatronAction* createIt(char, istream &) const;
  
private:
  PatronAction* actionTemplates[MAX_COMMAND_TYPES]; // array of template
                                                // actions that can be performed
  
  // hashing function to identify the key of the action that needs to be 
  //    created
  int hash(char) const;
};


#endif
