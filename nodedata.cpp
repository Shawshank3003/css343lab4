//---------------------------------------------------------------------------
// NODEDATA.CPP
// Class nodedata is the super class that mimics Object (it is all
// encompassing).
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
#include "nodedata.h"

//----------------------------------------------------------------------------
// constructors/destructor  

NodeData::NodeData() { }                         // default

NodeData::~NodeData() { }            // needed so strings are deleted properly

ostream& operator<<(ostream& out, const NodeData& nd) {
    out << "";
    return out;
}

