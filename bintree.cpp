//---------------------------------------------------------------------------
// BINTREE.H
// Class bintree creates a binary tree
// Author: Shashank Chennapragada, Abood Vakil
//---------------------------------------------------------------------------

#include "bintree.h"

//----------------------------------------------------------------------------
// Default Constructor
// No parameters. Creates an empty tree.
BinTree::BinTree() {
    root = nullptr;
}

//----------------------------------------------------------------------------
// Destructor
// Deletes all nodes in the tree.
BinTree::~BinTree() {
	makeEmpty();
}

//----------------------------------------------------------------------------
// isEmpty
// @return true if the tree is empty, false otherwise.
// Checks if the tree is empty by checking if the root is nullptr.
bool BinTree::isEmpty() const {
	return root == nullptr;
}

//----------------------------------------------------------------------------
// makeEmpty
// Deletes all nodes in the tree. Calls the recursive emptyTreeHelper
// function. emptyTreeHelper recursively traverses the tree and deletes
// the data in each node, as well as the node itself.
void BinTree::makeEmpty() {
	Node * current = root;
	if (current != nullptr) {  
		emptyTreeHelper(current);
	}
}

void BinTree::emptyTreeHelper(Node * current) { 
	if (current != nullptr) {
		emptyTreeHelper(current->left);
		emptyTreeHelper(current->right);

		delete current->data;
		current->data = nullptr;
		delete current;
		current = nullptr;
	}
	root = nullptr;
}

//----------------------------------------------------------------------------
// insert
// @param dataItemToAdd: The data to insert into the tree.
// If parameter exists in tree, returns false. Else, inserts the data into 
// the tree. Iteratively traverses the tree to find the correct location. 
// If the data is successfully inserted, returns true. Else, returns false. 
bool BinTree::insert(NodeData * dataItemToAdd) {
    Node* ptr = new Node;     // exception is thrown if memory is not allocated
    ptr->data = dataItemToAdd;
    dataItemToAdd = nullptr;
    ptr->left = ptr->right = nullptr;
    if (isEmpty()) {
        root = ptr;
    }
    else {
        Node* current = root;
        bool inserted = false;

        // if item is less than current item, insert in left subtree,
        // otherwise insert in right subtree
        while (!inserted) {
            if (*ptr->data == *current->data) { 
                delete ptr;
                ptr = nullptr;
                return false;
            }
            if (*ptr->data < *current->data) {
            if (current->left == nullptr) {           // at leaf, insert left
                current->left = ptr;
                inserted = true;
            }
            else
                current = current->left;               // one step left
            }
            else {
            if (current->right == nullptr) {          // at leaf, insert right
                current->right = ptr;
                inserted = true;
            }
            else
                current = current->right;              // one step right
            }
        }
    }
    return true;
}

//----------------------------------------------------------------------------
// retrieve
// @param dataToRetrieve: The data to search for and retrieve from tree
// @param result: The data that was retrieved from the tree. Initially is 
// trash, but will be set to the data if it is found.
// @return true if the data was found, false otherwise.
// Calls recursive helper retrieveHelper. retrieveHelper recursively traverses
// the tree to find the data. If the data is less than the data in the current
// node, it traverses the left subtree. If the data is greater than the data
// in the current node, it traverses the right subtree. If the data is found,
// the data is assigned to the third parameter of the helper function.
bool BinTree::retrieve(const NodeData &dataToRetrieve, NodeData *& result)
						const {
	Node * curr = root;
	if (curr != nullptr) {
		retrieveHelper(curr, dataToRetrieve, result);
	} else {
		return false;
    }
	if (result != nullptr) {
		return true;
	} else {
		return false;
    }
}

void BinTree::retrieveHelper(Node * curr, const NodeData & dataToRetrieve,
							  NodeData *& result) const {
	if (curr == nullptr){
		result = nullptr;
	} else if (*curr->data == dataToRetrieve) { 
		result = curr->data;
	} else if (dataToRetrieve < *curr->data) {
		retrieveHelper(curr->left, dataToRetrieve, result);
	} else {
		retrieveHelper(curr->right, dataToRetrieve, result);
	}
}

