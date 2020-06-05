//---------------------------------------------------------------------------
// SEARCHTREE.CPP
// Member function definitions for class SearchTree
// Author:  Melanie Palomino
// Date: April 16, 2020
//---------------------------------------------------------------------------
// SearchTree class:  Creates a tree that stores Comparable objects that can
//      only be inserted or copied from another tree. This program allows:
//
//   -- removal of a single Comparable occurance
//   -- output of Comparable objects stored
//   -- insertion of a Comparable object ptr
//   -- for comparison of 2 SearchTrees
//   -- for assignment of SearchTree
//   -- to retrieve a Comparable pointer
//   -- to get the height of a node that holds the Comparable object
//
// Assumptions:
//   -- root pointer is a nullptr before being initialized
//   -- in <<, data is displayed in Inorder traversal with their frequencies
//---------------------------------------------------------------------------
#include "SearchTree.h"

#include <string>
#include <iostream>

using namespace std;


//***************** Constructors & Destructors **********************

//-------------------------- Constructor ------------------------------------
// Default constructor for class SearchTree
// Preconditions:   None
// Postconditions:  root pointer is set to null and num of nodes is set to 0
SearchTree::SearchTree(){
    this-> root = nullptr;
    this->Nodenums = 0;
}


//---------------------------- Copy -----------------------------------------
// Copy constructor for class SearchTree
// Preconditions:  Passed tree is not empty and there's enough memory
// Postconditions:  other is copied into *this with the same structure
SearchTree::SearchTree(const SearchTree& other){
    this->Nodenums = other.Nodenums; //same amount of nodes
    //call function to deep copy the tree
    copyHelper(other.root, this->root);
}

//---------------------------- Destructor ----------------------------------
// Destructor for class SearchTree
// Preconditions:   There's something in the heap
// Postconditions: SearchTree is completely deallocated, Nodenums is 0
SearchTree::~SearchTree(){
    makeEmpty();
}
//*************************************************************************

//***************** Overloaded Operators **********************************

//-----------------------------  =  -----------------------------------------
// Overloaded assignment operator
// Preconditions:   right is not empty and there's enough memory
// Postconditions: right is copied into *this. *This is then returned
const SearchTree& SearchTree::operator=(const SearchTree& right){
    //if they are the same then return this
    if(*this == right) {
        return *this;
    }
    this->makeEmpty();
    this->copyHelper(right.root,this->root);
    this->Nodenums = right.Nodenums;
    return *this;
}


//------------------------------  ==  ---------------------------------------
// Determine if two SearchTrees are equal.
// Preconditions:  Right is not empty
// Postconditions:  true is returned if SearchTrees have the same data,
//                  structure and frequencies.
bool SearchTree::operator==(const SearchTree& right) const{
    if(this->Nodenums != right.Nodenums || //these two should be the same
       //compares the height of root
       this->height(*root->dataPtr) != right.height(*right.root->dataPtr)){
        return false;
    }
    return comparingHelper(right.root, this->root);
}

//--------------------------------  !=  -------------------------------------
// Determine if two SearchTrees are not equal.
// Preconditions:  Right is not empty
// Postconditions:  true is returned if SearchTrees don't have the same data,
//                 structure and frequencies.
bool SearchTree::operator!=(const SearchTree& right) const{
    return !comparingHelper(right.root, this->root);
}

//*****************************************************************************

//***************** Operator Helper Methods*************************************

//--------------------------- copyHelper --------------------------------------
// Copies otherRoot into thisRoot
// Preconditions:   Nodes are not nullptrs and there's enough memory
// Postconditions:  thisRoot is exactly like otherRoot.
void SearchTree::copyHelper(Node* otherRoot, Node* &thisRoot) const{
    //check if other tree's root is  null
    if(otherRoot != nullptr){
        thisRoot->leftPtr = nullptr;
        thisRoot->rightPtr = nullptr;
        thisRoot->frequency = 0;
        //Preorder copying
        thisRoot = new Node(); //initialize root
        thisRoot->dataPtr = otherRoot->dataPtr; //copies values of data
        *thisRoot->dataPtr = *otherRoot->dataPtr;
        thisRoot->frequency = otherRoot->frequency;
        copyHelper(otherRoot->leftPtr, thisRoot->leftPtr);
        copyHelper(otherRoot->rightPtr, thisRoot->rightPtr);
    }
    else {
        thisRoot = nullptr;
    }
}

