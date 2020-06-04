//
// CustomerHistory.h
// Member function definitions for class CustomerHistory
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// CustomerHistory class: Represents customer transaction history display.
//          It is a child class of Transaction. Has private custID
//
//   This program allows:
//      - Allows the creation of a CustomerHistory
//      - Allows the copy of a CustomerHistory
//      - Allows execution of a CustomerHistory
//      - Allows to get customer ID associated with account
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------


#ifndef CUSTOMERHISTORY_H
#define CUSTOMERHISTORY_H

#include <string>
#include <iostream>
#include <fstream>

#include "Transaction.h"
#include "Collectible.h"

using namespace std;


class CustomerHistory : public Transaction {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default CustomerHistory transaction
    // Preconditions:  none
    // Postconditions: CustomerHistory transaction is constructed with default values.
    CustomerHistory();


    //-------------------------- Constructor -----------------------------
    // Creates a CustomerHistoryTransaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    CustomerHistory(char type, int custID);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~CustomerHistory();


    //-----------------------------  run  ---------------------------------
    // Runs CustomerHistory function
    // Preconditions: none
    // Postconditions: CustomerHistory execution is ran
    virtual void run(Store* store) const;


    //----------------------------- create ---------------------------------
    // Creates a CustomerHistory object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new CustomerHistory object constructed with input values.
    virtual CustomerHistory* create(ifstream& infile) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of CustomerHistory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the CustomerHistory Object
    virtual CustomerHistory* clone() const;


    //----------------------------  getCustID -------------------------------------
    // Returns cutomer id for sell transaction
    // Preconditions: int is not empty
    // Postconditions: Value of int custID is returned
    int getCustID() const;



private:
    //stores customer ID associated with the transaction
    int custID;
};

#endif //HW4_CUSTOMERHISTORY_H
