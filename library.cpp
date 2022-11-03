//---------------------------------------------------------------------------
// LIBRARY.H
// Class library reads off a file and builds a library and patrons in it.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "library.h"

//------------------------------------------------------------------------------
// Constructor
Library::Library()
{

}


//------------------------------------------------------------------------------
// Destructor
Library::~Library()
{
    //dtor
} 

//------------------------------------------------------------------------------
// buildLibrary
// Purpose: Builds the library of items from the input file.
// Description: Parses through the input file, and creates a item object for
// each line using the ItemFactory.createIt() function. Then, uses the setData
// function for that specific item to set the data for each item. Then, adds
// that item to the appropriate BinTree that matches the itemType in the array
// of BinTrees. 
void Library::buildLibrary(ifstream& infile) {
    for (;;) {
        infile >> itemType;

        if (infile.eof()) {
            break;
        }
        Item* itemPtr = libraryItemFactory.createIt(itemType, infile);

        if (itemPtr != nullptr) {
            itemPtr->setData(infile);

            bool success = itemTypes[itemType].insert(itemPtr);
            if (!success) {
                delete itemPtr;
            }
        }
    }
}

//------------------------------------------------------------------------------
// buildPatrons
// Purpose: Builds the patrons collection from the input file.
// Description: Parses through the input file, and creates a patron pointer for
// each line. Then, calls the patron setData function on that pointer to set
// the id and name for each patron. Then, adds that patron to the hashtable
// at an index based on the id.
void Library::buildPatrons(ifstream& infile) {
    for (;;) {
        Patron* patronPtr = new Patron();
        patronPtr->setData(infile);

        if (infile.eof()) {
            delete patronPtr;
            patronPtr = nullptr;
            break;
        }
        bool success = libraryPatrons.add(patronPtr);
    }
}

//------------------------------------------------------------------------------
// performCommands
// Purpose: Performs the commands from the input file.
void Library::performCommands(ifstream& infile) {
    for (;;) {
        infile >> actionType;
        if (infile.eof()) {
            break;
        }

        PatronAction* patronActionPtr = 
                patronActionFactory.createIt(actionType, infile);
        if (patronActionPtr != nullptr) {
            bool success = patronActionPtr->setData(this, infile);
            if (success) {
                bool actionSuccess = patronActionPtr->perform();
                if (!actionSuccess) {
                    delete patronActionPtr;
                }
            } else {
                delete patronActionPtr;
            }
        } else {
            cout << "ERROR: " << '\'' << actionType << '\'' 
            << " is not a valid action" << endl;
        }
    }
}

//------------------------------------------------------------------------------
// display
// prints out each index in itemTypes if they are not empty
void Library::display() const {
    for (int i = 0; i < MAX_GENRES; i++) {
        if (!itemTypes[i].isEmpty()) {
            cout << itemTypes[i];
        }
    }
}

//------------------------------------------------------------------------------
// getPatronTable
// Purpose: Returns the patron table.
Patron* Library::getPatron(int patronId) const {
    return libraryPatrons.get(patronId);
}

//-----------------------------------------------------------------------------
// inLibrary
// Checks to see if the item from the parameters is in the library.
// Returns the Item pointer if there is and nullptr if there isnt.
Item* Library::inLibrary(char itemType, Item*& target) const {
    NodeData* targetData = nullptr;
    bool success = itemTypes[itemType - 'A'].retrieve(*target, targetData);
    
    if (success) {
       return (Item*)targetData;
    }
    return nullptr;
}
