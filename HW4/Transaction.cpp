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

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default transaction
// Preconditions:  none
// Postconditions: Transaction is constructed with default values.
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

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
Transaction::~Transaction(){}

//---------------------------------Display --------------------------------------
// Displays Transaction info
// Preconditions:  none
// Postconditions: Transaction type is displayed
void Transaction::display(ostream &output) const {
    output << this->transactionType;
}

//************************ Operators *****************************************

//-------------------------------- == -------------------------------------
// Equal operator overload. Compares two Transaction objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're equal
bool Transaction::operator==(const Inventory &other) const{
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return this->transactionType == trans.transactionType;
}

//-------------------------------- != -------------------------------------
// Unequal operator overload. Compares two Transaction objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're not equal
bool Transaction::operator!=(const Inventory &other) const {
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return !(*this == trans);
}

//-------------------------------- > ---------------------------------------
// Greater than operator overload. Compares if this Transaction is greater
// than the other.
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if this is greater than the other
bool Transaction::operator>(const Inventory &other) const{
    //cast to transcation
    const Transaction& trans = dynamic_cast<const Transaction&>(other);

    return this->transactionType > trans.transactionType;
}

//*****************************************************************************

//---------------------  getType ---------------------------------
// Returns Transaction's type
// Preconditions: none
// Postconditions: Value of char type is returned
char Transaction::getType() const {
    return this->transactionType;
}



