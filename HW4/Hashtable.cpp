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

HashTable::HashTable() {
    arrayHash = new Inventory*[SIZE + 1];
    this->size = SIZE + 1;
    for(int i = 0; i <= this->size; i++){
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



void HashTable::insert(char key, Inventory *value) {

    int index = hash(key);

    if(index > this->size){
        resize(index);
    }

    arrayHash[index] = value;

}


void HashTable::resize(int size) {
    int tempSize;
    Inventory **tempArray = new Inventory*[size + 1]();
    for(int i = 0; i <= size; i++){
        tempArray[i] = nullptr;
    }
    for(int i = 0; i <= this->size; i++){
        tempArray[i] = arrayHash[i];
    }
    //delete data
    delete arrayHash;
    arrayHash = tempArray;

    this->size = size + 1;

    tempArray = nullptr;
}

int HashTable::hash(char key) const {
    return key - 'O';
}

Inventory *HashTable::retrieve(char key) const {
    int index = hash(key);

    if((index < this->size) && (index >= 0)){
        return arrayHash[index];
    }

    return nullptr;
}




