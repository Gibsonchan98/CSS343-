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


SportsCard::SportsCard() : Collectible() {
    this->manufacturer = "";
    this->grade = "";
}

SportsCard::SportsCard(int year, string name, int amount, char type, string manu, string grade)
            : Collectible(year,name,amount,type){

        this->manufacturer = manu;
        this->grade = grade;
}

SportsCard::~SportsCard() {}

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

SportsCard* SportsCard::clone() const {

    return new SportsCard(getYear(), getName(),getAmount(),
            getType(), getManufacturer(), getGrade());

}

bool SportsCard::operator==(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return(this->getName() == card.getName() &&
           this->getAmount() == card.getAmount() &&
           this->getGrade() == card.getGrade() &&
           this->getType() == card.getType() &&
           this->getYear() == card.getYear() &&
           this->getManufacturer() == card.getManufacturer());

}

bool SportsCard::operator!=(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return !(*this == card);

}

bool SportsCard::operator>(const Inventory &other) const {

    const SportsCard& card = dynamic_cast<const SportsCard&>(other);

    return(this->getName() > card.getName() &&
           this->getAmount() > card.getAmount() &&
           this->getGrade() < card.getGrade() &&
           this->getType() > card.getType() &&
           this->getYear() > card.getYear() &&
           this->getManufacturer() > card.getManufacturer());

}

void SportsCard::display(ostream &output) const {

    output << "Sports Card: ";
    //call display parent function by parent
    Collectible::display(output);
    output << "Manufacturer: " << this->manufacturer;
    output << "Grade: " << this->grade;

}

string SportsCard::getGrade() const {
    return this->grade;
}

string SportsCard::getManufacturer()const {
    return this->manufacturer;
}
