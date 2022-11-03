//---------------------------------------------------------------------------
// CHILDRENSBOOK.H
// Class ChildrensBook represents a book from the children's book genre
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "childrensBook.h"

//------------------------------------------------------------------------------
// Constructor
// initializes author, bookTitle, year, bookFormat, totalCopies, and
// numOfCopiesIn
ChildrensBook::ChildrensBook() : Book(){
    author = "";
    genre = "CHILDREN";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
    totalCopies = 5;
    numOfCopiesIn = 5;
}

//------------------------------------------------------------------------------
// Destructor
ChildrensBook::~ChildrensBook() {

}

//------------------------------------------------------------------------------
// getAuthor
// returns author of book
string ChildrensBook::getAuthor() const{
    return author;
}

//------------------------------------------------------------------------------
// create
// Creates and returns a new ChildrensBook object
Item* ChildrensBook::create() const {
    return new ChildrensBook();
}

//------------------------------------------------------------------------------
// setData
// sets data for book
void ChildrensBook::setData(ifstream& infile) {
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, bookTitle, ',');

    //infile.get();
    infile >> year;
}

//------------------------------------------------------------------------------
// setCommandData
// Sets the data of the ChildrensBook object
void ChildrensBook::setCommandData(ifstream& inFile) {
    inFile.get();
    inFile >> bookFormat;

    inFile.get();
    getline(inFile, bookTitle, ',');

    inFile.get();
    getline(inFile, author, ',');
}

//------------------------------------------------------------------------------
// display
// Displays the data of the ChildrensBook object
void ChildrensBook::display() const{
    cout << left << 
    setw(MAX_TITLE_LENGTH + 2) << bookTitle.substr(0, MAX_TITLE_LENGTH) << 
    setw(MAX_AUTHOR_LENGTH + 2) << 
    author.substr(0, MAX_AUTHOR_LENGTH) << right << setw(8) << year << endl;
}

//------------------------------------------------------------------------------
// operator<
// returns a bool
// Checks to see if this childrens book is less than the one sent in the
// parameter.
// The book in the parameter is cast to childrens book since it already
// checks before coming to this function whether or not the book is a
// childrens book. It then compares the book titles and returns true if this
// is less than the book from the parameter. It then compares the author's
// names if the book has the same title.
// True is returned if this is less than the one in the parameter and false
// if it isn't.
bool ChildrensBook::operator<(const NodeData& bookToCompare) const {
    const ChildrensBook& book = dynamic_cast<const ChildrensBook&>
            (bookToCompare);
    if (bookTitle < book.bookTitle) {
        return true;
    }
    else if (bookTitle == book.bookTitle) {
        if (author < book.author) {
            return true;
        }
    }
    return false;
}

//------------------------------------------------------------------------------
// operator==
// returns a bool
// Checks to see if this childrens book is equal to the one sent in the
// parameter.
// The book in the parameter is cast to childrens book since it already
// checks before coming to this function whether or not the book is a
// childrens book. It then returns true it both of the books' title and
// authors are the same and false if they are not.
bool ChildrensBook::operator==(const NodeData& bookToCompare) const {
    const ChildrensBook& book = dynamic_cast<const ChildrensBook&>
            (bookToCompare);
    return bookTitle == book.bookTitle && author == book.author;
}

//------------------------------------------------------------------------------
// displayData
// Displays book information
// prints out the bookTitle with a max length to make sure that it doesn't
// take too much space, author's name with a max length and year.
void ChildrensBook::displayData() const {
    cout << left << setw(7) << numOfCopiesIn << left << setw(MAX_TITLE_LENGTH
    + 5) << bookTitle.substr(0, MAX_TITLE_LENGTH) <<
    setw(MAX_AUTHOR_LENGTH) << author.substr(0, MAX_AUTHOR_LENGTH) << right
    << setw(8) << year << endl;
}

//------------------------------------------------------------------------------
// displayHeader
// Displays the headers
// prints out the genre books on the first line to inform what kind of genre
// it is printing. Then it prints out "AVAIL" "TITLE" "AUTHOR" and "YEAR"
// evenly above the data to make it look clearer
void ChildrensBook::displayHeader() const {
    cout << genre << " BOOKS" << endl;
    cout << left << setw(7) << "AVAIL" << left << setw(MAX_TITLE_LENGTH + 5) <<
    "TITLE" << setw(MAX_AUTHOR_LENGTH) << 
    "AUTHOR" << right << setw(8) << "YEAR" << endl;
}