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

#include "Collectible.h"

#include <utility>

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default Inventory
// Preconditions:  None
// Postconditions: Collectible is constructed with default values.
Collectible::Collectible() : Inventory(){
    this->amount = 0;
    this->name = "";
    this->type = 0;
    this->year = 0;
}

//--------------------------- Constructor -----------------------------
// Constructs a Collectible with the parameter values
// Preconditions:  None
// Postconditions: Collectible is created with inputed values
Collectible::Collectible(int year, string name, int amount, char type)
            : Inventory(){
    this->amount = amount;
    this->name = std::move(name);
    this->type = type;
    this->year = year;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
Collectible::~Collectible(){}

//---------------------------------display --------------------------------------
// Displays Collectible's information
// Preconditions: Collectible is not empty
// Postconditions: Collectible's information is displayed
void Collectible::display(ostream& output) const {
   //output << this->type << setw(3);
    output << this->name << "-" << this->year << " | ";
}

//---------------------getType-------------------------------
// Returns the number type of this Collectible.
// Preconditions: None.
//Postconditions: Type was returned.
char Collectible::getType() const {
    return this->type;
}

//---------------------getAmount-------------------------------
//
// Returns the amount of this Collectible.
// Preconditions: None.
//Postconditions: Amount was returned.
int Collectible::getAmount() const {
    return this->amount;
}

//---------------------getName-------------------------------
// Returns the name of this Collectible.
// Preconditions: None.
//Postconditions: Namewas returned.
string Collectible::getName() const {
    return this->name;
}

//---------------------getYear-------------------------------
// Returns the year of this Collectible.
// Preconditions: None.
//Postconditions: Year was returned.
int Collectible::getYear() const {
    return this->year;
}


