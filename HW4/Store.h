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

class Store {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Store
    // Preconditions:  None
    // Postconditions: Store  is constructed with default values.
    Store(){
        //initialize all vectors, arrays, and Trees:
        //Initialized values are of null or 0
        // cutomerTable = new Inventory*[maxCustomers];
        // inventoryList = new SearchTree*[XX];
        // transFactory->add(types of transactions)
        //
        //collectFactory->add(types of collectibles)
        //
    }

    //--------------------------- Copy Constructor -----------------------------
    // Copys all values of other store
    // Preconditions:  Other is not empty
    // Postconditions: Store  is constructed with other's values
    Store(const Store& other);
    //set all values the same

    //---------------------------buildCustomer ----------------------------
    // Builds tree of customers
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and customers are added
    ~Store();
    void buildCustomers(ifstream& file){
        for(;;){
            /*
             * Customer* temp = new Customer(file) ;
             *  int num = 0;
             *  if(at end of file) delete temp;  break;
             *  num = temp->getId number
             *  add customer to tree ->insert(temp)
             *  add to table[num] = temp;
             *
             * */
        }

    }

    //--------------------------- buildInventory ----------------------------
    // Builds inventory
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and inventory is read
    void buildInventory(ifstream& file){
        for(;;){
            /*
             * Inventory* temp;
             * char type;
             * type = get from file
             * temp = collectFactory->create(file)
             *  if(at end of file) delete temp;  breakl;
             *  Collectible temp2 = dynamic cast  Collecitbble
             *  create index/key
             *  if(index is greater than table size)
             *      resize;
             *
             *  add count
             *  add to tree:  table[index] = temp2
             * */
        }

    }

    //--------------------------- buildTransactions ----------------------------
    // Builds transaction
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and transactions are read and processed
    void buildTransactions(ifstream& file){
        for(;;){
            /*
             * Inventory* temp;
             * char type;
             * temp = transFactory->create(file)
             *  if(at end of file) delete temp;  break;
             *  if(temp is not nullptr){
             *      Transaction temp2 = dynamic cast to transction type
             *      Collectible item = dynamic cast to collectible
             *      Transaction trans = Transaction(type, item)
            *       add to vector. push
             *  }
             *
             * process transcations
             *
             * */
        }
    }

    //--------------------------- processTransactions ----------------------------
    // Process transactions
    // Preconditions:  file exists and it is opened
    // Postconditions: File is read and transactions are read and processed
    void processTransactions(){
        /*
         * Transaction trans = dynamic cast<vector transactio>
         *  trans->run(this);
         *      delete from vector
         *
         * */
    }

    //-------------------------- display ----------------------------
    // Displays store inventory
    // Preconditions:  Store is not empty
    // Postconditions: All inventory is displayed
    void display(){
        /*
         * cout << *inventoryList[coin key] << endl;
         * cout << *inventoryList[comic key] << endl;
         * cout << *inventoryList[card key] << endl;
         * */
    }

    //--------------------------Buy  ----------------------------
    // Buys an item for the store
    // Preconditions:  Item exists
    // Postconditions: Adds item to store
    void buy(){
        /*
         * Buy ptr* = dynamic cast from vector
         * Collectible* item = dynamic cast
         * if(ptr is not null)
         *      if(0 < custID is valid < 1000)
         *      SearchTree* inventory = look for item in array inventoryList
         *      if(inventory->insert item){
         *          Customer* cust = dynamic cast from (customerTable (ptr custID)
         *          add transaction to customer
         *      }
         *      else {
         *         cout << ERROR MESSAGE
         *      }
         *      delete inventory
         *   else{
         *      delete cust
         *      cout << customer doesn't exists
         *  }
         *  else{
         *      delete ptr
         *      cout << ERROR TRANSACTION
         *  }
         *
         * */
    }

    //-------------------------- Sell ----------------------------
    // Sells an item of the store
    // Preconditions:  Store is not empty
    // Postconditions: Collectible is removed from inventory
    void sell(){
        /*
         * Buy ptr* = dynamic cast from vector
         * Collectible* item = dynamic cast
         * if(ptr is not null)
         *      if(0 < custID is valid < 1000)
         *      SearchTree* inventory = look for item in array inventoryList
         *      if(inventory->remove item){
         *          Customer* cust = dynamic cast from (customerTable (ptr custID)
         *          add transaction to customer
         *      }
         *      else {
         *         cout << ERROR MESSAGE
         *      }
         *      delete inventory
         *   else{
         *      delete cust
         *      cout << customer doesn't exists
         *  }
         *  else{
         *      delete ptr
         *      cout << ERROR TRANSACTION
         *  }
         *
         * */
    }

    //-------------------------- customerHistory ----------------------------
    // Displays customer transaction history
    // Preconditions:  Customer exists
    // Postconditions: Cusctomer transaction history is displayed.
    void customerHistory(int ID) const{
        /*
         * if(customerTable contains customer){
         *     cout << *customerTable[int location] << endl;
         *
         * }
         * else{
         *  cout << CUSTOMER ERROR
         * }
         *
         * */
    }

    //--------------------------allHistory ----------------------------
    // Displays store's transaction history
    // Preconditions:  Store is not empty
    // Postconditions: All store's transaction history  is displayed
    void allHistory() const{
        /*
         * display customer searchtree inorder (alphabetical)
         *  cout << *customers;
         *
         * */


    }


private:
    //tree of customers to sort them properly
    SearchTree* customers;

    //tree array of collectibles
    SearchTree** inventoryList;

    //vector of transactions
    vector<Inventory*> trans;

    //Factory Transaction object
    Factory transFactory;

    //Factory Type of object
    Factory collectFactory;

    //hashtable for customer
    Inventory** customerTable;

    //size
    int size;

    //max amount of customers
    int maxCustomers = 1000;

    //-------------------------- resize ----------------------------
    // Resize hashtable
    // Preconditions: size is double previous size
    // Postconditions: All inventroy is displayed
    void resize(int num){
        //Searchtree** temp = new Searchtree[ this->size + 1];

        //copy array
        /* for(int i = 0, until it is equal to size  )
         *   temp[i] = nullptr; //initialize
         *   temp[i] = inventoryList[i]; //copy hash
         * }
         *
         * delete invertoryList
         * inventoryList copy temp
         * copy temp size + 1
         * delete temp
         * */
    }
};


#endif //HW4_STORE_H
