//
// HashTable.h
// Member function definitions for class HashTable
// Created by Melanie Palomino on 5/17/20.
//---------------------------------------------------------------------------
// HashTable class: Represents a hashtable that stores any Inventory Object
//      values with at a key.
//  This program allows:
//   	- Allows creating a HashTable
//  	- Allows adding a value at a specific key.
//	    - Allows getting the value at key.
//  	- Allows making the hashtable empty.
//
//  Assumptions:
// 	- All values store are not nullptrs
//-----------------------------------------------------------------------------
#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <iostream>
#include <vector>

#include "Buy.h" //will find out soon

using namespace std;

class HashTable {

public:

    //-------------------- Default Constructor---------------------------
    //Default Constructor creates a hashtable with a default capacity and
    //  initiates array.
    // Preconditions: None.
    // Postconditions: Hshtable is created with the default
    //		   size and initialized
    HashTable();


    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual~HashTable();



    //--------------------- add --------------------------------
    // Safes value at the key in HashTable
    // Preconditions: Key and value are not empty or nullptr
    // Postconditions: The value was added to this hashtable.
    void insert(char key, Inventory *value);


    //---------------------get------------------------------------
    // Returns pointer Inventory object that is safed at that key
    // Preconditions: Key exists
    // Postconditions: Pointer to value is returned
    Inventory* retrieve(char key) const;

private:

    //size of the array
    int size;

    const static int SIZE = 10;

    //array of stored Inventory objects
    Inventory **arrayHash;

    //--------------------- hash -------------------------------
    //Creates and returns hash code for the input key.
    // Preonditions: None.
    //Postconditions: An int with hash code is returned
    int hash(char key) const;


    //---------------------resize---------------------------------
    // Enlarges array and resafes data
    // Preconditions: size is bigger than this->size.
    // Postconditions: arrayHash has been increased to size and has
    //      all data safed again
    void resize (int size);

    //--------------------- clear --------------------------------
    // Empties values of HashTable
    // Preconditions: none
    // Postconditions: HashTable is cleared
    void clear(char key, Inventory *value);

};

#endif //_HASHTABLE