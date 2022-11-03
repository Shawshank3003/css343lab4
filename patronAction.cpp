//---------------------------------------------------------------------------
// _PATRON_ACTION.CPP
// Class PatronAction is a support class of Patron.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "patronAction.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
// Initializes associatedItem, associatedPatron, and action
PatronAction::PatronAction() {
    associatedItem = nullptr;
    associatedPatron = nullptr;
    action = "";
}

//---------------------------------------------------------------------------
// Destructor
// Nothing to do
PatronAction::~PatronAction() { }

//---------------------------------------------------------------------------
// getAssociatedPatron
// Returns the patron associated with this action
Patron* PatronAction::getAssociatedPatron() const{
    return associatedPatron;
}

//---------------------------------------------------------------------------
// getAssociatedItem
// Returns the item associated with this action
Item* PatronAction::getAssociatedItem() const{
    return associatedItem;
}

//-----------------------------------------------------------------------------
// getAction
// Returns string action
string PatronAction::getAction() const {
    return action;
}
