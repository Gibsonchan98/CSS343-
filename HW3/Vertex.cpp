//
// VERTEX.CPP
// Member function definitions for class Vertex
// Created by Melanie Palomino on 4/25/20.
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

#include "Vertex.h"

//*************** FRIEND OPERATORS ********************************

//displays data of vertex
ostream &operator<<(ostream &output, const Vertex &vertex) {
    output << vertex.data;
    return output;
}

//takes input and stores it in the vertex data
istream &operator>>(istream &input, Vertex &vertex) {
    input >> vertex.data;
    return input;
}
//*****************************************************************

//*************** OVERLOADED OPERAOTRS ****************************
const Vertex &Vertex::operator=(const Vertex &other) {
    if(*this != other){
        this->data = other.data;
    }
    return *this;
}

bool Vertex::operator==(const Vertex &other) const {
    return false;
}
bool Vertex::operator!=(const Vertex &other) const {
    return this->data != other.data;
}


bool Vertex::operator>(const Vertex &other) const {
    return this->data > other.data;
}

bool Vertex::operator<(const Vertex &other) const {
    return this->data < other.data;
}
//*****************************************************************