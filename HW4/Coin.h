//
// Coin.h
// Member function definitions for class Coin
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Coin class: Represents a child class that inherits from Collectibles.
//      It has a private int for grade.
//
//
//   This program allows:
//      - Allows comparison between two Coin objects
//      - Allows the display of a Coin object
//      - Allows the copy of a Coin object
//      - Allows creating a Coin object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------
#ifndef COIN_H
#define COIN_H

#include "Collectible.h"

using namespace std;

class Coin : public Collectible {

public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default Coin
    // Preconditions:  None
    // Postconditions: Coin is constructed with default values.
    Coin();

    //--------------------------- Constructor -----------------------------
    // Constructs a Coinwith the parameter values
    // Preconditions:  None
    // Postconditions: Coin is created with inputed values
    Coin(int year, string name, int amount, char type, int grade);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~Coin();

    //--------------------------- create ----------------------------
    // Creates a SportsCard object
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new SportsCard object constructed with input values.
    virtual Coin* create(ifstream &input) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Invetory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Inventory Object
    virtual Coin* clone() const;

    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two SportsCard objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're equal
    virtual bool operator==(const Inventory& other) const;

    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares if this SportsCard is greater
    // than the other.
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const;

    //-------------------------------- == ---------------------------------------
    // Not equal operator overload. Compares two Coin objects
    // Preconditions:  They must have comparable attributes
    // Postconditions: returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const;


    //---------------------------------display --------------------------------------
    // Displays Coin's information
    // Preconditions: Coin is not empty
    // Postconditions: Coin's information is displayed
    virtual void display(ostream& output) const;

    //---------------------getGrade-------------------------------
    // Returns the grade of this Coin.
    // Preconditions: None.
    //Postconditions: value of int grade is returned.
    int getGrade() const;


private:

    //stores the grade of the coin
    int grade;

};


#endif //COIN_H
