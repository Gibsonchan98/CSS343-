//---------------------------------------------------------------------------
// BINARY.H
// Member function definitions for class Binary
// Author:  Melanie Palomino
//---------------------------------------------------------------------------
// Binary class:  Creates binary numbers,that are stored in a bool array, from
//   user input or constructors. This program allows:
//   -- allows conversion of negative decimals
//   -- allows output of binary number
//   -- allows addition and subtraction of binary numbers.
//   -- allows for comparison of 2 binary numbers, element by element
//   -- allows for assignment of 2 binary numbers
//   -- size is part of the class (so no longer needs to be passed)
//   -- includes range checking, returns false if out of range
//
// Assumptions:
//   -- size defaults to 1 if int not specified
//   -- array bits is initialize to 0
//   -- user must enter valid integers when using >>
//   -- in <<, binary number is displayed without any space
//---------------------------------------------------------------------------

#ifndef HW1_BINARY_H
#define HW1_BINARY_H

#include <iostream>

using namespace std;

class Binary {

    //-----------------------------  <<  ----------------------------------------
    // Overloaded output operator for class Binary; outputs binary number
    // Preconditions:   a.bits must point to an array with size at least a.size
    // Postconditions:  If sign is negative then it is sent to output.
    //            Bits elements are sent one by one to output istream with no
    //            spaces between them or leading 0s.
    friend ostream& operator<<(ostream& output, const Binary& a);

    //----------------------------  >>  -----------------------------------------
    // Overloaded input operator for class Binary; inputs integer
    // Preconditions:   a.bits must point to an array with size at least a.size
    // Postconditions:  Input is converted to binary form and save in bool array.
    //              New Binary object is created with inputted value.
    friend istream& operator>>(istream& input, Binary& a);
public:
    //-------------------------- Constructor ------------------------------------
    // Default constructor for class Binary
    // Preconditions:   None
    // Postconditions:  array bits is initialized with a size of 1
    //        element of array is set to 0/false
    //        count is incremented.
    Binary();

    //-------------------------- Overloaded Constructor ----------------------------
    // Overloaded constructor for class Binary
    // Preconditions:   None
    // Postconditions: array bits is initialized with size determined by binary num
    //         int has been converted and elements are saved as 0 or 1 (false/true)
    //         count is incremented.
    //         Negative input values turn sign to true
    Binary(int num);

    //---------------------------- Copy -----------------------------------------
    // Copy constructor for class Array
    // Preconditions:   other.bits points to an array of size at least other.size
    // Postconditions:  other is copied into *this, count is incremented
    Binary(const Binary& other);

    //---------------------------- Destructor -----------------------------------
    // Destructor for class Binary
    // Preconditions:   bits points to memory on the heap
    // Postconditions:  Binary for bits is deallocated, count is decremented
    ~Binary();

    //************************OVERLOADED OPERATORS*********************************

    //-----------------------------  =  -----------------------------------------
    // Overloaded assignment operator
    // Preconditions:   right.bits points to an array of size at least right.size
    // Postconditions:  *this is assigned the same binary number as right
    const Binary& operator=(const Binary& right);

    //------------------------------  ==  ---------------------------------------
    // Determine if two binary numbers are equal.
    // Preconditions:   bits and right.bits point to arrays with size at least
    //          size and right.size, respectively
    // Postconditions:  true is returned if the binary objects have the same size
    //          and elements false is return otherwise
    bool operator==(const Binary& right) const;

    //--------------------------------  !=  -------------------------------------
    // Determine if two binary numbers are not equal.
    // Preconditions:   bits and bits.ptr point to arrays with size at least
    //          size and right.size, respectively
    // Postconditions:  false is returned if the binary objects have the same size
    //          and elements true is return otherwise
    bool operator!=(const Binary& right) const;

    //--------------------------------  +=  -------------------------------------
    // Sets current Binary to addition of itself and right Binary.
    // Preconditions:   bits and right.bits point to existing Binary.
    // Postconditions:   Returns resulting Binary of addition.
    //             Negative binary nums are handled like negative numbers.
    //             Returned value is the absolute value of Binary.
    Binary operator+=(const Binary& right);

    //--------------------------------  -=  -------------------------------------
    // Sets current Binary to subtraction of itself and right Binary.
    // Preconditions:   bits and right.bits point to existing Binary.
    // Postconditions:   Returns resulting Binary of subtraction.
    //             Negative binary nums are handled like negative numbers.
    //             Returned value is the absolute value of Binary.
    Binary operator-=(const Binary& right);

    //-------------------------------- + -------------------------------------
    // Adds two binary objects.
    // Preconditions:   bits and right.bits point to existing Binary.
    // Postconditions:  Returns by value resulting Binary
    //              Negative binary nums are handled like negative.
    //              Returned value is the absolute value of Binary.
    Binary operator+(const Binary& right) const;

    //--------------------------------  -  -------------------------------------
    // Subtracts two Binary numbers.
    // Preconditions:   bits and right.bits point to existing Binary.
    // Postconditions:  Returns by value resulting Binary of subtraction.
    //              Negative binary nums are handled like negative numbers.
    //              Returned value is the absolute value of Binary.
    Binary operator-(const Binary& right) const;


    //----------------------------- getBit ----------------------------------------
    // Finds bit at location n
    // Preconditions:   bits is not nullptr and n is not out of range
    // Postconditions:  Returns bool value of bit at n
    //            Returns false if n is out of range
    bool getBit(int n);

    //-----------------------------  setBit  ----------------------------------------
    // Changes bit at n to one/true
    // Preconditions:   bits is not nullptr and n is not out of range
    // Postconditions:  Returns true if change is successful.
    //            Returns false if n is out of range
    //            Changes bit at n to 1.
    bool setBit(int n);

    //-----------------------------  clearBit  ----------------------------------------
    // Changes bit at n to zero/false
    // Preconditions:   bits is not nullptr and n is not out of range
    // Postconditions:  Returns true if change is successful.
    //            Returns false if n is out of range
    //            Changes bit at n to 0.
    bool clearBit(int n);

    //-----------------------------  toggleBit ------------------------------------
    // Changes specified bit to true if false and vice versa.
    // Preconditions:   bits is not nullptr and n is not out of range
    // Postconditions:  Returns true if change is successful.
    //            Returns false if n is out of range
    //            if bit is 0, it is changed to 1
    //            if bit is 1, it is changed to 0
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

    //------------------------- toDecimal -----------------------------------
    // Return the number the Binary object is equal to.
    // Preconditions:  bits must not be null
    // Postconditions:  Returns the conversion of binary to decimal
    //           It is the absolute of the binary number
    int toDecimal();

    //------------------------- toBinary -----------------------------------
    // Converts decimal number to binary.
    // Preconditions:  none
    // Postconditions:  Populates the array with bool values
    //             Handles negative value and turns sign to true
    void toBinary(int num);
};



#endif //HW1_BINARY_H