//------------------------- comparingHelper ------------------------------------
// Compares two SearchTree Objects
// Preconditions:   otherRoot and thisRoot are comparable
// Postconditions: Return true is trees have the same structure, data, and
//            frequency. Otherwise, returns false.
bool SearchTree::comparingHelper(Node* otherRoot,Node* thisRoot) const {

    //check if they are empty
    if(otherRoot == nullptr && thisRoot == nullptr){
        return true;
    }
    if (otherRoot == nullptr || thisRoot == nullptr){
        return false;
    }

    //check if data in Inventory is the same
    if(*otherRoot->dataPtr != *thisRoot->dataPtr){
        return false;
    }

    if( otherRoot->frequency != thisRoot->frequency){
        return false;
    }

    return comparingHelper(otherRoot->leftPtr, thisRoot->leftPtr) &&
           comparingHelper(otherRoot->rightPtr, thisRoot->rightPtr);

}

//****************************************************************************

//****************** Insert and Helper ****************************************

//--------------------------------  Insert  -----------------------------------
// Inserts a Comparable item into SearchTree.
// Preconditions:  Comparable is not a nullptr.
// Postconditions:  true is returned if Object is stored for the first time.
//          Returns false if item already existed
bool SearchTree::insert(Inventory* newItem){
    if(root == nullptr){
        this->root = new Node;
        this->Nodenums++;
        this->root->dataPtr = newItem; //copy address so it points to same data
        this->root->rightPtr = this->root->leftPtr = nullptr;
        root->frequency = 1;
        return true;
    }
    return insertHelper(this->root, newItem);
}

//---------------------------- Insert  Helper ---------------------------------
// Recursively inserts a Comparable item into SearchTree.
// Preconditions:  Comparable and curr are not a nullptrs.
// Postconditions:  true is returned if Object is stored for the first time.
//          Returns false if item already existed.
bool SearchTree::insertHelper(Node *curr, Inventory *newItem) {
    //base case for addition
    if(*curr->dataPtr == *newItem){
        curr->frequency++;
        return true;
    }

    if(*newItem > *curr->dataPtr){
        if(curr->rightPtr == nullptr){
            Node *newNode = new Node;
            newNode->dataPtr = newItem;
            curr->rightPtr = newNode;
            curr->rightPtr->frequency++;
            Nodenums++;
            return true;
        }
        return insertHelper(curr->rightPtr,newItem);
    }
    else{
        //base case
        if(curr->leftPtr == nullptr){
            Node *newNode = new Node;
            newNode->dataPtr = newItem;
            curr->leftPtr = newNode;
            curr->leftPtr->frequency++;
            Nodenums++;
            return true;
        }
        return insertHelper(curr->leftPtr,newItem);
    }


    return false;
}

//*************************************************************************

//******************Remove and Helper *************************************

//---------------------------- Remove -------------------------------------
// Removes an occurance of a Comparable item in SearchTree.
// Preconditions:  Comparable is not empty.
// Postconditions: True is returned if occurrence is removed. False if
//              item is not in Searchtree.
bool SearchTree::remove(const Inventory& item){
    return removeRecursive(this->root, item);
}

