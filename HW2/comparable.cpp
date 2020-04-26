//
// COMPARABLE.CPP
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
#include "comparable.h"

#include <iostream>
#include <string>

using namespace std;

//************* FRIEND OPERATORS ****************************

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Comparable; outputs char value
// Preconditions:   none
// Postconditions:  displays single data value
ostream& operator<<(ostream& output, const Comparable& comp){
    output << comp.data;
    return output;
}

//----------------------------  >>  -----------------------------------------
// Overloaded input operator for class Comaprable; inputs char value
// Preconditions:   none
// Postconditions:  input is stored in private data variable
istream& operator>>(istream& input, Comparable& comp){
    input >> comp.data;
    return input;
}

//************************************************************

//********************** EQUALITY COMPARISONS *********************************
//------------------------------  ==  ---------------------------------------
// Determine if two Comparables are equal.
// Preconditions: A Comparable Object must be passed through parameter
// Postconditions:  true is returned if the Comparables have the same data
bool Comparable::operator==(const Comparable &right) const {
    return this->data == right.data;
}


//------------------------------  !=  ---------------------------------------
// Determine if two Comparables are not equal.
// Preconditions: A Comparable object must be passed through paremeter
// Postconditions:  true is returned if the binary objects have the same size
//          and elements false is return otherwise
bool Comparable::operator!=(const Comparable &right) const {
    return this->data != right.data;
}
//************************************************************



//***************  GREATER THAN OR LESS **********************

//------------------------------  <  ---------------------------------------
// Determine if right Comparable is greater than this object
// Preconditions:   A Comparable object must be passed through paremeter
// Postconditions:  true is returned if this->char value is less than right
bool Comparable::operator<(const Comparable &right) const {
    return this->data < right.data;
}

//------------------------------  >  ---------------------------------------
// Determine if right Comparable is less than this object
// Preconditions:   A Comparable object must be passed through paremeter
// Postconditions:  true is returned if this->char value is greater than right
bool Comparable::operator>(const Comparable &right) const {
    return this->data > right.data;
}
//************************************************************