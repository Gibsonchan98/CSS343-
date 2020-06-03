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

Coin::Coin() : Collectible(){
    this->grade = 0;
}

Coin::Coin(int year, string name, int amount, char type, int grade)
    : Collectible(year,name,amount,type){
    this->grade = grade;
}

Coin::~Coin()= default;

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

void Coin::display(ostream &output) const {
    output << "Coin : ";
    Collectible::display(output);
    output << "Grade: " << this->grade;
}

bool Coin::operator==(const Inventory& other) const {

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return(this->getName() == coin.getName() &&
            this->getAmount() == coin.getAmount() &&
            this->getGrade() == coin.getGrade() &&
            this->getType() == coin.getType() &&
            this->getYear() == coin.getYear());
}

bool Coin::operator!=(const Inventory& other) const{

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return !(*this == coin);
}

bool Coin::operator>(const Inventory& other) const {

    const Coin& coin = dynamic_cast<const Coin&>(other);

    return(this->getName() > coin.getName() ||
           this->getAmount() > coin.getAmount() ||
           this->getGrade() < coin.getGrade() || //A is better than B
           this->getType() > coin.getType() ||
           this->getYear() > coin.getYear());
}


int Coin::getGrade() const {
    return this->grade;
}

Coin* Coin::clone() const {
    //year,name,amt,type,g
    return new Coin(getYear(), getName(),
            getAmount(),getType(),getGrade());
}




