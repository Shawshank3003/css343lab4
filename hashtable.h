//---------------------------------------------------------------------------
// HASHTABLE.H
// Class HashTable represents the storage of Patrons
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// HashTable class:
//      -- Represents the storage of Patrons
// Assumptions and Implementations:
//      -- Add function which adds a patron to the hashtable
//      -- hash function that returns the index of the Patron based on their
//      patron ID passed in the parameter
//      -- get function returns a Patron pointer based on the patron ID
//      passed into the parameter
//---------------------------------------------------------------------------
#ifndef _HASHTABLE_H
#define _HASHTABLE_H

#include <iostream>

const int MAX_SIZE = 10000;
const int MIN_ID = 0000;
const int MAX_ID = 9999;

class Patron;

class HashTable {
    public:
        // Constructor
        HashTable();

        // Destructor
        virtual ~HashTable();

        // Hash function that returns index of array based on patron id 
        // passed in as parameter.
        int hash(int) const;

        // Inserts a patron into the hashtable. returns true if successful.
        bool add(Patron*);  

        // Gets specific patron from the hashtable. Hashes the patron id and 
        // returns a pointer to the patron if found.
        Patron* get(int) const; 

        // clears the hashtable. helper for destructor.
        void clear();

    private:
        Patron* table[MAX_SIZE]; // array of pointers to patrons
        int size; // num of keys present in table 
};
#endif