//---------------------------------------------------------------------------
// DISPLAY_LIBRARY.CPP
// Class DisplayLibrary displays all the contents of the library
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "displayLibrary.h"
#include "library.h"

//---------------------------------------------------------------------------
// Constructor
// the string action from patronAction is set to DisplayHistory and the
// associatedItem and associatedPatron is initialized
DisplayLibrary::DisplayLibrary() {
    action = "DisplayLibrary";
    associatedItem = nullptr;
    associatedPatron = nullptr;
}

//---------------------------------------------------------------------------
// Destructor
DisplayLibrary::~DisplayLibrary() { }

//---------------------------------------------------------------------------
// create
// Purpose: Creates the display history object
PatronAction* DisplayLibrary::create() const{
    return new DisplayLibrary();
}

//---------------------------------------------------------------------------
// display
// Returns. No data to initialize for this function because the command is
// just D without any following data after it
void DisplayLibrary::display() const {
    return;
}

//---------------------------------------------------------------------------
// setData
// this library is set to the library in the parameters
bool DisplayLibrary::setData(Library *library, ifstream& infile) {
    this->lib = library;
    return true;
}

//---------------------------------------------------------------------------
// perform
// Purpose: Displays the history of a patron
bool DisplayLibrary::perform() {
    lib->display();
    return false;
}