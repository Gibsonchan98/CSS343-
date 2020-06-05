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

#include "Hashtable.h"

//-------------------- Default Constructor---------------------------
//Default Constructor creates a hashtable with a default capacity and
//  initiates array.
// Preconditions: None.
// Postconditions: Hashtable is created with the default
//		   size and initialized
HashTable::HashTable() {
    arrayHash = new Inventory*[SIZE + 1];
    this->size = SIZE + 1;
    for(int i = 0; i < this->size; i++){
        arrayHash[i] = nullptr;
    }
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
HashTable::~HashTable(){
    delete[] arrayHash;
}

//--------------------- insert --------------------------------
// Saves value at the key in HashTable
// Preconditions: Key and value are not empty or nullptr
// Postconditions: The value was added to this hashtable.
void HashTable::insert(char key, Inventory *value) {
    int index = hash(key);

    while(index > this->size){
        resize(index);
    }

    arrayHash[index] = value;

}

//---------------------resize---------------------------------
// Enlarges array and resafes data
// Preconditions: size is bigger than this->size.
// Postconditions: arrayHash has been increased to size and has
//      all data safed again
void HashTable::resize(int num) {

    Inventory **tempArray = new Inventory*[num * 2]();
    for(int i = 0; i <= num; i++){
        tempArray[i] = nullptr;
    }
    for(int i = 0; i <= this->size; i++){
        tempArray[i] = arrayHash[i];
    }
    //delete data
    delete arrayHash;
    arrayHash = tempArray;
    this->size = num * 2;

}

//--------------------- hash -------------------------------
//Creates and returns hash code for the input key.
// Preonditions: None.
//Postconditions: An int with hash code is returned
int HashTable::hash(char key) const {
    return key % this->size;
}

//---------------------retrieve ---------------------------------
// Returns pointer Inventory object that is safed at that key
// Preconditions: Key exists
// Postconditions: Pointer to value is returned
Inventory *HashTable::retrieve(char key) const {
    int index = hash(key);

    if((index < this->size) && (index >= 0)){
        return arrayHash[index];
    }

    return nullptr;
}




