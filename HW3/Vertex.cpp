//
// Vertex.cpp
// Member function definitions for class Vertex
// Created by Melanie Palomino on 4/25/20.
//---------------------------------------------------------------------------
// Vertex class:  Encapsulates a string value gathered from user input.
//   This program allows:
//   -- allows for comparisons between Vertex objects.
//   -- allows output of string data.
//   -- allows input of data.
//
// Assumptions:
//   -- Valid input
//   -- Input will only be through >> operator
//---------------------------------------------------------------------------

#include <string>
#include <fstream>

#include "Vertex.h"


//*************** FRIEND OPERATORS ********************************

//-------------------------- << -------------------------------
// Overloads << operator and displays string data
// Preconditions: node
// Postconditions: Returns string data
ostream &operator<<(ostream &output, const Vertex &vertex) {
    output << vertex.data;
    return output;
}

//-------------------------- >> --------------------------------
// Overloads operator >> and saves input into private data string
// Preconditions: Input is valid
// Postconditions: Input is saved in private string variable
istream &operator>>(istream &input, Vertex &vertex) {
    getline(input,vertex.data);
    //input >>vertex.data;
    return input;
}
//*****************************************************************

//*************** OVERLOADED OPERAOTRS ****************************

//-------------------------- = ---------------------------------
// Copies data value of the other Vertex object
// Preconditions: There is enough space
// Postconditions: This vertex object has same value as other.
const Vertex &Vertex::operator=(const Vertex &other) {
    if(*this != other){
        this->data = other.data;
    }
    return *this;
}

//-------------------------- == --------------------------------
// Compares equality of two vertex objects
// Preconditions: other is not empty
// Postconditions: True is returned if Vertex objects are the same.
//        same. Otherwise, it is false;
bool Vertex::operator==(const Vertex other) const {
    return this->data == other.data;
}

//-------------------------- != --------------------------------
// Compares inequality of two vertex objects
// Preconditions: other is not empty
// Postconditions: True is returned if Vertex objects aren not
//        the same. Otherwise, it is false;
bool Vertex::operator!=(const Vertex &other) const {
    return this->data != other.data;
}


//*****************************************************************