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
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default sell transaction
    // Preconditions:  none
    // Postconditions: Sell transaction is constructed with default values.
    Sell();


    //-------------------------- Constructor -----------------------------
    // Creates a Sell Transaction with char input
    // Preconditions: input is valid
    // Postconditions: This type is initialized with input value
    Sell(char type){
        // this char = param type
    }

    //-------------------------- Constructor -----------------------------
    // Creates a Sell Transaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    Sell(char type,  Inventory* item, int custID){
        // this char = param type
        // this item = param item
        // this custID = param custID
    }

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~Sell();

    //---------------------------------Display --------------------------------------
    // Displays Sell transaction info
    // Preconditions:  none
    // Postconditions: Sell transaction type is displayed
    virtual void display(ostream output) const{
        /*
         * output << "SELL";
         * Transaction : display(output)
         * */
    }

    //-----------------------------  run  ---------------------------------
    // Runs selling function
    // Preconditions: Item has enough amount in stock
    // Postconditions: Selling execution is ran
    virtual void run(Store* store) const{
        //run sell function in store manager
    }


    //----------------------------- create ---------------------------------
    // Creates a Sell object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Sell object constructed with input values.
    virtual Sell* create(ifstream& infile) const{
        /*
         *  create temp data variables
         *  read lines from file
         *  save input to type & custID
         *  return new Sell(temp data variables)
         * */
    }

    //----------------------------  getCustID -------------------------------------
    // Returns cutomer id for sell transaction
    // Preconditions: int is not empty
    // Postconditions: Value of int custID is returned
    int getCustID() const;

private:
    //ID of customer for this transaction
    int custID;
};


#endif //HW4_SELL_H
