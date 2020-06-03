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

#ifndef INVENTORYDISPLAY_H
#define INVENTORYDISPLAY_H

#include <string>
#include <iostream>
#include <fstream>

#include "Transaction.h"

using namespace std;

class InventoryDisplay : public Transaction{

public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default InventoryDisplay
    // Preconditions:  none
    // Postconditions: InventoryDisplay is constructed with default values.
    InventoryDisplay();


    //-------------------------- Constructor -----------------------------
    // Creates a InventoryDisplay with char input
    // Preconditions: char type is valid
    // Postconditions: This type is initialized with input value
    explicit InventoryDisplay(char type);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~InventoryDisplay();

    //-----------------------------  run  ---------------------------------
    // Runs inventoryDisplay function
    // Preconditions: none
    // Postconditions: inventoryDisplay execution is ran
    virtual void run(Store* store) const;


    //----------------------------- create ---------------------------------
    // Creates a InventoryDisplay object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new InventoryDisplay object constructed with input values.
    virtual InventoryDisplay* create(ifstream& infile) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of InventoryDisplay object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the InventoryDisplay Object
    virtual InventoryDisplay* clone() const;
};


#endif //INVENTORYDISPLAY_H
