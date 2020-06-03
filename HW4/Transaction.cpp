//
// Transaction.h
// Member function definitions for class Transaction
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Transaction class: Represents a transaction. It is a parent class.
//      It has a char type and an Inventory pointer.
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
#include "Transaction.h"

using namespace std;

Transaction::Transaction() : Inventory(){
    this->transactionType = 0;
}

//-------------------------- Constructor -----------------------------
// Creates a Transaction with char input
// Preconditions: char type is valid
// Postconditions: This type is initialized with input value
Transaction::Transaction(char type) : Inventory(){
    this->transactionType = type;
}



void Transaction::display(ostream &output) const {
    output << this->transactionType;
}


bool Transaction::operator>(const Inventory &other) const{
    //cast to transcation
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return this->transactionType > trans.transactionType;
}

bool Transaction::operator==(const Inventory &other) const{
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return this->transactionType == trans.transactionType &&
            *this->item == *trans.item;
}

bool Transaction::operator!=(const Inventory &other) const {
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return !(*this == trans);
}


Inventory* Transaction::getItem() const {
    return this->item;
}

char Transaction::getType() const {
    return this->transactionType;
}



