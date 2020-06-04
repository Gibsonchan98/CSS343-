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

#include "Customer.h"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default customer
// Preconditions:  none
// Postconditions: Customer is constructed with default values.
Customer::Customer() : Inventory() {
    this->name = "None";
    this->ID = 0;
    this->transactionHistory = new vector<Transaction*>();
}


//--------------------------- Constructor from File ----------------------------
// Creates a customer using file input
// Preconditions:  input is in correct format and valid
// Postconditions: Customer is constructed with input values.
Customer::Customer(ifstream& input){
    input >> this->ID;
    input.ignore(2);
    getline(input,name);
    this->transactionHistory = new vector<Transaction*>();
}


//--------------------------- Constructor -----------------------------
// Creates a customer from string name and int ID
// Preconditions: Name and ID are valid input
// Postconditions: Customer is constructed with input values.
Customer::Customer(string name, int ID) : Inventory(){
    this->name = name;
    this->ID = ID;
    this->transactionHistory = new vector<Transaction*>();
}


//--------------------------- Constructor -----------------------------
// Creates a customer from string name, int ID, and vector
// Preconditions: Name,ID, and vector are valid input
// Postconditions: Customer is constructed with input values.
Customer::Customer(string name, int ID, vector<Transaction *> *transaction)
            : Inventory(){
    this->ID = ID;
    this->name = name;
    this->transactionHistory = transaction;
}


//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  transactionHistory vector is not empty
// Postconditions: All memory is deallocated
Customer::~Customer(){
    delete this->transactionHistory;
}

//--------------------------- create ----------------------------
// Creates a customer using file input
// Preconditions:  input is in correct format and valid
// Postconditions: returns new Customer object constructed with input values.
Customer* Customer::create(ifstream& input) const{
    int ID;
    string nameT;
    input >> ID;
    input.ignore(2);
    getline(input,nameT);
    return new Customer(nameT,ID);
}

//--------------------------- clone --------------------------------------
// Creates a clone of Invetory object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the Inventory Object
Customer* Customer::clone() const{
    //create new vector
    vector<Transaction*> *transHist = new vector<Transaction*>();

    for(int i = 0; i < (long)transactionHistory->size(); i++){
       // transaction = i->clone();
        transHist->push_back(transactionHistory->at(i)->clone());
    }

    //copy transaction vector
    return new Customer(getName(), getID(),transHist);
}

//-------------------------------- == ---------------------------------------
// Equal operator overload. Compares two Customer objects
// Preconditions:  They must have comparable attributes
// Postconditions: returns true if they're equal
bool Customer::operator==(const Inventory& other) const{

    const Customer& cust = dynamic_cast<const Customer&>(other);

    return this->name == cust.name && this->ID == cust.getID();
}

//-------------------------------- != ---------------------------------------
// Unequal operator overload. Compares two Customer objects
// Preconditions:  They must have comparable attributes
// Postconditions: returns true if they're not equal
bool Customer::operator!=(const Inventory &other) const {

    const Customer& cust = dynamic_cast<const Customer&>(other);

    return !(*this == cust);
}


//-------------------------------- > ---------------------------------------
// Greater than operator overload. Compares two Customer objects
// Preconditions:  They must have comparable attributes
// Postconditions: returns true if name is greater than the other name
bool Customer::operator>(const Inventory& other) const{
    //used for sorting in tree
    const Customer& cust = dynamic_cast<const Customer&>(other);

    if(this->name.compare(cust.name) > 0 ){
        return true;
    }
    if(this->getName() == cust.getName()){
        if(this->getID()> cust.getID()){
            return true;
        }
    }

    return false;

}


//---------------------------------Display --------------------------------------
// Displays Customer info and transaction history
// Preconditions:  Customer is not empty
// Postconditions: Customer information and history is displayed
void Customer::display(ostream& output) const{

    output << "Name: " << setw(6) << this->name << endl;
    output << "ID: " << setw(8) << this->ID << endl;
    output << "Transaction history: " << endl;

    for(int i = 0; i < (long)this->transactionHistory->size(); i++){

        output<< i + 1  << ". ";
        output << *this->transactionHistory->at(i) << endl;

    }
}

//---------------------addTransaction---------------------------------
// Adds transaction to vetor
// Preconditions: Transaction is not null
// Postconditions: Transaction is saved in vector
void Customer::addTransaction(Transaction* transaction){

    if(transaction != nullptr){

        this->transactionHistory->push_back(transaction);

    }
}

//---------------------  getID ---------------------------------
// Returns ID number
// Preconditions: none
// Postconditions: Value of int ID number is returned
int Customer::getID() const{
    return this->ID;
}

//---------------------  getName ---------------------------------
// Returns Customer's name
// Preconditions: none
// Postconditions: Value of string name is returned
string Customer::getName() const{
    return this->name;
}

//------------------------------------ << --------------------------------------
// Overloads << operator
// Preconditions:  Customer is not empty
// Postconditions: Customer information and history is displayed
ostream& operator<<(ostream& output, const Customer& customer){
    //call display
    customer.display(output);

    return output;
}



