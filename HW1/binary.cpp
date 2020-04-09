//---------------------------------------------------------------------------
// BINARY.CPP
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
//   -- includes range checking, but program does not terminate
//
// Assumptions:
//   -- size defaults to 1 if int not specified
//   -- array bits is initialize to 0
//   -- user must enter valid integers when using >>
//   -- in <<, binary number is displayed without any space
//---------------------------------------------------------------------------
#include "binary.h"

#include <iostream>
#include <istream>
#include <stack>
using namespace std;


// Initialize static data member at file scope
int Binary::count = 0;

//-------------------------- Constructor ------------------------------------
// Default constructor for class Binary
// Preconditions:   None
// Postconditions:  array bits is initialized with a size of 1
//        element of array is set to 0/false
//        count is incremented.
Binary::Binary() {
    this->size = 1;
    this->sign = false;
    //allocate array with size 1
    bits = new bool[size];
    count++;
    //set number to 0
    bits[0] = false; //or 0
}

//-------------------------- Overloaded Constructor ----------------------------
// Overloaded constructor for class Binary
// Preconditions:   None
// Postconditions: array bits is initialized with size determined by binary num
//         int has been converted and elements are saved as 0 or 1 (false/true)
//         count is incremented.
//         Negative input values turn sign to true
Binary::Binary(int num) {
    if (num == 0) {
        this->sign = false;
        this->size = 1;
        bits = new bool[size];
        bits[0] = false;
    }
    else {
        toBinary(num);
    }

    count++;
}

//---------------------------- Copy -----------------------------------------
// Copy constructor for class Array
// Preconditions:   other.bits points to an array of size at least other.size
// Postconditions:  other is copied into *this, count is incremented
Binary::Binary(const Binary& other) {
    this->sign = other.sign;
    this->size = other.size;
    bits = new bool[size];
    for (int i = 0; i < size; i++) {
        this->bits[i] = other.bits[i];
    }
}

//---------------------------- Destructor -----------------------------------
// Destructor for class Binary
// Preconditions:   bits points to memory on the heap
// Postconditions:  Binary for bits is deallocated, count is decremented
Binary::~Binary() {
    delete[] bits;
    count--;
}


//----------------------------- getBit ----------------------------------------
// Finds bit at location n
// Preconditions:   bits is not nullptr and n is not out of range
// Postconditions:  Returns bool value of bit at n
//            Returns false if n is out of range
bool Binary::getBit(int n) {
    if (n < 0 || n >= size) {
        return false; //FOR NOW
    }
    //location int
    int loc = this->size - (n + 1);
    return this->bits[loc];
}

//****************************** MUTATORS *************************************

//-----------------------------  setBit  ----------------------------------------
// Changes bit at n to one/true
// Preconditions:   bits is not nullptr and n is not out of range
// Postconditions:  Returns true if change is successful.
//            Returns false if n is out of range
//            Changes bit at n to 1.
bool Binary::setBit(int n) {
    //CANNOT TAKE N THAT IS LARGER THAN SIXE
    if (n < 0 || n >= size) {
        return false;
    }
    int loc = this->size - (n + 1);
    return this->bits[loc] = true; //MAYBE SEPERATE THE RETURN
}

//-----------------------------  clearBit  ----------------------------------------
// Changes bit at n to zero/false
// Preconditions:   bits is not nullptr and n is not out of range
// Postconditions:  Returns true if change is successful.
//            Returns false if n is out of range
//            Changes bit at n to 0.
bool Binary::clearBit(int n) {
    //CANNOT TAKE N THAT IS LARGER THAN SIXE
    if (n < 0 || n >= size) {
        return false;
    }
    int loc = this->size - (n + 1);
    return this->bits[loc] = false; //MAYBE SEPERATE THE RETURN
}

//-----------------------------  toggleBit ------------------------------------
// Changes specified bit to true if false and vice versa.
// Preconditions:   bits is not nullptr and n is not out of range
// Postconditions:  Returns true if change is successful.
//            Returns false if n is out of range
//            if bit is 0, it is changed to 1
//            if bit is 1, it is changed to 0
bool Binary::toggleBit(int n) {
    if (n < 0 || n >= size) {
        return false;
    }
    int loc = this->size - (n + 1);
    bits[loc] = (bits[loc] == 0) ? 1 : 0;
    //if(bits[loc] == 0){bits[loc] = 1;}
    //bits[loc] = 0;
    return true;
}

//************************OVERLOADED OPERATORS*********************************

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator
// Preconditions:   right.bits points to an array of size at least right.size
// Postconditions:  *this is assigned the same binary number as right
const Binary& Binary::operator=(const Binary& right) {
    //check if they are already the same
    if (right == *this) {
        return *this;
    }
    //must delete everything and rewrite
    delete[] bits;
    this->sign = right.sign;
    this->size = right.size;
    bits = new bool[size];
    //copy all elements
    for (int i = 0; i < size; i++) {
        this->bits[i] = right.bits[i];
    }
    return *this;
}

//------------------------------  ==  ---------------------------------------
// Determine if two binary numbers are equal.
// Preconditions:   bits and right.bits point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  true is returned if the binary objects have the same size
//          and elements false is return otherwise
bool Binary::operator==(const Binary& right) const {
    bool result = false;
    if (this->size != right.size || this->sign != right.sign) {
        return false;
    }

    //if first element is not same then they are not equal
    if (bits[0] != right.bits[0]) {
        return false;
    }

    for (int i = 0; i < size; i++) {
        result = bits[i] == right.bits[i];
    }
    return result;
}

