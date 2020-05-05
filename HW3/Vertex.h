//
// VERTEX.H
// Member function definitions for class Vertex
// Created by Melanie Palomino on 4/25/20.
//---------------------------------------------------------------------------
// Vertex class:  Encapsulates a char value that gathered from user input.
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

#ifndef VERTEX_H
#define VERTEX_H

#include <string>
#include <iostream>

using namespace std;

class Vertex {

    //*************** FRIEND OPERATORS *****************************
    //overloaded operator to display data
    friend ostream& operator<<(ostream& output, const Vertex& vertex);

    //takes in info by input
    friend istream& operator>>(istream& input, Vertex& vertex);
    //**************************************************************

public:
    //*************** OPERATOR OVERLOAD ****************************

    //assignment operator
    const Vertex& operator=(const Vertex& other);

    //equality operator
    bool operator==(const Vertex& other) const;

    // operator
    bool operator!=(const Vertex& other) const;

    bool operator<(const Vertex& other) const;
    bool operator>(const Vertex& other) const;

    //**************************************************************

private:
    string data; //stores data of vertex
};


#endif //VERTEX_H