//---------------------------Remove Recursive ---------------------------------
// Recursively removes an occurance of a Comparable item in SearchTree.
// Preconditions:  Comparable is not empty and curr is not a nullptr.
// Postconditions: True is returned if occurrence is removed. False if
//              item is not in Searchtree.
bool SearchTree::removeRecursive(Node*& curr, const Inventory& item){
    if(curr != nullptr){
        //base case
        if(item == *curr->dataPtr){
            if(curr->frequency > 1){
                curr->frequency--;
            }
            else{
                //  deleteNode(curr);
                return false;
            }
            return true;
        }
        if(item > *curr->dataPtr){
            return removeRecursive(curr->rightPtr,item);
        }
        else {
            return removeRecursive(curr->leftPtr,item);
        }
    }
    return false;
}

//-------------------------- DeleteNode -------------------------------------
// Checks if curr has any children to delete appropriately .
// Preconditions:  Curr is not a nullptr.
// Postconditions: Old data ptr is deleted and set to smallest item.
void SearchTree::deleteNode(Node*& curr) {
    delete curr->dataPtr;
    curr->dataPtr = nullptr;
    //if it has no children
    if(curr->leftPtr == nullptr && curr->rightPtr == nullptr){
        delete curr;
        curr = nullptr;
        Nodenums--;
    }
    else if(curr->leftPtr == nullptr || curr->rightPtr == nullptr){
        Node* temp = curr;
        curr = curr->leftPtr == nullptr? curr->rightPtr : curr->leftPtr;
        delete temp;
        //temp = nullptr;
        Nodenums--;
    }
    else{
        curr->dataPtr = replaceWithSmallest(curr);
    }

}

//--------------------------replaceWithSmallest-----------------------------
// Goes to the smallest value, deletes node, and returns data
// Preconditions:  Curr is not a nullptr.
// Postconditions: Node is delete and smallest item is returned.
Inventory* SearchTree::replaceWithSmallest(Node *&curr) {
    if(curr->leftPtr == nullptr){
        Inventory* item = curr->dataPtr;
        curr->frequency = curr->rightPtr->frequency;
        Node* temp = curr;
        curr = curr->rightPtr;
        delete temp;
        //temp = nullptr;
        Nodenums--;
        return item;
    }
    else{
        return replaceWithSmallest(curr->leftPtr);
    }
}

//************************ Destructor Helpers**************************

//--------------------------MakeEmpty----------------------------------
// Removes and deallocates memory.
// Preconditions: None.
// Postconditions: Everything is deleted and memory is free again.
void SearchTree::makeEmpty() {
    clear(this->root);
    this->root = nullptr;
}

//--------------------------Clear----------------------------------
// Removes and deallocates memory.
// Preconditions: None.
// Postconditions: Everything is deleted and memory is free again.
void SearchTree::clear(Node *curr) {
    if(curr != nullptr){
        clear(curr->leftPtr);
        clear(curr->rightPtr);
        delete curr->dataPtr;
        curr->dataPtr = nullptr;
        delete curr;
    }
}
//*****************************************************************************


//*******************Retrieve and Helper *************************************

//-------------------------Retrieve ----------------------------------
// Retrieves Comparable pointer stored in the Node that contains
// the Comparable item.
// Preconditions: None.
// Postconditions: Comparable pointer is returned.
const Inventory* SearchTree::retrieve(const Inventory& item) const{
    if(this->root != nullptr){
        return retrieveHelper(this->root, item);
    }
    return nullptr;
}

//-------------------------Retrieve Helper ------------------------------
// Retrieves Comparable pointer stored in the Node that contains
// the Comparable item.
// Preconditions: None
// Postconditions: Comparable pointer is returned.
const Inventory* SearchTree::retrieveHelper(Node *curr, const Inventory &item) const{
    if(curr == nullptr){
        return nullptr;
    }
    if(*curr->dataPtr == item){
        return curr->dataPtr;
    }
    if(item > *curr->dataPtr){
        return retrieveHelper(curr->rightPtr,item);
    }
    else{
        return retrieveHelper(curr->leftPtr,item);
    }
}


//***************** Height & Helper methods*************************************

