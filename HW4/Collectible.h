//
// Collectible.h
// Member function definitions for class Collectible
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Collectible class: Represents a parent class that a type of collectible
//      can inherit from. It has a private int to store the amount of an
//      object that is in stock. It also contains a string for name,an int
//      for year. And a private char type to describe what type of
//      collectible it is.
//
//   This program allows:
//      - Allows comparison between two Collectible objects
//      - Allows the display of an Collectible object
//      - Allows the copy of an Collectible object
//      - Allows creating an Collectible object using a specified file.
//      -
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------

#ifndef COLLECTIBLE_H
#define COLLECTIBLE_H

#include <string>
#include <iostream>
#include <fstream>
#include <climits>

#include "Inventory.h"

using namespace std;

class Collectible : public Inventory{

public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Inventory
    // Preconditions:  None
    // Postconditions: Collectible is constructed with default values.
    Collectible();
    //All values are set to zero or null

    //--------------------------- Constructor -----------------------------
    // Constructs a Collectible with the parameter values
    // Preconditions:  None
    // Postconditions: Collectible is created with inputed values
    Collectible(int year, string name, int amount, char type);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~Collectible();

    //--------------------------- create ----------------------------
    // Creates a Collectible object
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new Collectible object constructed with input values.
    virtual Collectible* create(ifstream& input) const = 0;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Invetory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Inventory Object
    virtual Collectible* clone() const = 0;


    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two Collectible objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're equal
    virtual bool operator==(const Inventory& other) const = 0;

    //-------------------------------- == ---------------------------------------
    // Not equal operator overload. Compares two Inventory objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const = 0;

    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares if this Collectible is greater
    // than the other.
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const = 0;

    //---------------------------------display --------------------------------------
    // Displays Collectible's information
    // Preconditions: Collectible is not empty
    // Postconditions: Collectible's information is displayed
    virtual void display(ostream& output) const;

    //---------------------getType-------------------------------
    // Returns the number type of this Collectible.
    // Preconditions: None.
    //Postconditions: Type was returned.
    char getType() const;

    //---------------------getAmount-------------------------------
    //
    // Returns the amount of this Collectible.
    // Preconditions: None.
    //Postconditions: Amount was returned.
    int getAmount() const;

    //---------------------getName-------------------------------
    // Returns the name of this Collectible.
    // Preconditions: None.
    //Postconditions: Namewas returned.
    string getName() const;

    //---------------------getYear-------------------------------
    // Returns the year of this Collectible.
    // Preconditions: None.
    //Postconditions: Year was returned.
    int getYear() const;

private:

    //describes what type of collectible it is
    char type;

    //Collectible's name/type
    string name;

    //Collectible's date, year it was made.
    int year;

    //amount in inventory
    int amount;
};


#endif //HW4_COLLECTIBLE_H
