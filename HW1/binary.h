//
// Created by Melanie Palomino on 4/2/20.
//
//  Array of bools
//
//

#ifndef HW1_BINARY_H
#define HW1_BINARY_H

#include <iostream>

using namespace std;

class Binary{
    //ACCESSORS
    friend ostream& operator<<(ostream& output, const Binary& a);
    friend istream& operator>>(istream& input, Binary& a);
public:
    //default constructor
    Binary(); //set number to zero
    //one parameter constructor
    Binary(int num);
    //copy constructor
    Binary(const Binary& other);
    //destructor
    ~Binary();
    //OVERLOADED OPERATORS
    //assignment operator
    const Binary& operator=(const Binary& right);
    //equality
    bool operator==(const Binary& right) const;

    bool operator!=(const Binary& right) const;

    Binary operator+=(const Binary& right);
    Binary operator-=(const Binary& right);
    Binary operator+(const Binary& right) const;
    Binary operator-(const Binary& right) const;

    //MUTATORS
    //get Size
    int getSize();
    //getBit
    bool getBit(int n);
    //set bit
    bool setBit(int n);
    //clear bit
    bool clearBit(int n);
    //toggle bit
    bool toggleBit(int n);
private:

    //int that keeps track of array size
    int size;

    //is true if negative
    bool sign;

    //allocated array
    bool* bits; //ptr to first element of array

    //used to keep track of number of arrays created
    //later helpul to make sure all arrays are deleted
    static int count;
};



#endif //HW1_BINARY_H
