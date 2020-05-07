//
// Vertex.h
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

#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <iostream>

using namespace std;

class Vertex {

    //*************** FRIEND OPERATORS *****************************

    //-------------------------- << -------------------------------
    // Overloads << operator and displays string data
    // Preconditions: node
    // Postconditions: Returns string data
    friend ostream& operator<<(ostream& output, const Vertex& vertex);

    //-------------------------- >> --------------------------------
    // Overloads operator >> and saves input into private data string
    // Preconditions: Input is valid
    // Postconditions: Input is saved in private string variable
    friend istream& operator>>(istream& input, Vertex& vertex);
    //**************************************************************

public:
    //*************** OPERATOR OVERLOAD ****************************

    //-------------------------- = ---------------------------------
    // Copies data value of the other Vertex object
    // Preconditions: There is enough space
    // Postconditions: This vertex object has same value as other.
    const Vertex& operator=(const Vertex& other);

    //-------------------------- == --------------------------------
    // Compares equality of two vertex objects
    // Preconditions: other is not empty
    // Postconditions: True is returned if Vertex objects are the same.
    //        same. Otherwise, it is false;
    bool operator==(const Vertex& other) const;

    //-------------------------- != --------------------------------
    // Compares inequality of two vertex objects
    // Preconditions: other is not empty
    // Postconditions: True is returned if Vertex objects aren not
    //        the same. Otherwise, it is false;
    bool operator!=(const Vertex& other) const;

    bool operator<(const Vertex& other) const;
    bool operator>(const Vertex& other) const;

    //**************************************************************

private:
    string data; //stores data of vertex
};


#endif //VERTEX_H
