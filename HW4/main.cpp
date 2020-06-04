#include <iostream>
#include <string>
#include <fstream>

#include "Store.h"

using namespace std;

int main() {
    Store store;
    ifstream infile1("hw4inventory.txt");
    ifstream infile2("hw4commands.txt");
    ifstream infile3("hw4customers.txt");

    if(!infile1 || !infile2 || infile3){
        cout << "FILE CANNOT BE OPENED" << endl;
        return 1;
    }

    store.buildInventory(infile1);
    store.buildCustomers(infile2);
    store.buildTransactions(infile3);
    store.processTransactions();


}
