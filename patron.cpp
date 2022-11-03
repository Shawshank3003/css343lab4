//---------------------------------------------------------------------------
// PATRON.CPP
// Class patron is the subclass of Person and it focuses on the patrons of
// the library.
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "patron.h"
#include "patronAction.h"

//---------------------------------------------------------------------------
// Constructor
// Initializes patronName and patronID
Patron::Patron() {
    patronName = "";
    patronId = 0;
}

//---------------------------------------------------------------------------
// Destructor
// deletes history using a loop
Patron::~Patron() { 
    for (int i = 0; i < (int)history.size(); i++) {
        delete history[i];
        history[i] = nullptr;
    }
}

//---------------------------------------------------------------------------
// setData
// Description: Sets the data for the patron
void Patron::setData(ifstream& infile) {
    infile >> patronId;
    if (infile.eof()) {
        return;
    }
    getline(infile, patronName, '\n');
}

//---------------------------------------------------------------------------
// addCommandToHistory
// Description: Adds a command to the patron's history
void Patron::addCommandToHistory(PatronAction* action) {
    history.push_back(action);
}

//---------------------------------------------------------------------------
// displayHistory
// Description: Displays the patron's history
void Patron::displayHistory() const {
    cout << patronId << " " << patronName << ":" << endl;
    if (!history.empty()) {
        for (int i = 0; i < (int)history.size(); i++) {
            if (history[i] != nullptr) {
                history[i]->display();
            }
        }
        cout << endl;
    }
    else {
        cout << patronName << " does not have a history" << endl;
    }
}

//---------------------------------------------------------------------------
// operator==
// Description: Compares two patrons by their id
// Returns true if the two patrons have the same id
bool Patron::operator==(const Patron& other) const {
    return patronId == other.patronId;
}

//---------------------------------------------------------------------------
// operator!=
// Description: Compares two patrons by their id
// Returns true if the two patrons do not have the same id
bool Patron::operator!=(const Patron& other) const {
    return patronId != other.patronId;
}


//---------------------------------------------------------------------------
// getPatronId
// Description: Returns the patron's id
int Patron::getPatronId() const {
    return patronId;
}

//---------------------------------------------------------------------------
// getFirstName
// Description: Returns the patron's first name
string Patron::getName() const {
    return patronName;
}

//---------------------------------------------------------------------------
// getHistory
// Description: Returns the patron's history
vector<PatronAction*> Patron::getHistory() const {
    return history;
}
