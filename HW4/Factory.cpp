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

#include "Factory.h"
#include <fstream>
#include <vector>

using namespace std;
//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a defaIult Factory
// Preconditions:  None
// Postconditions: Factory is constructed with default values.
Factory::Factory(){

    this->map = new HashTable();

    this->list = new vector <Inventory*>();
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
Factory::~Factory(){

    delete this->map;

    delete this->list;
}

//--------------------------- add ----------------------------
// Adds object to the hashtable
// Preconditions:  input in not null
// Postconditions: The item is added
void Factory::insert(char key, Inventory* value ){

    this->list->push_back(value);

    this->map->insert(key, value);
}


//--------------------------- create ----------------------------
// Creates an derived object of Inventory
// Preconditions:  input is in correct format and valid
// Postconditions: returns pointer to derived Inventory object.
Inventory* Factory::create(ifstream &input) const{
    Inventory* temp;
    //get type from file
    char type = input.peek();

    if(isalpha(type)){
        temp = this->map->retrieve(type);

        if(temp != nullptr){
            return temp->create(input);
        }
    }

    input.ignore(INT_MAX,'\n');
    temp = nullptr;
    return nullptr;

}
