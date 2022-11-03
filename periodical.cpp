//---------------------------------------------------------------------------
// _PERIODICAL_H
// Class Periodical is the subclass of Book.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "periodical.h"

//---------------------------------------------------------------------------
// Constructor
// Initializes bookTitle, year, month, bookFormat, totalCopies, and
// numOfCopiesIn. Genre is set to "PERIODICAL"
Periodical::Periodical() : Book() {
    bookTitle = "";
    genre = "PERIODICAL";
    year = 0;
    month = 0;
    bookFormat = 'H';
    totalCopies = 1;
    numOfCopiesIn = 1;
}

//---------------------------------------------------------------------------
// Destructor
// Nothing to do
Periodical::~Periodical() { }

//---------------------------------------------------------------------------
// getMonth
// Returns int month
int Periodical::getMonth() const{
    return month;
}

//---------------------------------------------------------------------------
// create
// returns a new Periodical Object
Item* Periodical::create() const {
    return new Periodical();
}

//---------------------------------------------------------------------------
// setData
// Sets the data of month year and the book title
void Periodical::setData(ifstream& infile) {
    infile.get();
    getline(infile, bookTitle, ',');

    infile.get();
    infile >> month;

    infile.get();
    infile >> year;
}

//---------------------------------------------------------------------------
// setCommandData
// sets the data for the bookFormat and same as setData
void Periodical::setCommandData(ifstream& infile) {
    infile.get();
    infile >> bookFormat;

    infile.get();
    infile >> year;

    infile.get();
    infile >> month;

    infile.get();
    getline(infile, bookTitle, ',');
}

//---------------------------------------------------------------------------
// display
// Prints out year, month, and bookTitle
void Periodical::display() const {
    cout << left << setw(8) << 
    year << setw(5) << month << setw(MAX_TITLE_LENGTH) << 
    bookTitle.substr(0, MAX_TITLE_LENGTH) << endl;
}

//---------------------------------------------------------------------------
// operator<
// Returns true if this is less than the parameter and false if not. This is
// done by comparing the dates and the bookTitle.
bool Periodical::operator<(const NodeData& bookToCompare) const {
    const Periodical* p = dynamic_cast<const Periodical*>(&bookToCompare);
    if (year < p->year) {
        return true;
    } else if (year == p->year) {
        if (month < p->month) {
            return true;
        } else if (month == p->month) {
            if (bookTitle < p->bookTitle) {
                return true;
            }
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// operator==
// Returns true if this is the same as the one in the parameter and false if not
bool Periodical::operator==(const NodeData& bookToCompare) const {
    const Periodical* p = dynamic_cast<const Periodical*>(&bookToCompare);
    return bookTitle == p->bookTitle && year == p->year && month == p->month;
}

//------------------------------------------------------------------------------
// displayData
// Displays book information
// prints out the number of copies in the library, the year, the month, and
// the book title.
void Periodical::displayData() const {
    cout << left << setw(7) << numOfCopiesIn << setw(8) << 
    year << setw(15) << month << left << setw(MAX_TITLE_LENGTH + 5) <<
    bookTitle.substr(0, MAX_TITLE_LENGTH) << endl;
}

//------------------------------------------------------------------------------
// displayHeader
// Displays the headers
// prints out the genre books on the first line to inform what kind of genre
// it is printing. Then it prints out "AVAIL" "YEAR" "MONTH" and "TITLE"
// evenly above the data to make it look clearer
void Periodical::displayHeader() const {
    cout << genre << " BOOKS" << endl;
    cout << left << setw(7) << "AVAIL" << left << setw(8) <<
    "YEAR" << setw(15) << 
    "MONTH" << left << setw(MAX_TITLE_LENGTH) << "TITLE" << endl;
}