//--------------------------------  !=  -------------------------------------
// Determine if two binary numbers are not equal.
// Preconditions:   bits and right.bits point to arrays with size at least
//          size and right.size, respectively
// Postconditions:  false is returned if the binary objects have the same size
//          and elements true is return otherwise
bool Binary::operator!=(const Binary& right) const {
    bool result = false;
    if (this->size != right.size || this->sign != right.sign) {
        return true;
    }

    for (int i = 0; i < size; i++) {
        result = bits[i] != right.bits[i];
    }
    return result;
}

//-------------------------------- + -------------------------------------
// Adds two binary objects.
// Preconditions:   bits and right.bits point to existing Binary.
// Postconditions:  Returns by value resulting Binary
//              Negative binary nums are handled like negative.
//              Returned value is the absolute value of Binary.
Binary Binary::operator+(const Binary& right) const {
    Binary temp = *this;  //temp of this object
    Binary tempRight = right; //temp of added
    int num = temp.toDecimal();
    int rightNum = tempRight.toDecimal();
    if (tempRight.sign) { rightNum *= -1; } // if negative then change num
    if (temp.sign) { num *= -1; }
    int newNum = num + rightNum;
    Binary result(newNum);
    return result;
}


//--------------------------------  -  -------------------------------------
// Subtracts two Binary numbers.
// Preconditions:   bits and right.bits point to existing Binary.
// Postconditions:  Returns by value resulting Binary of subtraction.
//              Negative binary nums are handled like negative numbers.
//              Returned value is the absolute value of Binary.
Binary Binary::operator-(const Binary& right) const {
    Binary temp = *this;  //temp of this object
    Binary tempRight = right; //temp of added
    int num = temp.toDecimal();
    int rightNum = tempRight.toDecimal();
    if (tempRight.sign) { rightNum *= -1; } // if negative then change num
    if (temp.sign) { num *= -1; }
    int newNum = num - rightNum;
    Binary result(newNum);
    return result;
}


//--------------------------------  +=  -------------------------------------
// Sets current Binary to addition of itself and right Binary.
// Preconditions:   bits and right.bits point to existing Binary.
// Postconditions:   Returns resulting Binary of addition.
//             Negative binary nums are handled like negative numbers.
//             Returned value is the absolute value of Binary.
Binary Binary::operator+=(const Binary& right) {
    //Binary temp = *this + right;
    *this = *this + right;
    return *this;
}

//--------------------------------  -=  -------------------------------------
// Sets current Binary to subtraction of itself and right Binary.
// Preconditions:   bits and right.bits point to existing Binary.
// Postconditions:   Returns resulting Binary of subtraction.
//             Negative binary nums are handled like negative numbers.
//             Returned value is the absolute value of Binary.
Binary Binary::operator-=(const Binary& right) {
    *this = *this - right;
    return *this;
}

//************************ FRIEND OPERATORS ***********************************

//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class Binary; outputs binary number
// Preconditions:   a.bits must point to an array with size at least a.size
// Postconditions:  If sign is negative then it is sent to output.
//            Bits elements are sent one by one to output istream with no
//            spaces between them or leading 0s.
ostream& operator<<(ostream& output, const Binary& a) {
    int tracker = 0; //used to see where to start displaying
    if (a.sign) {
        output << "-";
    }

    if (a.size > 1) {
        for (int i = 0; i < a.size; i++) {
            if (a.bits[i] != 0) {
                break;
            }
            tracker++;
        }
        for (int i = tracker; i < a.size; i++) {
            output << a.bits[i] << "";
        }
    }
    else {
        output << a.bits[0];
    }

    return output;
}



//----------------------------  >>  -----------------------------------------
// Overloaded input operator for class Binary; inputs integer
// Preconditions:   a.bits must point to an array with size at least a.size
// Postconditions:  Input is converted to binary form and save in bool array.
//              New Binary object is created with inputted value.
istream& operator>>(istream& input, Binary& a) {
    int temp; //storge for input 
    input >> temp;
    Binary b(temp);
    a = b;

    return input;
}

//********************** PRIVATE CONVERTERS ***********************************

//------------------------- toDecimal -----------------------------------
// Return the number the Binary object is equal to
// Preconditions:  bits must not be null
// Postconditions:  Returns the conversion of binary number
//           It is the absolute of the binary number
int Binary::toDecimal() {
    int power = 1, decimalNum = 0, c = 1;
    for (int i = (this->size - 1); i >= 0; i--) { //start from lsn
        if (c != 1) {
            power *= 2;
        }
        decimalNum += this->bits[i] * power;
        c++;
    }
    return decimalNum;
}

//------------------------- toBinary -----------------------------------
// Converts decimal number to binary
// Preconditions:  none
// Postconditions:  Populates the array with bool values
//             Handles negative value and turns sign to true
void Binary::toBinary(int num) {
    int temp = 0, a = 0, b = 0;
    this->sign = false;
    //check if negative
    if (num < 0) {
        num = num * -1;
        this->sign = true;
    }
    //create temp stack
    stack<bool> tempStack;
    //conversion
    for (int i = num; i > 0; i = i / 2) {
        temp = num % 2;
        tempStack.push(temp);
        num = num / 2;
        a++;
        // cout << "Num " << a << ": " << temp << endl;
    }
    this->size = tempStack.size();
    this->bits = new bool[this->size];
    while (!tempStack.empty()) {
        this->bits[b] = tempStack.top();
        //cout << "Front Num " << b << ": " << tempVector.top()<< endl;
        tempStack.pop();
        b++;
    }

}
