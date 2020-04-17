//
// Created by Melanie Palomino on 4/14/20.
//

#include "SearchTree.h"

#include <string>
#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

//***************** Constructors & Destructors **********************

//default constructor
SearchTree::SearchTree(){
    this-> root = nullptr;
}

SearchTree::SearchTree(const SearchTree& st){
    this->Nodenums = st.Nodenums; //same amount of nodes
    //must initialize root
    copyHelper(st.root, this->root);
    //call overload operator to deep copy the tree

}


SearchTree::~SearchTree(){
    makeEmpty();
}
//*********************************************************************

//***************** Overloaded Operators ******************************
const SearchTree& SearchTree::operator=(const SearchTree& right){
    //if they are the same then return this
    if(right != *this){
        //delete everything on tree
        //this->makeEmpty();
        copyHelper(right.root, this->root);
    }
    return *this;
}

//two trees are equal only if they have the same data, the same structure,
// and the same number of occurrences for each comparable
bool SearchTree::operator==(const SearchTree& right) const{
    if(this->Nodenums != right.Nodenums || //these two should be the same
        //compares the height of root
        this->height(*root->dataPtr) != right.height(*right.root->dataPtr)){
        return false;
    }
    return comparingHelper(right.root, this->root);
}

//checks if Trees are not equal
bool SearchTree::operator!=(const SearchTree& right) const{
    if(this->Nodenums != right.Nodenums || //these two should be the same
       //compares the height of root
       this->height(*root->dataPtr) != right.height(*right.root->dataPtr)){
        return true;
    }
    return !comparingHelper(right.root, this->root);
}

//********************************************************************************

//******************* Mutator Functions ****************************************

//inserts a Comparable into the tree or increments the count if it is already in the tree.
// This method should return false if the Comparable is found (and, thus, not inserted).
// Ownership of the memory is transferred to the tree only if the object is not found in
// the tree (in which case it must later be deallocated by the tree).
bool SearchTree::insert(Comparable* newItem){
    if(isEmpty()){
        this->root = new Node;
        this->Nodenums++;
        this->root->dataPtr = newItem; //copy address so it points to same data
        return true;
    }
    return insertHelper(this->root, newItem);
}

//removes one occurrence of a Comparable from the tree. If it is the last occurrence,
// remove the node. Return false if the Comparable is not found.
bool SearchTree::remove(const Comparable& item){
    if(*this->root->dataPtr == item){
        if(this->root->frequency == 1 ) {
            this->root->frequency--;
            if (this->root->rightPtr != nullptr || this->root->leftPtr != nullptr) {
                //create recursive for remove
            }
            this->root->dataPtr == nullptr;

        }
    }
    return false;
}

//removes and deallocates all of the data from the tree.
void SearchTree::makeEmpty() {
    clear(this->root);
}

void SearchTree::clear(Node *curr) {
        if(curr != nullptr){
            clear(curr->leftPtr);
            clear(curr->rightPtr);
            curr->dataPtr = nullptr;
            //delete curr->dataPtr; //is this necessary since it is not in the heap
            delete curr;
        }
}
//*****************************************************************************

//******************* Mutator Functions ****************************************

//inds a Comparable in the tree using a key stored in the parameter.
// This is useful for cases where the Comparable stores more than the sorting key.
// Return nullptr if not found.
const Comparable* SearchTree::retrieve(const Comparable& item) const{
    if(isEmpty()){
        return nullptr;
    }
    return retrieveHelper(this->root, item);
}

// returns the height of the node storing the Comparable in the tree.
// A leaf has height 0. Return -1 if the Comparable is not found.
int SearchTree::height(const Comparable& comp) const{}

//******************************************************************************

//***************** Private Helper methods*************************************

bool SearchTree::insertHelper(Node *curr, Comparable *newItem) {
    //base case for addition
    if(*curr->dataPtr == *newItem){
        curr->frequency++;
        return false;
    }
    if(*newItem < *curr->dataPtr){
        //base case
        if(curr->leftPtr == nullptr){
            Node *newNode = new Node;
            newNode->dataPtr = newItem;
            curr->leftPtr = newNode;
            Nodenums++;
            return true;
        }
        return insertHelper(curr->leftPtr,newItem);
    }
    if(*newItem > *curr->dataPtr){
        if(curr->rightPtr == nullptr){
            Node *newNode = new Node;
            newNode->dataPtr = newItem;
            curr->rightPtr = newNode;
            Nodenums++;
            return true;
        }
        return insertHelper(curr->rightPtr,newItem);
    }
}

//check if tree is empty
bool SearchTree::isEmpty() const {
    return this->root == nullptr;
}

//copies other tree from root to leaf Preorder traversal
void SearchTree::copyHelper(Node* otherRoot, Node* &thisRoot){
    //check if other tree's root is  null
    if(otherRoot == nullptr){
        thisRoot = nullptr;
    }
    else{
        //Preorder copying
        thisRoot = new Node(); //initialize root
        this->Nodenums++; //increase num everytime a Node is created
        *thisRoot->dataPtr = *otherRoot->dataPtr; //copies values of data
        copyHelper(otherRoot->leftPtr, thisRoot->leftPtr);
        copyHelper(otherRoot->rightPtr, thisRoot->rightPtr);
    }
}

//comparing method helper
bool SearchTree::comparingHelper(Node* otherRoot,Node* thisRoot) const {
    //check if they are empty
    if(otherRoot == nullptr && thisRoot == nullptr){
        return true;
    }
    if ((otherRoot != nullptr && thisRoot == nullptr) ||
            (otherRoot == nullptr && thisRoot != nullptr)){
        return false;
    }
    //check if data in comparable is the same
    if(*otherRoot->dataPtr != *thisRoot->dataPtr){
        return false;
    }

    return comparingHelper(otherRoot->leftPtr, thisRoot->leftPtr) &&
            comparingHelper(otherRoot->rightPtr, thisRoot->rightPtr);

}

//helpr retrieve Comprable pointer
const Comparable* SearchTree::retrieveHelper(Node *curr, const Comparable &item) const{
    if(curr != nullptr){
        //base case
        if(*curr->dataPtr == item){
            return curr->dataPtr;
        }
        if(*curr->dataPtr > item){
            curr = curr->rightPtr;
            return retrieveHelper(curr, item);
        }
        if(*curr->dataPtr < item){
            curr = curr->leftPtr;
            return retrieveHelper(curr, item);
        }
    }
    return nullptr;
}

//displaying trial
ostream& SearchTree::displaying(ostream &output, Node* curr) {
    if(curr != nullptr){
        displaying(output,curr->leftPtr);
        output << *curr->dataPtr << " "  << curr->frequency;
        displaying(output,curr->rightPtr);
    }
    return output;
}

//display helper
void SearchTree::displayHelper(ostream &output,Node *curr) {
    if(curr != nullptr){
        displaying(output,curr->leftPtr);
        output << *curr->dataPtr << " "  << curr->frequency;
        displaying(output,curr->rightPtr);
    }
}
//*********************************************************************

//output the frequency table in sorted order.
// This should be an inorder traversal of your tree. Your output should look similar to:. 1
//a 3
//e 1
//f 1
//h 7
//...
 ostream& operator<<(ostream& output, const SearchTree& st){
    //st.displayHelper(output,st.root);
    //output << endl;
    //return output;
    return st.displaying(output,st.root);
}