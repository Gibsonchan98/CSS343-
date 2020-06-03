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


#ifndef BUY_H
#define BUY_H


#include "Transaction.h"

class Buy : public Transaction {
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Buy transaction
    // Preconditions:  none
    // Postconditions:Buy transaction is constructed with default values.
    Buy();

    //--------------------------Copy Constructor -----------------------------
    // Creates a Buy transaction based on other Buy transaction
    // Preconditions: other is not null. There's enough space for other
    // Postconditions: Buy transaction is constructed with Other's values.
    Buy(const Buy& other){
        //set all this values to other values
    }

    //-------------------------- Constructor -----------------------------
    // Creates a Buy Transaction with char input
    // Preconditions: input is valid
    // Postconditions: This type is initialized with input value
    Buy(char type){
        // this char = param type
    }

    //-------------------------- Constructor -----------------------------
    // Creates a Buy Transaction with input
    // Preconditions: Input is valid
    // Postconditions: This attributes are initialized with input values
    Buy(char type,  Inventory* item, int custID){
        // this char = param type
        // this item = param item
        // this custID = param custID
    }

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    virtual ~Buy();

    //---------------------------------Display --------------------------------------
    // Displays Buy transaction info
    // Preconditions:  none
    // Postconditions: Buy transaction type is displayed
    virtual void display(ostream output) const{
        /*
         * output << "BUY" ;
         * Transaction : display(output)
         * */
    }

    //-----------------------------  run  ---------------------------------
    // Runs Buying function
    // Preconditions: There's enough space for more items
    // Postconditions: Buying execution is ran
    virtual void run(Store* store) const{
        //run buy function in store manager
    }


    //----------------------------- create ---------------------------------
    // Creates a Buy object using file input
    // Preconditions:  Input is in correct format and valid
    // Postconditions: returns new Buy object constructed with input values.
    virtual Buy* create(ifstream infile){
        /*
         *  create temp data variables
         *  read lines from file
         *  save input to type & custID
         *  return new Buy(temp data variables)
         * */
    }


    //----------------------------  =  -------------------------------------
    // Assignment operator overloaded. Creates Buy based on the other
    // Preconditions: There's enough space for a copy
    // Postconditions: Returns Buy object that is constructed
    //          with Other's values.
    virtual Buy* operator=(const Inventory& other){
        /*
         * const Buy& temp = dynamic cast (Buy)
         *
         * this type = temp's type
         * this custID = temp's id
         *
         * return *this;
         *
         */
    }

    //----------------------------  getCustID -------------------------------------
    // Returns cutomer id for buy transaction
    // Preconditions: int is not empty
    // Postconditions: Value of int custID is returned
    int getCustID() const;

private:
    //ID of customer for this transaction
    int custID;

};


#endif //HW4_BUY_H
