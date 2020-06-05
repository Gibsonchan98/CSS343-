// Sell.h
// Member function definitions for class Sell
// Created by Melanie Palomino on 5/20/20.
//---------------------------------------------------------------------------
// Sell class: Represents sell transaction. It is a child class of Transaction
//      It has a custID to save ID related with the transaction.
//
//   This program allows:
//  	- Allows the display of a Sell item
//      - Allows the creation of a Sell
//      - Allows the copy of a Sell
//      - Allows execution of a Sell
//      - Allows getting ID
//  Assumptions:
//  	- The input file has correct formatting and info
//---------------------------------------------------------------------------

#include "Sell.h"
#include "Store.h"

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default sell transaction
// Preconditions:  none
// Postconditions: Sell transaction is constructed with default values.
Sell::Sell() : TransactionItem() {}


//-------------------------- Constructor -----------------------------
// Creates a Sell Transaction with input
// Preconditions: Input is valid
// Postconditions: This attributes are initialized with input values
Sell::Sell(char type, Collectible* item, int custID)
        : TransactionItem(type,item,custID){}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
Sell::~Sell() = default;

//---------------------------------Display --------------------------------------
// Displays Sell transaction info
// Preconditions:  none
// Postconditions: Sell transaction type is displayed
void Sell::display(ostream& output) const{
    output << "Sell(";
    TransactionItem::display(output);
}

//-----------------------------  run  ---------------------------------
// Runs selling function
// Preconditions: Item has enough amount in stock
// Postconditions: Selling execution is ran
void Sell::run(Store* store) const{
    store->sell();
}


//----------------------------- create ---------------------------------
// Creates a Sell object using file input
// Preconditions:  Input is in correct format and valid
// Postconditions: returns new Sell object constructed with input values.
Sell* Sell::create(ifstream& infile) const{
    char transtype;
    int id;
    infile >> transtype;
    infile.ignore();
    infile >> id;
    infile.ignore();
    infile.ignore();
    return new Sell(transtype,nullptr,id);
}

//--------------------------- clone --------------------------------------
// Creates a clone of Buy object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the Buy Object
Sell* Sell::clone() const{
    //char type,  Inventory* item, int custID
    if(this->getItem() == nullptr){
        return new Sell(getType(), nullptr,getCustID());
    }

    return new Sell(getType(),getItem()->clone(),getCustID());
}

