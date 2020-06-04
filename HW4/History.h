//
// History.h
// Member function definitions for class History
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
//  Historyclass: Represents store transaction history display.
//          It is a child class of Transaction.
//
//   This program allows:
//      - Allows the creation of a History
//      - Allows the copy of a History
//      - Allows execution of a History
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------

#ifndef HISTORY_H
#define HISTORY_H

#include <string>
#include <iostream>
#include <fstream>

#include "Transaction.h"

using namespace std;


class History : public Transaction{

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default History
    // Preconditions:  none
    // Postconditions: History is constructed with default values.
    History();

    //-------------------------- Constructor -----------------------------
    // Creates a History with char input
    // Preconditions: char type is valid
    // Postconditions: This type is initialized with input value
    History(char type);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~History();

    //-----------------------------  run  ---------------------------------
    // Runs History function
    // Preconditions: None
    // Postconditions: History execution is ran
    virtual void run(Store* store) const;

    //----------------------------- create ---------------------------------
    // Creates a History object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new History object constructed with input values.
    virtual History* create(ifstream& infile) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of History object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the History Object
    virtual History* clone() const;

};


#endif //HW4_HISTORY_H
