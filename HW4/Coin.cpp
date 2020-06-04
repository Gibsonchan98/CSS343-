//
// Coin.h
// Member function definitions for class Coin
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// Coin class: Represents a child class that inherits from Collectibles.
//      It has a private int for grade.
//
//
//   This program allows:
//      - Allows comparison between two Coin objects
//      - Allows the display of a Coin object
//      - Allows the copy of a Coin object
//      - Allows creating a Coin object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------

#include "Coin.h"

#include <utility>

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default Coin
// Preconditions:  None
// Postconditions: Coin is constructed with default values.
Coin::Coin() : Collectible(){
    this->grade = 0;
}

//--------------------------- Constructor -----------------------------
// Constructs a Coin with the parameter values
// Preconditions:  None
// Postconditions: Coin is created with inputed values
Coin::Coin(int year, string name, int amount, char type, int grade)
    : Collectible(year,name,amount,type){
    this->grade = grade;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
Coin::~Coin(){}

//--------------------------- create ----------------------------
// Creates a Coin object
// Preconditions:  input is in correct format and valid
// Postconditions: returns new Coin object constructed with input values.
Coin* Coin::create(ifstream& input) const {
    char type;
    int amt, year, g;
    string name;

    input >> type;
    input.ignore();
    input.ignore();
    input >> amt;
    if(amt < 1){ //if it is zero or negative
        amt = 0;
    }
    input.ignore();
    input.ignore();
    input >> year;
    input.ignore();
    input.ignore();
    input >> g;
    input.ignore();
    input.ignore();
    getline(input, name);

    return new Coin(year,name,amt,type,g);

}

//--------------------------- clone --------------------------------------
// Creates a clone of Coin object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the Coin Object
Coin* Coin::clone() const {
    //year,name,amt,type,g
    return new Coin(getYear(), getName(),
                    getAmount(),getType(),getGrade());
}

//---------------------------------display --------------------------------------
// Displays Coin's information
// Preconditions: Coin is not empty
// Postconditions: Coin's information is displayed
void Coin::display(ostream &output) const {
    output << "Coin : ";
    Collectible::display(output);
    output << "Grade: " << this->grade ;
}

//-------------------------------- == ---------------------------------------
// Equal operator overload. Compares two Coin objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're equal
bool Coin::operator==(const Inventory& other) const {

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return(this->getName() == coin.getName() &&
            this->getAmount() == coin.getAmount() &&
            this->getGrade() == coin.getGrade() &&
            this->getType() == coin.getType() &&
            this->getYear() == coin.getYear());
}


//-------------------------------- != ---------------------------------------
// Not equal operator overload. Compares two Coin objects
// Preconditions:  They must have comparable attributes
// Postconditions: returns true if they're not equal
bool Coin::operator!=(const Inventory& other) const{

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return !(*this == coin);
}


//-------------------------------- > ---------------------------------------
// Greater than operator overload. Compares if this Coin is greater
// than the other.
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if this is greater than the other
bool Coin::operator>(const Inventory& other) const {

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return(this->getName() > coin.getName() ||
           this->getAmount() > coin.getAmount() ||
           this->getGrade() < coin.getGrade() || //A is better than B
           this->getType() > coin.getType() ||
           this->getYear() > coin.getYear());
}

//---------------------getGrade-------------------------------
// Returns the grade of this Coin.
// Preconditions: None.
//Postconditions: value of int grade is returned.
int Coin::getGrade() const {
    return this->grade;
}







