//
// Transaction.h
// Member function definitions for class Transaction
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Transaction class: Represents a transaction that is connected with a
//          customer and has an item, like Buy or Sell. It is a parent class.
//          It has a int id and Collectible item.
//
//   This program allows:
//  	- Allows the display of a TransactionItem
//      - Allows execution of a TransactionItem
//      - Allows getting the item
//      - Allows getting customer ID associated with the transaction
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------
#ifndef TRANSACTIONITEM_H
#define TRANSACTIONITEM_H

#include "Collectible.h"
#include "Transaction.h"



class TransactionItem : public Transaction {
public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default sell transaction
    // Preconditions:  none
    // Postconditions: Sell transaction is constructed with default values.
    TransactionItem();

    //-------------------------- Constructor -----------------------------
    // Creates a Sell Transaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    TransactionItem(char type, Collectible* item, int ID);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~TransactionItem();

    //---------------------------------Display --------------------------------------
    // Displays  TransactionItem transaction info
    // Preconditions:  none
    // Postconditions:  TransactionItem transaction type is displayed
    virtual void display(ostream& output) const;

    //-----------------------------  run  ---------------------------------
    // Runs selling function
    // Preconditions: Item has enough amount in stock
    // Postconditions: Selling execution is ran
    virtual void run(Store* store) const = 0;


    //----------------------------- create ---------------------------------
    // Creates a Sell object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Sell object constructed with input values.
    virtual TransactionItem* create(ifstream& infile) const = 0;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Buy object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Buy Object
    virtual TransactionItem* clone() const = 0;

    //----------------------------  getCustID -------------------------------------
    // Returns cutomer id for buy transaction
    // Preconditions: int is not empty
    // Postconditions: Value of int custID is returned
    int getCustID() const;


    //----------------------------  getItem -------------------------------------
    // Returns pointer to item
    // Preconditions: Item is not null
    // Postconditions: Pointer to Inventory item is returned
    Collectible* getItem() const;


    //----------------------------- setItem  ---------------------------------
    // Sets item to parameter pointer
    // Preconditions: customer exists
    // Postconditions: History execution is ran
    void setItem(Collectible* item);


private:
    //customer ID
    int custID;

    //Collectible item pointer
    Collectible* item;

};


#endif //TRANSACTIONITEM_H
