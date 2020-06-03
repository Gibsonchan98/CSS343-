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

CustomerHistory::CustomerHistory() : Transaction(){
    this->custID = 0;
}

CustomerHistory::CustomerHistory(char type, int custID) : Transaction(type){
    this->custID = custID;
}

CustomerHistory::~CustomerHistory() = default;


CustomerHistory* CustomerHistory::create(ifstream &infile) const {
    char type;
    int ID;
    infile >> type;
    infile.ignore();
    infile >> ID;
    return new CustomerHistory(type,ID);
}

CustomerHistory* CustomerHistory::clone() const {
    return new CustomerHistory(getType(),getCustID());
}

void CustomerHistory::run(Store *store) const {
    store->customerHistory(this->custID);
}

int CustomerHistory::getCustID() const {
    return this->custID;
}






