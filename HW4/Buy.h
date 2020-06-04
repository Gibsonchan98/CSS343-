//
// Buy.h
// Member function definitions for class Buy
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// Buy class: Represents Buy transaction. It is a child class of Transaction
//      It has a custID to save ID related with the transaction and
//      an Inventory pointer.
//
//   This program allows:
//  	- Allows the display of a Buy item
//      - Allows the creation of a Buy
//      - Allows the copy of a Buy
//      - Allows execution of a Buy
//      - Allows getting custID
//      - Allows getting an item pointer
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------


#ifndef BUY_H
#define BUY_H

#include "TransactionItem.h"

class Buy : public TransactionItem {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Buy transaction
    // Preconditions:  none
    // Postconditions:Buy transaction is constructed with default values.
    Buy();


    //-------------------------- Constructor -----------------------------
    // Creates a Buy Transaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    Buy(char type, Collectible* item, int custID);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~Buy();

    //---------------------------------Display --------------------------------------
    // Displays Buy transaction info
    // Preconditions:  none
    // Postconditions: Buy transaction type is displayed
    virtual void display(ostream& output) const;

    //-----------------------------  run  ---------------------------------
    // Runs Buying function
    // Preconditions: There's enough space for more items
    // Postconditions: Buying execution is ran
    virtual void run(Store* store) const;


    //----------------------------- create ---------------------------------
    // Creates a Buy object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Buy object constructed with input values.
    virtual Buy* create(ifstream& infile) const;


    //--------------------------- clone --------------------------------------
    // Creates a clone of Buy object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Buy Object
    virtual Buy* clone() const;



};


#endif //HW4_BUY_H