//----------------------------------------------------------------------------
// displaySideways
// Displays a binary tree as though you are viewing it from the side.
// Turn head 90 degrees counterclockwise (to the left) to see tree structure.
// Hard coded displaying to standard output.
void BinTree::displaySideways() const {
   sidewaysHelper(root, 0);
}

void BinTree::sidewaysHelper(Node* current, int level) const {
   if (current != nullptr) {
      level++;
      sidewaysHelper(current->right, level);

      // indent for readability, same number of spaces per depth level 
      for(int i = level; i >= 0; i--) {
          cout << "      ";
      }

      cout << *current->data << endl;        // display information of object
      sidewaysHelper(current->left, level);
   }
}

//----------------------------------------------------------------------------
// getSibling
// @param dataToFind: The data to search for, and retrieve the sibling of.
// @param result: The data that was retrieved from the tree. Initially is
// trash, but will be set to the data if it is found.
// @return true if the sibling was found, false otherwise.
// Calls recursive helper getSiblingHelper. getSiblingHelper recursively
// traverses the tree to find the data. If the data is found, and it's sibling
// exists, the data is assigned to the third parameter of the helper function.
bool BinTree::getSibling(const NodeData &dataToFind, NodeData & result) const {
    Node * curr = root;
    return siblingHelper(curr, dataToFind, result);
}

bool BinTree::siblingHelper(Node * node, const NodeData & dataToFind, 
                            NodeData & result) const{
    if (node == nullptr) { 
        return false;
    }
    if (node->left != nullptr && *node->left->data == dataToFind) {
        if (node->right != nullptr) { 
            result = *node->right->data;
            return true;
        }
        return false;
    } else if (node->right != nullptr && *node->right->data == dataToFind) { 
        if (node->left != nullptr) { 
            result = *node->left->data;
            return true;
        }
        return false;
    }
    return (siblingHelper(node->left, dataToFind, result) || 
        siblingHelper(node->right, dataToFind, result));
}

//----------------------------------------------------------------------------
// getParent
// @param dataToFind: The data to search for, and retrieve the parent of.
// @param result: The data that was retrieved from the tree. Initially is
// trash, but will be set to the data if it is found.
// @return true if the parent was found, false otherwise.
// Calls recursive helper getParentHelper. getParentHelper recursively
// traverses the tree to find the data. If the data is found, it's parent
// is assigned to the third parameter of the helper function.
bool BinTree::getParent(const NodeData &dataToFind, NodeData & result) const {
    Node * curr = root;
    return parentHelper(curr, dataToFind, result);
}

bool BinTree::parentHelper(Node * node, const NodeData & dataToFind, 
                            NodeData & result) const { 
    if (node == nullptr) { 
        return false;
    }
    if (node->left != nullptr && *node->left->data == dataToFind) { 
        result = *node->data;
        return true;
    }
    if (node->right != nullptr && *node->right->data == dataToFind) { 
        result = *node->data;
        return true;
    }
    return (parentHelper(node->left, dataToFind, result) ||
        parentHelper(node->right, dataToFind, result));
}

//----------------------------------------------------------------------------
// bstreeToArray
// @param bstArray: The array to store the tree's data in.
// Calls the recursive helper bstreeToArrayHelper. bstreeToArrayHelper
// recursively traverses the tree and stores the data in the array.
void BinTree::bstreeToArray(NodeData* bstArray[]) {
	int i = 0;
	bstreeToArrayHelper(this->root, bstArray, i);
	emptyTreeHelper(this->root);
} 

void BinTree::bstreeToArrayHelper(Node * curr, NodeData* bstArray[],
							int& i) {
	if (curr != nullptr) {
		bstreeToArrayHelper(curr->left, bstArray, i);
        bstArray[i] = curr->data;
        curr->data = nullptr;
        i++;
		bstreeToArrayHelper(curr->right, bstArray, i);
	}
}

