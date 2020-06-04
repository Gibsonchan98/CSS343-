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
#include "iomanip"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default Store
// Preconditions:  None
// Postconditions: Store  is constructed with default values.
Store::Store(){

    //Collectibles hashtable
    this->collectFactory = new Factory();
    //initialize collectibles  hashtable
    this->collectFactory->insert('M', new Coin());
    this->collectFactory->insert('C', new ComicBook());
    this->collectFactory->insert('S', new SportsCard());

    //Transaction hashtable
    this->transFactory = new Factory();
    //initialize collectibles  hashtable
    this->transFactory->insert('D',new InventoryDisplay);
    this->transFactory->insert('S', new Sell());
    this->transFactory->insert('B',new Buy());
    this->transFactory->insert('C', new CustomerHistory());
    this->transFactory->insert('H', new History());

    //initialize hastable of BSTs of collectibles
    this->inventoryList = new SearchTree* [MAX_ITEMS];
    for(int i = 0; i < this->size; i++){
        this->inventoryList[i] = nullptr;
    }

    //create class or seperate functions
    //adding types of collectibles to tree
    if(('M' - 'A') > this->size){this->resize('M'-'A');}
    this->inventoryList['M' - 'A'] = new SearchTree();

    if(('C' - 'A') > this->size){this->resize('C'-'A');}
    this->inventoryList['C' - 'A'] = new SearchTree();

    if(('S' - 'A') > this->size){this->resize('S'-'A');}
    this->inventoryList['S' - 'A'] = new SearchTree();

    //initialize hastable for customers
    this->customerList = new Inventory*[MAX_CUSTOMERS];

    //initialize BST of customers
    this->customers = new SearchTree();

    //initialize queue of transacions
    this->transList = new queue <Inventory*> ();

    this->size = MAX_ITEMS;
}


//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions: none
// Postconditions: All memory is deallocated
Store::~Store(){
    delete collectFactory;
    delete transFactory;
    delete customers;
    delete inventoryList;
    delete customerList;
}

//---------------------------buildCustomer ----------------------------
// Builds tree of customers
// Preconditions:  file exists and it is opened
// Postconditions: File is read and customers are added
void Store::buildCustomers(ifstream &input) {
    //read file
    for(;;){

        Customer* custTemp = new Customer(input);

        //if at end of the file
        if(input.eof()){
            delete custTemp;
            break;
        }

        int ID = custTemp->getID();
        //add customer
        this->customers->insert(custTemp);
        this->customerList[ID] = custTemp;
    }

}

//--------------------------- buildInventory ----------------------------
// Builds inventory
// Preconditions:  file exists and it is opened
// Postconditions: File is read and inventory is read
void Store::buildInventory(ifstream &input){
    //read file for inventory
    for(;;){
        char type = input.peek();
        Inventory* item = collectFactory->create(input);

        //if at end of the file
        if(input.eof()){
            delete item;
            break;
        }
        //if item was able to be created
        if(item != nullptr){
            //add item funtion
            Collectible* collect = dynamic_cast<Collectible*>(item);

            int amt = collect->getAmount();

            int index = type - 'A';

            //add item to tree
            for(int i = 0; i < amt; i++){
                inventoryList[index]->insert(item);
            }

        }

    }

}

//--------------------------- buildTransactions ----------------------------
// Builds transaction
// Preconditions:  file exists and it is opened
// Postconditions: File is read and transactions are read and processed
void Store::buildTransactions(ifstream &input) {
    for(;;){
        Inventory* trans = transFactory->create(input);
        //if at end of the file
        if(input.eof()){

            if(trans == nullptr){
                delete trans;
                break;
            }

        }

        if(trans != nullptr){

            Inventory* collectible = collectFactory->create(input);

            if(collectible !=nullptr){
                TransactionItem* temp = dynamic_cast<TransactionItem*>(trans);
                Collectible* coll = dynamic_cast<Collectible*>(collectible);
                temp->setItem(coll);
                temp = nullptr;
            }
            transList->push(trans);
        }
    }

}

