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

History::History() : Transaction(){
}

History::History(char type) : Transaction(type){}


History::~History(){}


void History::run(Store *store) const {
    store->allHistory();
}


History* History::create(ifstream &infile) const {
    char type;
    infile >> type;
    infile.ignore(INT_MAX, '\n');
    return new History(type);
}

//--------------------------- clone --------------------------------------
// Creates a clone of History object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the History Object
History *History::clone() const {
    return new History(getType());
}



