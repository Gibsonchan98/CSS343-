//
// Sell.h
// Member function definitions for class Sell
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// Sell class: Represents sell transaction. It is a child class of Transaction
//      It has a custID to save ID related with the transaction.
//
//   This program allows:
//  	- Allows the display of a Sell item
//      - Allows the creation of a Sell
//      - Allows the copy of a Sell
//      - Allows execution of a Sell
//      - Allows getting ID
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------

#ifndef SELL_H
#define SELL_H

#include <string>
#include <iostream>
#include <fstream>

#include "Transaction.h"
#include "Collectible.h"

class Customer;

class Sell: public Transaction {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default sell transaction
    // Preconditions:  none
    // Postconditions: Sell transaction is constructed with default values.
    Sell();

    
    //-------------------------- Constructor -----------------------------
    // Creates a Sell Transaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    Sell(char type,  Inventory* item, int custID);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~Sell();

    //---------------------------------Display --------------------------------------
    // Displays Sell transaction info
    // Preconditions:  none
    // Postconditions: Sell transaction type is displayed
    virtual void display(ostream& output) const;

    //-----------------------------  run  ---------------------------------
    // Runs selling function
    // Preconditions: Item has enough amount in stock
    // Postconditions: Selling execution is ran
    virtual void run(Store* store) const;


    //----------------------------- create ---------------------------------
    // Creates a Sell object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Sell object constructed with input values.
    virtual Sell* create(ifstream& infile) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Buy object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Buy Object
    virtual Sell* clone() const;

    //----------------------------  getCustID -------------------------------------
    // Returns cutomer id for sell transaction
    // Preconditions: int is not empty
    // Postconditions: Value of int custID is returned
    int getCustID() const;

    //----------------------------  getItem -------------------------------------
    // Returns pointer to item
    // Preconditions: Item is not null
    // Postconditions: Pointer to Inventory item is returned
    Inventory* getItem() const;

private:
    //ID of customer for this transaction
    int custID;

    //Pointer to an Inventory item
    Inventory* item;
};


#endif //HW4_SELL_H
