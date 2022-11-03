//---------------------------------------------------------------------------
// FICTION.CPP
// Class Fiction represents the fiction genre of a book
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "fiction.h"

//---------------------------------------------------------------------------
// Constructor
Fiction::Fiction() {
    author = "";
    genre = "FICTION";
    bookTitle = "";
    year = 0;
    bookFormat = 'H';
    totalCopies = 5;
    numOfCopiesIn = 5;
}

//---------------------------------------------------------------------------
// Destructor
Fiction::~Fiction() { }

//---------------------------------------------------------------------------
// create()
// Creates a fiction book object
Item* Fiction::create() const{
    return new Fiction();
}

void Fiction::setData(ifstream& infile) {
    infile.get();
    getline(infile, author, ',');

    infile.get();
    getline(infile, bookTitle, ',');

    infile.get();
    infile >> year;
}

//---------------------------------------------------------------------------
// setCommandData()
void Fiction::setCommandData(ifstream& inFile) {
    inFile.get();
    inFile >> bookFormat;
    
    inFile.get();
    getline(inFile, author, ',');

    inFile.get();
    getline(inFile, bookTitle, ',');
}

//------------------------------------------------------------------------------
// display
// Displays the data of the ChildrensBook object
void Fiction::display() const {
    cout << left << setw(MAX_AUTHOR_LENGTH + 2) 
    << author.substr(0, MAX_AUTHOR_LENGTH) << setw(MAX_TITLE_LENGTH + 2) << 
    bookTitle.substr(0, MAX_TITLE_LENGTH) << right << setw(8) << year
    << endl;
}

//---------------------------------------------------------------------------
// operator<
// Overloaded less than operator
bool Fiction::operator<(const NodeData& bookToCompare) const {
    const Fiction& book = dynamic_cast<const Fiction&>(bookToCompare);
    if (author < book.author) {
        return true;
    }
    else if (author == book.author) {
        if (bookTitle < book.bookTitle) {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------
// operator==
// Overloaded equality operator
bool Fiction::operator==(const NodeData& bookToCompare) const {
    const Fiction& book = dynamic_cast<const Fiction&>(bookToCompare);
    return author == book.author && bookTitle == book.bookTitle;
}

//------------------------------------------------------------------------------
// displayData
// Displays book information
// prints out the number of copies in the library, the author name, the book
// title, and the year.
void Fiction::displayData() const {
    cout << left << setw(7) << numOfCopiesIn << left << setw(MAX_AUTHOR_LENGTH)
    << author.substr(0, MAX_AUTHOR_LENGTH) << setw(MAX_TITLE_LENGTH + 5) <<
    bookTitle.substr(0, MAX_TITLE_LENGTH) << right << setw(8) << year
    << endl;
}

//------------------------------------------------------------------------------
// displayHeader
// Displays the headers
// prints out the genre books on the first line to inform what kind of genre
// it is printing. Then it prints out "AVAIL" "AUTHOR" "TITLE" and "YEAR"
// evenly above the data to make it look clearer
void Fiction::displayHeader() const {
    cout << genre << " BOOKS" << endl;
    cout << left << setw(7) << "AVAIL" << left << setw(MAX_AUTHOR_LENGTH) <<
    "AUTHOR" << setw(MAX_TITLE_LENGTH + 5) << 
    "TITLE" << right << setw(8) << "YEAR" << endl;
}