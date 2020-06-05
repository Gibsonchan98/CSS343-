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

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates a default ComicBook
// Preconditions:  None
// Postconditions: Comicbook is constructed with default values.
ComicBook::ComicBook() : Collectible() {
    this->grade = "";
    this->publisher = "";
}

//--------------------------- Constructor -----------------------------
// Constructs a ComicBook with the parameter values
// Preconditions:  None
// Postconditions: ComicBook is created with inputed values
ComicBook::ComicBook(int year, string name, int amount, char type, string pub, string grade)
    : Collectible(year, name, amount,type){
    this->publisher = pub;
    this->grade = grade;
}

//--------------------------- Destructor ----------------------------
// Deallocates all used memory
// Preconditions:  None
// Postconditions: All memory is deallocated
ComicBook::~ComicBook()= default;

//--------------------------- create ----------------------------
// Creates a SportsCard object
// Preconditions:  input is in correct format and valid
// Postconditions: returns new SportsCard object constructed with input values.
ComicBook *ComicBook::create(ifstream& input) const{
    char type;
    int temp, amt, year;
    string name, strgrade, pub;

    input >> type; //check if right type?
    input.ignore();
    input.ignore();
    input >> temp;
    if(temp < 0){ //if it is zero or negative
       return nullptr;
    }
    //see if temp is a year or a count
    if(temp > 1800){
        year = temp;
        amt = 0;
    }
    else{
        amt = temp;
        input.ignore();
        input.ignore();
        input >> year;
    }
    input.ignore();
    input.ignore();
    getline(input, strgrade, ',');
    input.ignore();
    getline(input, name, ',');
    input.ignore();
    getline(input, pub);

    return new ComicBook(year, name, amt, type, pub, strgrade);
}

//--------------------------- clone --------------------------------------
// Creates a clone of ComicBook object
// Preconditions:  none
// Postconditions: returns a pointer to the clone of the ComicBook Object
ComicBook* ComicBook::clone() const {
    //int year, string name, int amount, char type, string pub, string grade
    return new ComicBook(getYear(), getName(), getAmount(),
            getType(), getPub(), getGrade());
}

//-------------------------------- == ---------------------------------------
// Equal operator overload. Compares two ComicBook objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're equal
bool ComicBook::operator==(const Inventory& other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return(this->getName() == comic.getName() &&
           this->getGrade() == comic.getGrade() &&
           this->getType() == comic.getType() &&
           this->getYear() == comic.getYear() &&
           this->getPub() == comic.getPub());
}

//-------------------------------- != ---------------------------------------
// Unequal operator overload. Compares two ComicBook objects equality
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if they're not equal
bool ComicBook::operator!=(const Inventory &other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return !(*this == comic);
}

//-------------------------------- > ---------------------------------------
// Greater than operator overload. Compares if this ComicBook is greater
// than the other.
// Preconditions:  They must have comparable attributes
// Postconditions: Returns true if this is greater than the other
bool ComicBook::operator>(const Inventory& other) const {

    const ComicBook& comic = dynamic_cast<const ComicBook&>(other);

    return(this->getName() > comic.getName() ||
           this->getGrade() < comic.getGrade() ||
           this->getType() > comic.getType() ||
           this->getYear() > comic.getYear());

}

//---------------------------------Display --------------------------------------
// Displays ComicBook's information
// Preconditions: ComicBook is not empty
// Postconditions: ComicBook's information is displayed
void ComicBook::display(ostream& output) const {

    output << "Comicbook(" << this->getAmount() << "): ";
    //call display parent function by parent
    Collectible::display(output);
    output << "Publisher: " << this->publisher << " | ";
    output << "Grade: " << this->grade;
}

//---------------------getGrade-------------------------------
// Returns the grade of this ComicBook.
// Preconditions: None.
//Postconditions: value of string grade is returned.
string ComicBook::getGrade() const {
    return this->grade;
}

//--------------------- getPub------------------------------
// Returns the publisher  of this  ComicBook.
// Preconditions: None.
//Postconditions: value of string publisher is returned.
string ComicBook::getPub() const {
    return this->publisher;
}




