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

#include "Store.h"
