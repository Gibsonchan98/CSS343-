//
// Transaction.h
// Member function definitions for class Transaction
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Transaction class: Represents a transaction. It is a parent class.
//      It has a char type.
//
//   This program allows:
//  	- Allows the display of a Transaction
//      - Allows the creation of a Transaction
//      - Allows the copy of a Transaction
//      - Allows execution of a Transaction
//      - Allows getting Transaction type
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------


#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include <iostream>
#include <fstream>
#include <climits>

#include "Inventory.h"

using namespace std;

class Store;

class Transaction : public Inventory {


public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default transaction
    // Preconditions:  none
    // Postconditions: Transaction is constructed with default values.
    Transaction();


    //-------------------------- Constructor -----------------------------
    // Creates a Transaction with char input
    // Preconditions: char type is valid
    // Postconditions: This type is initialized with input value
    explicit Transaction(char type);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~Transaction();

    //----------------------------- create ---------------------------------
    // Creates a Transaction object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Transaction object constructed with input values.
    virtual Transaction* create(ifstream& infile) const = 0;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Transaction object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Transaction Object
    virtual Transaction* clone() const = 0;

    //-----------------------------  run  ---------------------------------
    // Runs transaction function
    // Preconditions: none
    // Postconditions: Transaction execution is ran. Returns true if successful
    virtual void run(Store* store) const = 0;

    //---------------------------------Display --------------------------------------
    // Displays Transaction info
    // Preconditions:  none
    // Postconditions: Transaction type is displayed
    void display(ostream &output) const;

    //************************ Operators *****************************************

    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two Transaction objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're equal
    virtual bool operator==(const Inventory& other) const;

    //-------------------------------- != ---------------------------------------
    // Unequal operator overload. Compares two Transaction objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const;


    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares if this Transaction is greater
    // than the other.
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const;

    //*****************************************************************************

    //---------------------  getType ---------------------------------
    // Returns Transaction's type
    // Preconditions: none
    // Postconditions: Value of char type is returned
    char getType() const;

private:

    //private char to store type
    char transactionType;

};


#endif //TRANSACTION_H
