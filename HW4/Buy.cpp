//
// Buy.h
// Member function definitions for class Buy
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// Buy class: Represents Buy transaction. It is a child class of Transaction
//      It has a custID to save ID related with the transaction.
//
//   This program allows:
//  	- Allows the display of a Buy item
//      - Allows the creation of a Buy
//      - Allows the copy of a Buy
//      - Allows execution of a Buy
//      - Allows getting custID
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------

#include "Buy.h"
#include "Store.h"

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default Buy transaction
// Preconditions:  none
// Postconditions:Buy transaction is constructed with default values.
Buy::Buy() : Transaction(){
    this->custID = 0;
    this->item = nullptr;
}

//-------------------------- Constructor -----------------------------
// Creates a Buy Transaction with input
// Preconditions: Input is valid
// Postconditions: This attributes are initialized with input values
Buy::Buy(char type,  Inventory* item, int custID) : Transaction(type){
    this->custID = custID;
    this->item = item; //copy pointer
    //*this->item = *item; //copy item
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
Buy::~Buy(){
    delete this->item;
}

//---------------------------------Display --------------------------------------
// Displays Buy transaction info
// Preconditions:  none
// Postconditions: Buy transaction type is displayed
void Buy::display(ostream& output) const{
    output << "Transaction: ";
    Transaction::display(output);
    if(this->item != nullptr){
        output << *item;
    }

}

//-----------------------------  run  ---------------------------------
// Runs Buying function
// Preconditions: There's enough space for more items
// Postconditions: Buying execution is ran
void Buy::run(Store* store) const{
    store->buy();
}


//----------------------------- create ---------------------------------
// Creates a Buy object using file input
// Preconditions:  Input is in correct format and valid
// Postconditions: returns new Buy object constructed with input values.
Buy* Buy::create(ifstream& infile) const{
    char transtype;
    int id;
    infile >> transtype;
    infile.ignore();
    infile >> id;
    infile.ignore();
    infile.ignore();
    return new Buy(transtype,nullptr,id);
}


//--------------------------- clone --------------------------------------
// Creates a clone of Buy object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the Buy Object
Buy* Buy::clone() const{
    //char type,  Inventory* item, int custID
    if(this->item == nullptr){
        return new Buy(getType(), nullptr,getCustID());
    }

    return new Buy(getType(),getItem(),getCustID());
}

//----------------------------  getCustID -------------------------------------
// Returns cutomer id for buy transaction
// Preconditions: int is not empty
// Postconditions: Value of int custID is returned
int Buy::getCustID() const{
    return this->custID;
}


//----------------------------  getItem -------------------------------------
// Returns pointer to item
// Preconditions: Item is not null
// Postconditions: Pointer to Inventory item is returned
Inventory* Buy::getItem() const {
    return this->item;
}