//------------------------  height ----------------------------------------
// Gives the height of Node where item is located at.
// Preconditions:  None
// Postconditions: The heigh of the node where item is located at is returned.
//               If not found, -1 is returned.
int SearchTree::height(const Inventory& item) const{
    //check if in tree first
    if(this->retrieve(item) == nullptr){
        return -1;
    }
    if(this->root != nullptr){
        Node* locatedPtr;
        this->positionFinder(locatedPtr,this->root,item);
        if(locatedPtr != nullptr){
            return heightAddition(locatedPtr) - 1;
        }
        //not neccessary but just in case
        return -1;
    }
    return -1;
}

//---------------------- positionFinder --------------------------------------
// Finds the position of where the item is located at
// Preconditions:   Tree is not empty
// Postconditions:  newPtr is set with position if item is in the tree.
void SearchTree::positionFinder(Node*& newPtr,Node* curr, const Inventory &item) const {
    if(*curr->dataPtr == item){
        newPtr = curr;
    }
    else if(*curr->dataPtr > item){
        positionFinder(newPtr,curr->leftPtr,item);
    }
    else if(item > *curr->dataPtr) {
        positionFinder(newPtr,curr->rightPtr, item);
    }
    else{
        newPtr = nullptr;
    }

}

//------------------------heightAddition --------------------------------------
// Adds the number of children node each side has
// Preconditions:   Tree is not empty
// Postconditions:  Max total of children nodes is returned; if leaf then it is 0.
int SearchTree::heightAddition(Node* curr) const{
    //if it's a leaf
    if(curr != nullptr){
        int l = heightAddition(curr->leftPtr);
        int r = heightAddition(curr->rightPtr);
        return 1 + max(l,r);
    }
    return 0;
}

//******************************************************************************


//***************** getCount & Helper method*************************************

//------------------------ getCount ----------------------------------------
// Returns the frequency of located item
// Preconditions:  Item is not null
// Postconditions: The item's frequency is returned.
int SearchTree::getCount(const Inventory& item) const{
    return getCountRecursive(item, this->root);
}

//------------------------ getCountRecursive --------------------------------------
// Returns the frequency of located item
// Preconditions:  Item is not null
// Postconditions: The item's frequency is returned.
int SearchTree::getCountRecursive(const Inventory& item, const Node* curr) const{
    if(curr == nullptr){
        return -1;
    }
    if(*curr->dataPtr == item){
        return curr->frequency;
    }
    if(item > *curr->dataPtr){
        return getCountRecursive(item, curr->rightPtr);
    }
    else{
        return getCountRecursive(item, curr->leftPtr);
    }
}

//******************************************************************************






//***************** Output & Helper methods*************************************

//--------------------------- displayHelper --------------------------------------
// Overloaded output operator for class Binary; outputs binary number
// Preconditions:   curr is not a nullptr.
// Postconditions:  Data is displayed with frequency
void SearchTree::displayHelper(ostream &output,Node *curr) const {
    if(curr != nullptr){
        displayHelper(output,curr->leftPtr);
        output << *curr->dataPtr << endl;
        displayHelper(output,curr->rightPtr);
    }
}



//-----------------------------  <<  ----------------------------------------
// Overloaded output operator for class SearchTree.
// Preconditions:  st is not empty.
// Postconditions: SearchTree data is displayed in Inorder traversal.
ostream& operator<<(ostream& output, const SearchTree& st){
    //return st.displaying(output, st.root);
    st.displayHelper(output,st.root);
    return output;
}

//----------------------------displaying ---------------------------------------
// Overloaded output operator for class Binary; outputs binary number
// Preconditions:   curr is not a nullptr.
// Postconditions:  Data is displayed with frequency
/*
ostream& SearchTree::displaying(ostream &output, Node* curr) {
    if(curr != nullptr){
        displaying(output,curr->leftPtr);
        output << *curr->dataPtr << " "  << curr->frequency << endl;
        displaying(output,curr->rightPtr);
    }
    return output;
}
*/
//******************************************************************************