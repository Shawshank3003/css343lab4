//---------------------------------------------------------------------------
// ACTION_FACTORY.CPP
// Class ActionFactory creates different types of patron actions
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "actionFactory.h"
#include "patronAction.h"

//---------------------------------------------------------------------------
// Constructor
// Creates an action factory
ActionFactory::ActionFactory() {
    for (int i = 0; i < MAX_COMMAND_TYPES; i++) {
        actionTemplates[i] = nullptr;
    }

    actionTemplates[2] = new Checkout();
    actionTemplates[3] = new DisplayLibrary();
    actionTemplates[7] = new DisplayHistory();
    actionTemplates[17] = new Return();
}

//---------------------------------------------------------------------------
// Destructor
// Deallocates the action factory
ActionFactory::~ActionFactory() {
    for (int i = 0; i < MAX_COMMAND_TYPES; i++) {
        if (actionTemplates[i] != nullptr) {
            delete actionTemplates[i];
            actionTemplates[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// createIt
// Creates an action object based on the command type
// returns the PatronAction array with the action character added into it
PatronAction* ActionFactory::createIt(char ch, istream& infile) const{
    int index = hash(ch);
    if (actionTemplates[index] == nullptr) {
        string valid;
        getline(infile, valid, '\n');
        return nullptr;
    }
    return actionTemplates[index]->create();
}

//---------------------------------------------------------------------------
// hash
// function returns an int that corresponds to the char from the parameter's
// index
int ActionFactory::hash(char ch) const {
    return ch - 'A';
}