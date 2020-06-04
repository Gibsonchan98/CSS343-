//
// SportsCard.h
// Member function definitions for class SportsCard
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// SportsCard class: Represents a child class that inherits from Collectibles.
//      It has a private string to store manufacturer, a string for grade.
//
//   This program allows:
//      - Allows comparison between two SportsCard objects
//      - Allows the display of a SportsCard object
//      - Allows the copy of a SportsCard object
//      - Allows creating a SportsCard object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------
#include "SportsCard.h"

using namespace std;

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default SportsCard
// Preconditions:  None
// Postconditions: SportsCard is constructed with default values.
SportsCard::SportsCard() : Collectible() {
    this->manufacturer = "";
    this->grade = "";
}

//--------------------------- Constructor -----------------------------
// Constructs a SportsCard with the parameter values
// Preconditions:  None
// Postconditions: SportsCard is created with inputed values
SportsCard::SportsCard(int year, string name, int amount, char type, string manu, string grade)
            : Collectible(year,name,amount,type){

        this->manufacturer = manu;
        this->grade = grade;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
SportsCard::~SportsCard() {}

//--------------------------- create ----------------------------
// Creates a SportsCard object
// Preconditions:  input is in correct format and valid
// Postconditions: returns new SportsCard object constructed with input values.
SportsCard* SportsCard::create(ifstream &input) const {

    char type;
    int amt, year;
    string name, state, manufacturer;

    input >> type; //check if right type?
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
    getline(input, state, ',');
    input.ignore();
    getline(input, name, ',');
    input.ignore();
    getline(input, manufacturer);

    //int year, string name, int amount, char type, string manu, string grade
    return new SportsCard(year, name, amt, type,manufacturer, state);

}

//--------------------------- clone --------------------------------------
// Creates a clone of SportsCard object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the SportsCard Object
SportsCard* SportsCard::clone() const {

    return new SportsCard(getYear(), getName(),getAmount(),
            getType(), getManufacturer(), getGrade());

}

//-------------------------------- == ---------------------------------------
// Equal operator overload. Compares two SportsCard objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're equal
bool SportsCard::operator==(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return(this->getName() == card.getName() &&
           this->getAmount() == card.getAmount() &&
           this->getGrade() == card.getGrade() &&
           this->getType() == card.getType() &&
           this->getYear() == card.getYear() &&
           this->getManufacturer() == card.getManufacturer());

}

//-------------------------------- != ---------------------------------------
// Unequal operator overload. Compares two SportsCard objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're not equal
bool SportsCard::operator!=(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return !(*this == card);

}

//-------------------------------- > ---------------------------------------
// Greater than operator overload. Compares if this SportsCard is greater
// than the other.
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if this is greater than the other
bool SportsCard::operator>(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return(this->getName() > card.getName() &&
           this->getAmount() > card.getAmount() &&
           this->getGrade() < card.getGrade() &&
           this->getType() > card.getType() &&
           this->getYear() > card.getYear() &&
           this->getManufacturer() > card.getManufacturer());

}

//---------------------------------Display --------------------------------
// Displays SportsCard's information
// Preconditions:  SportsCard is not empty
// Postconditions:  SportsCard's information is displayed
void SportsCard::display(ostream &output) const {

    output << "Sports Card: ";
    //call display parent function by parent
    Collectible::display(output);
    output << " Manufacturer: " << this->manufacturer;
    output << " Grade: " << this->grade;

}

//---------------------getGrade--------------------------------------------
// Returns the grade of this SportsCard.
// Preconditions: None.
//Postconditions: Grade is returned.
string SportsCard::getGrade() const {
    return this->grade;
}

//--------------------- getManufacturer------------------------------------
// Returns the manufacturer of this SportsCard.
// Preconditions: None.
//Postconditions: value of string manu is returned.
string SportsCard::getManufacturer()const {
    return this->manufacturer;
}
