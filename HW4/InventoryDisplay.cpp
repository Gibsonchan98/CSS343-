//
// InventoryDisplay.h
// Member function definitions for class InventoryDisplay
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// InventoryDisplay class: Represents inventory display transaction.
//          It is a child class of Transaction.
//
//   This program allows:
//      - Allows the creation of InventoryDisplay
//      - Allows the copy of  InventoryDisplay
//      - Allows execution of  InventoryDisplay
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------

#include "InventoryDisplay.h"
#include "Store.h"

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default InventoryDisplay
// Preconditions:  none
// Postconditions: InventoryDisplay is constructed with default values.
InventoryDisplay::InventoryDisplay() : Transaction(){}

//-------------------------- Constructor -----------------------------
// Creates a InventoryDisplay with char input
// Preconditions: char type is valid
// Postconditions: This type is initialized with input value
InventoryDisplay::InventoryDisplay(char type) : Transaction(type){}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
InventoryDisplay::~InventoryDisplay()= default;

//-----------------------------  run  ---------------------------------
// Runs inventoryDisplay function
// Preconditions: none
// Postconditions: inventoryDisplay execution is ran
void InventoryDisplay::run(Store* store) const{
    store->display();
}

//----------------------------- create ---------------------------------
// Creates a InventoryDisplay object using file input
// Preconditions:  Input is in correct format and valid
// Postconditions: returns new InventoryDisplay object constructed with input values.
InventoryDisplay* InventoryDisplay::create(ifstream& infile) const{
    char type;
    infile >> type;
    infile.ignore(INT_MAX, '\n');
    return new InventoryDisplay(type);
}

InventoryDisplay *InventoryDisplay::clone() const {
    return new InventoryDisplay(getType());
}
