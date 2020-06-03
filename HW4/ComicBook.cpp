//
// ComicBook.h
// Member function definitions for class ComicBook
// Created by Melanie Palomino on 5/19/20.
//---------------------------------------------------------------------------
// ComicBook class: Represents a child class that inherits from Collectibles.
//      It has a private string to store publisher, a string for grade.
//
//   This program allows:
//      - Allows comparison between two ComicBook objects
//      - Allows the display of a ComicBook object
//      - Allows the copy of a ComicBook object
//      - Allows creating a ComicBook object using a specified file.
//
//  Assumptions:
//  	- Input file is valid and correct
//---------------------------------------------------------------------------

#include "ComicBook.h"

ComicBook::ComicBook() : Collectible() {
    this->grade = "";
    this->publisher = "";
}

ComicBook::ComicBook(int year, string name, int amount, char type, string pub, string grade)
    : Collectible(year, name, amount,type){
    this->publisher = pub;
    this->grade = grade;
}

ComicBook::~ComicBook(){}

ComicBook *ComicBook::create(ifstream& input) const{
    char type;
    int amt, year;
    string name, strgrade, publisher;

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
    getline(input, strgrade, ',');
    input.ignore();
    getline(input, name, ',');
    input.ignore();
    getline(input, publisher);

    return new ComicBook(year, name, amt, type, publisher, strgrade);
}

ComicBook* ComicBook::clone() const {
    //int year, string name, int amount, char type, string pub, string grade
    return new ComicBook(getYear(), getName(), getAmount(),
            getType(), getPub(), getGrade());
}

bool ComicBook::operator==(const Inventory& other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return(this->getName() == comic.getName() &&
           this->getAmount() == comic.getAmount() &&
           this->getGrade() == comic.getGrade() &&
           this->getType() == comic.getType() &&
           this->getYear() == comic.getYear() &&
           this->getPub() == comic.getPub());
}

bool ComicBook::operator!=(const Inventory &other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return !(*this == comic);
}

bool ComicBook::operator>(const Inventory& other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return(this->getName() > comic.getName() ||
           this->getAmount() > comic.getAmount() ||
           this->getGrade() < comic.getGrade() ||
           this->getType() > comic.getType() ||
           this->getYear() > comic.getYear());

}

void ComicBook::display(ostream& output) const {

    output << "Comicbook: ";
    //call display parent function by parent
    Collectible::display(output);
    output << "Publisher: " << this->publisher;
    output << "Grade: " << this->grade;
}

string ComicBook::getGrade() const {
    return this->grade;
}

string ComicBook::getPub() const {
    return this->publisher;
}




