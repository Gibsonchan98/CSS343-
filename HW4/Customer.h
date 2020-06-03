//
// Customer.h
// Member function definitions for class Customer
// Created by Melanie Palomino on 5/17/20.
//---------------------------------------------------------------------------
// Customer class: Represents a customer. It has a name, id, and history
//     of transactions.
//   This program allows:
//  	- Allows storing transaction history
//      - Allows comparison between two Customers
//      - Allows the display of the customer's transaction history
//      - Allows the copy of a Customer
//      - Allows getting an instance of a Customer
//  Assumptions:
//  	- Input is valid and correct
//---------------------------------------------------------------------------


#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#include "Inventory.h"
#include "Transaction.h"

using namespace std;

class Customer : public Inventory {


    //------------------------------------ << --------------------------------------
    // Overloads << operator
    // Preconditions:  Customer is not empty
    // Postconditions: Customer information and history is displayed
    friend ostream& operator<<(ostream& output, const Customer& customer);

public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default customer
    // Preconditions:  none
    // Postconditions: Customer is constructed with default values.
    Customer();

    //--------------------------- Constructor from File ----------------------------
    // Creates a customer using file input
    // Preconditions:  input is in correct format and valid
    // Postconditions: Customer is constructed with input values.
    Customer(ifstream& infile);


    //--------------------------- Constructor -----------------------------
    // Creates a customer from string name and int ID
    // Preconditions: Name and ID are valid input
    // Postconditions: Customer is constructed with input values.
    Customer(string name, int ID);

    //--------------------------- Constructor -----------------------------
    // Creates a customer from string name, int ID, and vector
    // Preconditions: Name,ID, and vector are valid input
    // Postconditions: Customer is constructed with input values.
    Customer(string name, int ID, vector<Transaction*>* transaction);


    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  transactionHistory vector is not empty
    // Postconditions: All memory is deallocated
    virtual ~Customer();

    //--------------------------- create ----------------------------
    // Creates a customer using file input
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new Customer object constructed with input values.
    virtual Customer* create(ifstream &input) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Invetory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Inventory Object
    virtual Customer* clone() const;

    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two Customer objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're equal
    virtual bool operator==(const Inventory& other) const;

    //-------------------------------- != ---------------------------------------
    // Unequal operator overload. Compares two Customer objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const;

    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares two Customer objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const;


    //---------------------------------Display --------------------------------------
    // Displays Customer info and transaction history
    // Preconditions:  Customer is not empty
    // Postconditions: Customer information and history is displayed
    virtual void display(ostream& output) const;

    //---------------------addTransaction---------------------------------
    // Adds transaction to vetor
    // Preconditions: Transaction is not null
    // Postconditions: Transaction is saved in vector
    void addTransaction(Transaction* transaction);

    //---------------------  getID ---------------------------------
    // Returns ID number
    // Preconditions: none
    // Postconditions: Value of int ID number is returned
    int getID() const;

    //---------------------  getName ---------------------------------
    // Returns Customer's name
    // Preconditions: none
    // Postconditions: Value of string name is returned
    string getName() const;

private:

    //customer id. Must be less than 1000
    int ID;

    //customer name
    string name;

    //vector with the Customer's transaction history
    vector<Transaction*> *transactionHistory;

};


#endif //CUSTOMER_H
