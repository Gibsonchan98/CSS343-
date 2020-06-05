#include <iostream>
#include <string>
#include <fstream>

#include "Store.h"

using namespace std;

int main() {
    Store store;

    ifstream infile1("/Users/marielaespinoza/Melanie/CSS343/HW4/hw4inventory.txt");
    ifstream infile2("/Users/marielaespinoza/Melanie/CSS343/HW4/hw4commands.txt");
    ifstream infile3("/Users/marielaespinoza/Melanie/CSS343/HW4/hw4customers.txt");

    string file= "/Users/marielaespinoza/Melanie/CSS343/HW4/commands.txt";

    if(!infile1 || !infile2 || !infile3){
        cout << "FILE CANNOT BE OPENED" << endl;
        return 1;
    }

     store.buildInventory(infile1);
     //store.display();
     store.buildCustomers(infile3);
     //store.allHistory();
     store.buildTransactions(file);
   //  store.allHistory();
     store.processTransactions();

    return 0;
}
