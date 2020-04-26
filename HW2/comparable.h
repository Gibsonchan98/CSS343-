//
// COMPARABLE.H
// Member function definitions for class Comparable
// Created by Melanie Palomino on 4/14/20.
//---------------------------------------------------------------------------
// Comparable class:  Encapsulates a char value that gathered from user input.
//   This program allows:
//   -- allows conversion of negative decimals
//   -- allows output of char data
//   -- allows for comparison of 2 Comparable objects
//
// Assumptions:
//   -- There are no blank inputs
//   -- user must enter valid char when using >>
//   -- This class needs no constructors or assignment operator, only >> is used
//---------------------------------------------------------------------------

#ifndef COMPARABLE_H
#define COMPARABLE_H

#include <iostream>
#include <string>

using namespace std;

class Comparable{

    //-----------------------------  <<  ----------------------------------------
    // Overloaded output operator for class Comparable; outputs char value
    // Preconditions:   none
    // Postconditions:  displays single data value
    friend ostream& operator<<(ostream& output, const Comparable& a);

    //----------------------------  >>  -----------------------------------------
    // Overloaded input operator for class Comaprable; inputs char value
    // Preconditions:   none
    // Postconditions:  input is stored in private data variable
    friend istream& operator>>(istream& input, Comparable& a);

public:

    //************************OVERLOADED OPERATORS*********************************

    //------------------------------  ==  ---------------------------------------
    // Determine if two Comparables are equal.
    // Preconditions: A Comparable Object must be passed through parameter
    // Postconditions:  true is returned if the Comparables have the same data
    bool operator==(const Comparable& right) const;

    //------------------------------  !=  ---------------------------------------
    // Determine if two Comparable Objects are not equal.
    // Preconditions: A Comparable object must be passed through paremeter
    // Postconditions:  true is returned if the binary objects have the same size
    //          and elements false is return otherwise
    bool operator!=(const Comparable& right) const;

    //------------------------------  <  ---------------------------------------
    // Determine if right Comparable is greater than this object
    // Preconditions:   A Comparable object must be passed through paremeter
    // Postconditions:  true is returned if this->char value is less than right
    bool operator<(const Comparable& right) const;

    //------------------------------  >  ---------------------------------------
    // Determine if right Comparable is less than this object
    // Preconditions:   A Comparable object must be passed through paremeter
    // Postconditions:  true is returned if this->char value is greater than right
    bool operator>(const Comparable& right) const;

private:
    char data;  //private variable to save data
};

#endif //COMPARABLE_H
