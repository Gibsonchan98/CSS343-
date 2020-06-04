//
// SportsCard.h
// Member function definitions for class SportsCard
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// SportsCard class: Represents a child class that inherits from Collectibles.
//      It has a private string to store manufacturer, a string for grade.
//
//
//   This program allows:
//      - Allows comparison between two SportsCard objects
//      - Allows the display of a SportsCard object
//      - Allows the copy of a SportsCard object
//      - Allows creating a SportsCard object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------
#ifndef SPORTSCARD_H
#define SPORTSCARD_H

#include <string>
#include <iostream>
#include <fstream>

#include "Collectible.h"

class SportsCard : public Collectible {

public:

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default SportsCard
    // Preconditions:  None
    // Postconditions: SportsCard is constructed with default values.
    SportsCard();


    //--------------------------- Constructor -----------------------------
    // Constructs a SportsCard with the parameter values
    // Preconditions:  None
    // Postconditions: SportsCard is created with inputed values
    SportsCard(int year, string name, int amount, char type, string manu, string grade);


    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~SportsCard();

    //--------------------------- create ----------------------------
    // Creates a SportsCard object
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new SportsCard object constructed with input values.
    virtual SportsCard* create(ifstream &input) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of SportsCard object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the SportsCard Object
    virtual SportsCard* clone() const;

    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two SportsCard objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're equal
    virtual bool operator==(const Inventory& other) const;

    //-------------------------------- != ---------------------------------------
    // Unequal operator overload. Compares two SportsCard objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const;

    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares if this SportsCard is greater
    // than the other.
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const;


    //---------------------------------Display --------------------------------
    // Displays SportsCard's information
    // Preconditions:  SportsCard is not empty
    // Postconditions:  SportsCard's information is displayed
    virtual void display(ostream& output) const;

    //---------------------getGrade--------------------------------------------
    // Returns the grade of this SportsCard.
    // Preconditions: None.
    //Postconditions: Grade is returned.
    string getGrade() const;

    //--------------------- getManufacturer------------------------------------
    // Returns the manufacturer of this SportsCard.
    // Preconditions: None.
    //Postconditions: value of string manu is returned.
    string getManufacturer() const;

private:

    //private string to store manufacturer name
    string manufacturer;

    //stores type of grade
    string grade;

};


#endif //HW4_SPORTSCARD_H
