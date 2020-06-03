//
// Factory.h
// Member function definitions for class Factory
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Factory class: It takes an Inventroy input and creates a new instance
//    based on the type that is inputed. It looks for the type in the hashtable
//    to see if it exists.
//
//   This program allows:
//      - Allows getting a new instance type of Object to the Factory
//      - Allows reading a file to identify type of Object
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------
#ifndef HW4_FACTORY_H
#define HW4_FACTORY_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

#include "Hashtable.h"
#include "Inventory.h"

class Factory {
public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a defaIult Factory
    // Preconditions:  None
    // Postconditions: Factory is constructed with default values.
    Factory();

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~Factory();


    //--------------------------- create ----------------------------
    // Creates an derived object of Inventory
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns pointer to derived Inventory object.
    virtual Inventory* create(ifstream &input) const;
    /*
     * Inventory* temp; char type;
     * type = get type from file
     * if(it is a valid type){
     *     temp = hashtable->get(type)
     *     if(it is's in table){
     *          return new instance
     *      }
     *  }
     *  else {
     *      return nullptr;
     *  }
     *
     *
     * */



    //--------------------------- add ----------------------------
    // Adds object to the hashtable
    // Preconditions:  input in not null
    // Postconditions: The item is added
    virtual void insert(char key, Inventory* value);


private:
    //HashTable to store objects
    HashTable* map;

    //List of inventory
    vector<Inventory*> *list;

};


#endif //HW4_FACTORY_H
