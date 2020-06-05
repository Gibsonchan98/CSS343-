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

#include "TransactionItem.h"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default sell transaction
// Preconditions:  none
// Postconditions: Sell transaction is constructed with default values.
TransactionItem::TransactionItem() : Transaction(){
    this->item = nullptr;
    this->custID = 0;
}

//-------------------------- Constructor -----------------------------
// Creates a Sell Transaction with input
// Preconditions: Input is valid
// Postconditions: This attributes are initialized with input values
TransactionItem::TransactionItem(char type, Collectible* item, int ID)
    : Transaction(type){
    this->item = item;
    this->custID = ID;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
TransactionItem::~TransactionItem(){
    delete this->item;
    this->item = nullptr;
}

//---------------------------------Display --------------------------------------
// Displays  TransactionItem transaction info
// Preconditions:  none
// Postconditions:  TransactionItem transaction type is displayed
void TransactionItem::display(ostream& output) const{
    //to display type of transaction
    Transaction::display(output);
    //display Collectible
    if(this->item != nullptr){
        output << *item;
    }
    else{
        output << "Nothing";
    }
}


//----------------------------  getCustID -------------------------------------
// Returns cutomer id for buy transaction
// Preconditions: int is not empty
// Postconditions: Value of int custID is returned
int TransactionItem::getCustID() const{
    return this->custID;
}


//----------------------------  getItem -------------------------------------
// Returns pointer to item
// Preconditions: Item is not null
// Postconditions: Pointer to Collectible item is returned
Collectible* TransactionItem::getItem() const {
    return this->item;
}


//----------------------------- setItem  ---------------------------------
// Sets item to parameter pointer
// Preconditions: None
// Postconditions: Item ptr is set to parameter pointer
void TransactionItem::setItem(Collectible* item){
    this->item = item;
}