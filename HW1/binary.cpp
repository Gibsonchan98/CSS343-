//
// Created by Melanie Palomino on 4/2/20.
//
// Array of bools
//
//
//
//
//
//

//
#include "binary.h"

#include <iostream>
#include <istream>
#include <stack>
using namespace std;


// Initialize static data member at file scope
int Binary::count = 0;

//set number to zero
Binary::Binary(){
    this-> size = 1;
    //allocate array with size 1
    bits = new bool[size];
    count++;
    //set number to 0
    bits[0] = false; //or 0
}
//one parameter constructor
Binary::Binary(int num){
    int temp = 0, a = 0, b = 0;
    if(num < 0){
        num = num*-1;
        this->sign = true;
    }
    //create temp stack
    stack<bool> tempVector;
    //conversion
    for(int i = num; i > 0; i = i/2){
        temp = num%2;
        tempVector.push(temp);
        num = num/2;
        a++;
        // cout << "Num " << a << ": " << temp << endl;
    }
    this->size = tempVector.size();
    bits = new bool[this->size];
    while(!tempVector.empty()){
        bits[b] = tempVector.top();
        //cout << "Front Num " << b << ": " << tempVector.top()<< endl;
        tempVector.pop();
        cout << bits[b];
        b++;
    }
    count++;
}

//copy constructor
Binary::Binary(const Binary& other){
    this->sign = other.sign;
    this->size = other.size;
    bits = new bool[size];
    for(int i = 0; i < size; i++){
        this->bits[i] = other.bits[i];
    }
}

//destructor
Binary::~Binary(){
    delete[] bits;
}

//MUTATORS

//getBit
bool Binary::getBit(int n){
    if(n < 0){
        return false; //FOR NOW
    }
    //location int
    int loc = this->size - (n+1);
    return this->bits[loc];
}

//set bit return true if succesull
//sets bit n to one/true
bool Binary::setBit(int n){
    //CANNOT TAKE N THAT IS LARGER THAN SIXE
    if(n < 0 || n >= size){
        return false;
    }
    int loc = this->size - (n+1);
    return this->bits[loc] = 1; //MAYBE SEPERATE THE RETURN
}

//clear bit
//sets bit n to zero/false
bool Binary::clearBit(int n){
    //CANNOT TAKE N THAT IS LARGER THAN SIXE
    if(n < 0 || n >= size){
        return false;
    }
    int loc = this->size - (n+1);
    return this->bits[loc] = 0; //MAYBE SEPERATE THE RETURN
}

//toggle bit
//changes false to true and true to false.
bool Binary::toggleBit(int n){
    //CANNOT TAKE N THAT IS LARGER THAN SIXE
    if(n < 0 || n >= size){
        return false;
    }
    int loc = this->size - (n+1);
    bits[loc] = (bits[loc] == 0) ? 1: 0;
    //if(bits[loc] == 0){bits[loc] = 1;}
    //bits[loc] = 0;
    return true;
}

//OPERATORS

//add two binary numbers or bools
Binary Binary::operator+(const Binary& right) const{
    Binary temp = *this;  //temp of this object
    Binary tempRight = right; //temp of added
//********************CONVERSION TO INT****************************//
    int num = temp.toDecimal();
    cout << "Num: " << num  << endl;
    int rightNum = tempRight.toDecimal();
    cout << "rightNum: " << rightNum << endl;
//*****************************************************************//
    int newNum = num + rightNum;
    Binary result(newNum);
    cout << "Sum: " << newNum << endl;
    return result;
}




//out
//Output the binary number with no spaces. Use a preceding "-" if it is negative. Do not output leading zeros. Do not output endl.
ostream& operator<<(ostream& output, const Binary& a){
    //display negative sign if negative
    if(a.sign == true){
        output << "-";
        for(int i = 0; i < a.size; i++){
            output << a.bits[i];
        }
    }
    return output;
}

//turns binary to decimal and returns decimal
int Binary::toDecimal(){
    int power = 1, decimalNum = 0, count = 1;
    for(int i = (this->size -1) ; i >= 0; i--){ //start from lsn
        if(count != 1) {
            power *= 2;
        }
        decimalNum += this->bits[i] * power;
        count++;
    }
    return decimalNum;
}
