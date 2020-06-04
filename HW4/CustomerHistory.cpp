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
#include "CustomerHistory.h"
#include "Store.h"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default CustomerHistory transaction
// Preconditions:  none
// Postconditions: CustomerHistory transaction is constructed with default values
CustomerHistory::CustomerHistory() : Transaction(){
    this->custID = 0;
}

//-------------------------- Constructor -----------------------------
// Creates a CustomerHistoryTransaction with input
// Preconditions: Input is valid
// Postconditions: This attributes are initialized with input values
CustomerHistory::CustomerHistory(char type, int custID) : Transaction(type){
    this->custID = custID;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
CustomerHistory::~CustomerHistory(){}

//----------------------------- create ---------------------------------
// Creates a CustomerHistory object using file input
// Preconditions:  Input is in correct format and valid
// Postconditions: returns new CustomerHistory object constructed with input values.
CustomerHistory* CustomerHistory::create(ifstream &infile) const {
    char type;
    int ID;
    infile >> type;
    infile.ignore();
    infile >> ID;
    return new CustomerHistory(type,ID);
}

//--------------------------- clone --------------------------------------
// Creates a clone of CustomerHistory object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the CustomerHistory Object
CustomerHistory* CustomerHistory::clone() const {
    return new CustomerHistory(getType(),getCustID());
}

//-----------------------------  run  ---------------------------------
// Runs CustomerHistory function
// Preconditions: none
// Postconditions: CustomerHistory execution is ran
void CustomerHistory::run(Store *store) const {
    store->customerHistory(this->custID);
}

//----------------------------  getCustID -------------------------------------
// Returns customer id for sell transaction
// Preconditions: int is not empty
// Postconditions: Value of int custID is returned
int CustomerHistory::getCustID() const {
    return this->custID;
}