//----------------------------------------------------------------------------
// arrayToBSTree
// @param array: array of NodeData pointers to be used to create a new tree.
// Calls the recursive helper arrayToBSTreeHelper. arrayToBSTreeHelper uses 
// binary search to find the correct place to insert the data into the array.
void BinTree::arrayToBSTree(NodeData* array[]) {
	int high = 0;
	int low = 0;
	for (int i = 0; i < 100; i++) {
		if (array[i] != nullptr) {
			high++;
        } else {
            continue;
        }
	}
	if (isEmpty()) {
	    arrayToBSTreeHelper(this->root, array, low, high-1);
	} else {
		emptyTreeHelper(this->root);
		arrayToBSTreeHelper(this->root, array, low, high-1);
	}
} 

void BinTree::arrayToBSTreeHelper(Node *& curr, NodeData * array[],
								  int low, int high) {
	if (low > high) {
		curr = nullptr;
	} else {
		int binaryIndex = (low + high) / 2;
        NodeData* temp;
        temp = array[binaryIndex];
        array[binaryIndex] = nullptr;
        insert(temp);
        arrayToBSTreeHelper(curr->left, array, low, binaryIndex - 1 );
        arrayToBSTreeHelper(curr->right, array, binaryIndex + 1, high);
	}
}

//----------------------------------------------------------------------------
// operator<<
// @param output: The output stream to write to.
// @param treeToPrint: The tree to write to the output stream.
// Prints the tree inorder. If the tree is empty, prints "tree is empty".
// Calls recursive helper inorderHelper. inorderHelper recursively traverses
// the tree and prints the data inorder.
ostream& operator<<(ostream& output, const BinTree& treeToPrint) {
	if (treeToPrint.isEmpty()){
		output << "NO ITEMS IN THIS GENRE" << endl;
	} else {
        treeToPrint.root->data->displayHeader();
        treeToPrint.inorderHelper(treeToPrint.root);
        output << endl;
	}
	return output;
}

void BinTree::inorderHelper(Node* curr) const {
	if (curr != nullptr) {
        inorderHelper(curr->left);
        curr->data->displayData();
        inorderHelper(curr->right);
	}
}

/*
//----------------------------------------------------------------------------
// operator=
// @param treeToDeepCopy: The tree to assign to this tree.
// @return: A reference to this tree.
// Calls recursive helper copyTreeHelper. 
BinTree& BinTree::operator=(const BinTree &treeToDeepCopy) {
	if (*this != treeToDeepCopy) {
		emptyTreeHelper(root);
		copyTreeHelper(treeToDeepCopy.root, root);
	}
	return *this;
}	
*/
//----------------------------------------------------------------------------
// operator==
// @param treeToCompare: The tree to compare to this tree.
// @return: true if the trees are equal, false otherwise.
// Calls recursive helper equalityHelper. equalityHelper recursively traverses
// the tree and compares the data to see if they are equal.
bool BinTree::operator==(const BinTree &treeToCompare) const {
	Node * leftRoot = this->root; 
    Node * rightRoot = treeToCompare.root;
	if (leftRoot == nullptr && rightRoot == nullptr) {
		return true;
    } else {
		return equalityHelper(leftRoot, rightRoot);
    }
}

bool BinTree::equalityHelper(Node * leftNode, Node * rightNode) const {
	if ((leftNode != nullptr && rightNode != nullptr) && 
		(*leftNode->data == *rightNode->data)) {
		return true;
    }

	if ((leftNode == nullptr) || (rightNode == nullptr)) {
		return false;
    }

	return ((*leftNode->data == *rightNode->data) &&
		equalityHelper(leftNode->left, rightNode->left) &&
		equalityHelper(leftNode->right, rightNode->right));
}

//----------------------------------------------------------------------------
// operator!=
// @param treeToCompare: The tree to compare to this tree.
// @return: true if the trees are not equal, false otherwise.
bool BinTree::operator!=(const BinTree &treeToCompare) const {
	return !(*this == treeToCompare);
}
