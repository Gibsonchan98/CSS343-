//
// Inventory.h
// Member function definitions for class Inventory
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Inventory class: Represents any type of object in the store. An abstract
//      class. It is a parent class used by collectibles & transaction
//      classes. All its methods are virtual.
//
//   This program allows:
//      - Allows comparison between two Inventory objects
//      - Allows the display of an Inventory object
//      - Allows the copy of an Inventory object
//      - Allows creating an Inventory object using a specified file.
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Inventory {

    //------------------------------------ << ---------------------------------
    // Overloads << operator
    // Preconditions:  Inventory is not empty
    // Postconditions: Inventory information and history is displayed
    friend ostream& operator<<(ostream& output, const Inventory& item){
       item.display(output);
       return output;
    }

public:
    //--------------------------- Deafult Constructor -------------------------
    // Default constructor. Creates a default Inventory
    // Preconditions:  None
    // Postconditions: Inventory is constructed with default values.
    Inventory(){}


    //--------------------------- Destructor ----------------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~Inventory() {}

    //--------------------------- create --------------------------------------
    // Creates an Invetory object
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new Inventory object constructed
    //          with input values.
    virtual Inventory* create(ifstream& input) const = 0;


    //--------------------------- clone --------------------------------------
    // Creates a clone of Invetory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Inventory Object
    virtual Inventory* clone() const = 0;


    //-------------------------------- == -------------------------------------
    // Equal operator overload. Compares two Inventory objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're equal
    virtual bool operator==(const Inventory& other) const = 0;

    //-------------------------------- == -------------------------------------
    // Not equal operator overload. Compares two Inventory objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const = 0;


    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares two Inventory objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const = 0;


    //---------------------------------Display --------------------------------
    // Displays Invetory's information
    // Preconditions: Inventory is not empty
    // Postconditions: Invetory's information is displayed
    virtual void display(ostream& output) const = 0;

};


#endif //INVENTORY_H
