//---------------------------------------------------------------------------
// ITEM_FACTORY.CPP
// Class ItemFactory
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "itemFactory.h"

//---------------------------------------------------------------------------
// Constructor
// Set the the values in the itemTemplates to the items accordingly
ItemFactory::ItemFactory() {
    for (int i = 0; i < MAX_ITEM_TYPES; i++)
    {
        itemTemplates[i] = nullptr;    
    }

    itemTemplates[2] = new ChildrensBook();
    itemTemplates[5] = new Fiction();
    itemTemplates[15] = new Periodical();
}

//---------------------------------------------------------------------------
// Destructor
// deletes the itemTemplates and sets them to null
ItemFactory::~ItemFactory() {
    for (int i = 0; i < MAX_ITEM_TYPES; i++)
    {
        if (itemTemplates[i] != nullptr)
        {
            delete itemTemplates[i];
            itemTemplates[i] = nullptr;
        }
    }
}

//---------------------------------------------------------------------------
// createIt
// Creates an item based on the item type
Item* ItemFactory::createIt(char ch, istream& infile) const{
    int index = hash(ch);
    if (itemTemplates[index] == nullptr) {
        string valid;
        getline(infile, valid, '\n');
        return nullptr;
    }
    else {
        return itemTemplates[index]->create();
    }
}

//---------------------------------------------------------------------------
// hash
int ItemFactory::hash(char ch) const {
    return ch - 'A';
}