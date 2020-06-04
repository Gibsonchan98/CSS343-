//
// ComicBook.h
// Member function definitions for class ComicBook
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// ComicBook class: Represents a child class that inherits from Collectibles.
//      It has a private string to store publisher, a string for grade.
//
//   This program allows:
//      - Allows comparison between two ComicBook objects
//      - Allows the display of a ComicBook object
//      - Allows the copy of a ComicBook object
//      - Allows creating a ComicBook object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------

#ifndef COMICBOOK_H
#define COMICBOOK_H

#include "Collectible.h"

using namespace std;

class ComicBook : public Collectible {

public:
    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates a default ComicBook
    // Preconditions:  None
    // Postconditions: Comicbook is constructed with default values.
    ComicBook();

    //--------------------------- Constructor -----------------------------
    // Constructs a ComicBook with the parameter values
    // Preconditions:  None
    // Postconditions: ComicBook is created with inputed values
    ComicBook(int year, string name, int amount, char type, string pub, string grade);

    //--------------------------- Destructor ----------------------------
    // Deallocates all used memory
    // Preconditions:  None
    // Postconditions: All memory is deallocated
    virtual ~ComicBook();

    //--------------------------- create ----------------------------
    // Creates a SportsCard object
    // Preconditions:  input is in correct format and valid
    // Postconditions: returns new SportsCard object constructed with input values.
    virtual ComicBook* create(ifstream &input) const;

    //--------------------------- clone --------------------------------------
    // Creates a clone of Invetory object
    // Preconditions:  none
    // Postconditions: returns a pointer to the clone of the Inventory Object
    virtual ComicBook* clone() const;

    //-------------------------------- == ---------------------------------------
    // Equal operator overload. Compares two ComicBook objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're equal
    virtual bool operator==(const Inventory& other) const;

    //-------------------------------- != ---------------------------------------
    // Unequal operator overload. Compares two ComicBook objects equality
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if they're not equal
    virtual bool operator!=(const Inventory& other) const;

    //-------------------------------- > ---------------------------------------
    // Greater than operator overload. Compares if this ComicBook is greater
    // than the other.
    // Preconditions:  They must have comparable attributes
    // Postconditions: Returns true if this is greater than the other
    virtual bool operator>(const Inventory& other) const;


    //---------------------------------Display --------------------------------------
    // Displays ComicBook's information
    // Preconditions: ComicBook is not empty
    // Postconditions: ComicBook's information is displayed
    virtual void display(ostream& output) const;


    //---------------------getGrade-------------------------------
    // Returns the grade of this ComicBook.
    // Preconditions: None.
    //Postconditions: value of string grade is returned.
    string getGrade() const;


    //--------------------- getPub------------------------------
    // Returns the publisher  of this  ComicBook.
    // Preconditions: None.
    //Postconditions: value of string publisher is returned.
    string getPub() const;

private:

    //stores the grade of the ComicBook
    string grade;

    //stores publisher of ComicBook
    string publisher;

};


#endif //COMICBOOK_H