//-------------------------- Sell ----------------------------
// Sells an item of the store
// Preconditions:  Store is not empty
// Postconditions: Collectible is removed from inventory
void Store::sell() {

    Sell* trans = dynamic_cast<Sell*>(transList->front());

    Collectible* item = trans->getItem();

    int ID = trans->getCustID();
    if(item != nullptr){

        int index = item->getType() - 'A';

        if(ID > 0 && ID < MAX_CUSTOMERS){

            SearchTree *tree = inventoryList[index];

            if(tree->remove(*item)){
                Customer* customer = dynamic_cast<Customer*> (customerList[ID]);
                customer->addTransaction(trans);
                customer = nullptr;
            }
            else{
                cout << "ITEM OUT OF STOCK!" << endl;
                delete trans;
            }
            tree = nullptr;
        }
        else{
            cout << "CUSTOMER DOES NOT EXIST" << endl;
            delete trans;
        }
    }
    else{
        delete trans;
    }
    trans = nullptr;
    item = nullptr;
}



//--------------------------Buy  ----------------------------------------------
// Buys an item for the store
// Preconditions:  Item exists
// Postconditions: Adds item to store
void Store::buy() {
    //cast transaction
    Buy* trans = dynamic_cast<Buy*>(transList->front());
    int ID = trans->getCustID();

    Inventory* item = trans->getItem()->clone();

    if(item != nullptr){

        Collectible* collectible = trans->getItem();
        int index = collectible->getType() - 'A';
        //if able to insert item

        if(inventoryList[index]->insert(item)){
            Customer* customer = dynamic_cast<Customer*>(customerList[ID]);
            customer->addTransaction(trans);
            customer = nullptr;
        }
        else{
            cout << "COULD NOT BUY COLLECTIBLE" << endl;
            delete item;
            delete trans;
        }
        collectible = nullptr;
    }

    else{

        delete trans;
    }
    trans = nullptr;
    item = nullptr;
}

//-------------------------- display ----------------------------
// Displays store inventory
// Preconditions:  Store is not empty
// Postconditions: All inventory is displayed
void Store::display() {
    cout << "_________________________________________________________" << endl;
    cout << setw(35) << "STORE INVENTORY" << setw(35) << endl;
    cout << "_________________________________________________________" << endl;
    cout << *inventoryList['M'-'A'] << endl;
    cout << *inventoryList['C'-'A'] << endl;
    cout << *inventoryList['S'-'A'] << endl;
}

//-------------------------- customerHistory ----------------------------
// Displays customer transaction history
// Preconditions:  Customer exists
// Postconditions: Cusctomer's transaction history is displayed.
void Store::customerHistory(int ID) const {
    //if customer exists
    if(customerList[ID] != nullptr){
    cout << "_________________________________________________________" << endl;
    cout << setw(43) << "CUSTOMER TRANSACTION HISTORY" << setw(43) << endl;
    cout << "_________________________________________________________" << endl;
    cout << *customerList[ID] << endl << endl;
    }
    else{
        cout << "CUSTOMER " << ID <<  " DOES NOT EXIST" << endl;
    }

}

//--------------------------allHistory ----------------------------------------
// Displays store's customers' transaction history
// Preconditions:  Store is not empty
// Postconditions: All store's customers' transaction history  is displayed
void Store::allHistory() const {
    cout << "__________________________________________________________" << endl;
    cout << setw(43) << "STORE TRANSACTION HISTORY" << setw(43) << endl;
    cout << "__________________________________________________________" << endl;
    cout << *customers << endl << endl;
}


//-------------------------- resize ----------------------------
// Resize hashtable
// Preconditions: size is double previous size
// Postconditions: All inventroy is displayed
void Store::resize(int num) {

   SearchTree** temp = new SearchTree*[num + 1];

   //initialize to avoid issues in VS
   for(int i = 0; i <= num; i++){
        temp[i] = nullptr;
    }

    for(int i = 0; i <= this->size; i++){
        temp[i] = inventoryList[i];
    }

    delete inventoryList;
    inventoryList = temp;
    this->size = num + 1;
    temp = nullptr;
}


//--------------------------- processTransactions ----------------------------
// Process transactions
// Preconditions:  file exists and it is opened
// Postconditions: File is read and transactions are read and processed
void Store::processTransactions() {
    //run all the transactions
    while(!this->transList->empty()){
        Transaction* trans = dynamic_cast<Transaction*>(transList->front());
        trans->run(this);
        //remove from queue
        transList->pop();
    }
}








