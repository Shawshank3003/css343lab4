//---------------------------------------------------------------------------
// BINTREE.H
// Class bintree creates a binary tree
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------
// bintree class:
//      A rooted binary tree data structure. Each node has a left and right
//      child, and a data item. Each node store data that is greater than all
//      data in the left subtree and less than all data in the right subtree.
// Implementation and Assumptions:
//      -- The data in each node is unique.
//      -- Implemented using pointers to nodes.
//      -- NodeData class is already fully implemented
//---------------------------------------------------------------------------

#ifndef _BINTREE_H_
#define _BINTREE_H_

#include <iostream>
#include "nodedata.h"

using namespace std;


class BinTree {
   // overloaded << operator: prints out the tree inorder. (calls recursive
   // inorderHelper method.) If tree is empty: prints out "tree is empty"
   friend ostream& operator<<(ostream&, const BinTree&);

public:
    // default constructor: no parameters, constructs an empty tree
	BinTree();

    // destructor: empties and deallocates the tree	
	~BinTree();						

    // public member functions for the BinTree class
	bool isEmpty() const;  // returns true if tree is empty, false otherwise.	
	void makeEmpty();	   // empties and deallocates the tree.  
    bool insert(NodeData *);  // inserts a data item into the tree. 
                              // returns true if successful, false otherwise.
    bool retrieve(const NodeData &, 
                NodeData *&) const;  // retrieves the data item from the tree, 
                                     // assigns to second parameter if exists.
	void displaySideways() const;  // displays a sideways representation of the
                                   // tree.
    bool getSibling(const NodeData &, 
                NodeData &) const;  // retrieves the sibling of the data item.
                                    // returns true if successful, false 
                                    // otherwise.
    bool getParent(const NodeData &, 
                NodeData &) const;  // retrieves the parent of the data item. 
                                    // returns true if successful, false 
                                    // otherwise.
	void bstreeToArray(NodeData* []);  // converts the tree to an array.   
    void arrayToBSTree(NodeData* []);  // converts the array to a tree.
	

    // assignment operator: one parameter, assigns the parameter to the tree
	//BinTree& operator=(const BinTree &);		
	
    // boolean comparison operators
	bool operator==(const BinTree &) const;   // is object == parameter?
	bool operator!=(const BinTree &) const;   // is object != parameter?

private:
	struct Node{
		NodeData * data;   // pointer to data object		
		Node * left;       // left subtree pointer		
		Node * right;	   // right subtree pointer
	};

	Node * root;	       // pointer to root node of tree			


    // private member functions for the BinTree class (all recursive helpers)
    void inorderHelper(Node*) const;  // recursive inorder traversal helper
    void emptyTreeHelper(Node*);   // recursive emptyTree helper for 
                                   // destructor and makeEmpty
    void retrieveHelper(Node*, const NodeData &, 
                    NodeData*&) const;  // recursive retrieve helper for
                                        // retrieve
	void sidewaysHelper(Node* current, 
                    int level) const;   // recursive sideways helper for 
                                        // displaySideways  
    bool siblingHelper(Node*, const NodeData &, 
                    NodeData&) const;   // recursive sibling helper for 
                                        // getSibling   	
    bool parentHelper(Node*, const NodeData &, 
                    NodeData&) const;   // recursive parent helper for
                                        // getParent
	void bstreeToArrayHelper(Node * , NodeData* [],
                         int&);   // recursive bstreeToArray helper for 
                                  // bstreeToArray 
	void arrayToBSTreeHelper(Node *& , NodeData * [], 
                        int , int);   // recursive arrayToBSTree helper for
                                      // arrayToBSTree 
	bool equalityHelper(Node*, Node*) const; // recursive equality checker 
                                            // for == operator
};

#endif