//---------------------------------------------------------------------------
// BOOK.H
// Class Book represents a book
// Author: Shashank Chennapragada, Abood Vakil, Khushaal Kurswani
//---------------------------------------------------------------------------
#include "book.h"
using namespace std;

//----------------------------------------------------------------------------
// Default Constructor
// Initialize the year, bookTitle and bookFormat
Book::Book() {
    year = 0;
    bookTitle = "";
    genre = "";
    bookFormat = 'H';
}

//----------------------------------------------------------------------------
// Destructor
Book::~Book() {
    // nothing to do
}

//----------------------------------------------------------------------------
// getYear
// returns the year of the book
int Book::getYear() const{
    return year;
}

//----------------------------------------------------------------------------
// getTitle
// returns the title of the book
string Book::getBookTitle() const{
    return bookTitle;
}

//----------------------------------------------------------------------------
// getBookFormat
// returns the format of the book
string Book::getBookFormat() const{
    return bookFormat;
}


