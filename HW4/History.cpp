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
#include "History.h"
#include "Store.h"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default History
// Preconditions:  none
// Postconditions: History is constructed with default values.
History::History() : Transaction(){}

//-------------------------- Constructor -----------------------------
// Creates a History with char input
// Preconditions: char type is valid
// Postconditions: This type is initialized with input value
History::History(char type) : Transaction(type){}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
History::~History(){}

//-----------------------------  run  ---------------------------------
// Runs History function
// Preconditions: None
// Postconditions: History execution is ran
void History::run(Store *store) const {
    store->allHistory();
}

//----------------------------- create ---------------------------------
// Creates a History object using file input
// Preconditions:  Input is in correct format and valid
// Postconditions: returns new History object constructed with input values.
History* History::create(ifstream &infile) const {
    char type;
    infile >> type;
    //ignores all characters until new line
    infile.ignore(INT_MAX, '\n');
    //return pointer to History object
    return new History(type);
}

//--------------------------- clone --------------------------------------
// Creates a clone of History object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the History Object
History *History::clone() const {
    return new History(getType());
}



