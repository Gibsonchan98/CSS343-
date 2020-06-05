//
// Store.h
// Member function definitions for class Store
// Created by Melanie Palomino on 5/15/20.
//---------------------------------------------------------------------------
// Store class: Creates storage for  the store's customer, inventory information.
//   The infomation is intialized from reading files.
//   It also processes the transactions given from a file. It contains three
//   hashtables. One containing pointers to customers, another to transactions.
//   Lastly, the third one contains pointers to BSTs of collectibles.
//   In addition, it contains a BST to sort customers
//   This program allows:
//  	- Allows adding a Customer object.
//  	- Allows adding a Item object to the inventory.
//  	- Allows adding a Transaction object.
//  	- Allows processing the Transactions.
//  Assumptions:
//  	- Customers, Transactions, and Items are not nullptrs
//---------------------------------------------------------------------------

#ifndef STORE_H
#define STORE_H

#include <string>
#include <queue>
#include <iostream>
#include <fstream>
#include "Factory.h"
#include "Hashtable.h"
#include "SearchTree.h"
#include "Customer.h"
#include "Collectible.h"
#include "Coin.h"
#include "SportsCard.h"
#include "ComicBook.h"
#include "Transaction.h"
#include "Sell.h"
#include "Buy.h"
#include "History.h"
#include "InventoryDisplay.h"
#include "CustomerHistory.h"


using namespace std;

class Transaction;

class Store {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Store
    // Preconditions:  None
    // Postconditions: Store  is constructed with default values.
    Store();



    /*  //--------------------------- Copy Constructor -----------------------------
      // Copys all values of other store
      // Preconditions:  Other is not empty
      // Postconditions: Store  is constructed with other's values
      Store(const Store& other);
      //set all values the same*/

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions: none
    // Postconditions: All memory is deallocated
    ~Store();

    //---------------------------buildCustomer ----------------------------
    // Builds tree of customers
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and customers are added
    void buildCustomers(ifstream& file);

    //--------------------------- buildInventory ----------------------------
    // Builds inventory
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and inventory is read
    void buildInventory(ifstream& file);

    //--------------------------- buildTransactions ----------------------------
    // Builds transaction
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and transactions are read and processed
    void buildTransactions(string file);

    //--------------------------- processTransactions ----------------------------
    // Process transactions
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and transactions are read and processed
    void processTransactions();

    //-------------------------- display ----------------------------
    // Displays store inventory
    // Preconditions:  Store is not empty
    // Postconditions: All inventory is displayed
    void display();

    //--------------------------Buy  ----------------------------
    // Buys an item for the store
    // Preconditions:  Item exists
    // Postconditions: Adds item to store
    void buy();

    //-------------------------- Sell ----------------------------
    // Sells an item of the store
    // Preconditions:  Store is not empty
    // Postconditions: Collectible is removed from inventory
    void sell();

    //-------------------------- customerHistory ----------------------------
    // Displays customer transaction history
    // Preconditions:  Customer exists
    // Postconditions: Cusctomer transaction history is displayed.
    void customerHistory(int ID) const;

    //--------------------------allHistory ----------------------------
    // Displays store's transaction history
    // Preconditions:  Store is not empty
    // Postconditions: All store's transaction history  is displayed
    void allHistory() const;


private:

    //tree of customers to sort them properly
    SearchTree* customers;

    //tree array of  (HASHTABLE)
    SearchTree** inventoryList;

    //vector of transactions
    queue <Inventory*>* transList;

    //Factory Transaction object
    Factory* transFactory;

    //Factory Type of object
    Factory* collectFactory;

    //hashtable for customer
    Inventory** customerList;

    //size
    int size;

    //max amount of customers
    const static int MAX_CUSTOMERS = 1000;

    //max amount of items
    const static int MAX_ITEMS = 26;


    //-------------------------- resize ----------------------------
    // Resize hashtable
    // Preconditions: size is double previous size
    // Postconditions: All inventroy is displayed
    void resize(int num);
};


#endif //HW4_STORE_H
