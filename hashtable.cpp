//---------------------------------------------------------------------------
// HASHTABLE.CPP
// Class HashTable represents the storage of Patrons
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "patron.h"
#include "hashtable.h"

//---------------------------------------------------------------------------
// Constructor
// initializes size as 0. intializes the array of pointers to nullptr
HashTable::HashTable() {
    size = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        table[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// Destructor
// deletes all the patrons in the hashtable
HashTable::~HashTable() {
    clear();
}

//---------------------------------------------------------------------------
// clear
// deletes all the patrons in the hashtable
void HashTable::clear() {
    for (int i = 0; i < MAX_SIZE; i++) {
        delete table[i];
    }
}

//---------------------------------------------------------------------------
// add
// adds a patron to the hashtable
bool HashTable::add(Patron* patron) {
    if (size == MAX_SIZE || patron->getPatronId() < MIN_ID 
        || patron->getPatronId() > MAX_ID) {
        return false;
    }
    //If the patron ID is already available
    if (table[hash(patron->getPatronId())] != nullptr) {
        cout << "Patron already exists" << endl;
        delete patron;
        patron = nullptr;
        return false;
    }
    table[hash(patron->getPatronId())] = patron;
    size++;
    return true;
}

//---------------------------------------------------------------------------
// hash
// returns the hash value of the patron id
int HashTable::hash(int patronId) const{
    return patronId;
}

Patron* HashTable::get(int patronId) const {
    if (patronId < MIN_ID || patronId > MAX_ID) {
        return nullptr;
    }
    return table[hash(patronId)];
}



