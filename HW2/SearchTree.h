//---------------------------------------------------------------------------
// SEARCHTREE.H
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

#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#include "comparable.h"

#include <iostream>
#include <cassert>
#include <string> //for now

using namespace std;

class SearchTree{
    //output the frequency table in sorted order.
    // This should be an inorder traversal of your tree. Your output should look similar to:. 1
    //a 3
    //e 1
    //f 1
    //h 7
    //...
    friend ostream& operator<<(ostream& output, const SearchTree& st);

public:
    //***************** Constructors & Destructors ****************************

    //-------------------------- Constructor ----------------------------------
    // Default constructor for class SearchTree
    // Preconditions:   None
    // Postconditions:  root pointer is set to null and num of nodes is set to 0
    SearchTree();

    //---------------------------- Copy ---------------------------------------
    // Copy constructor for class SearchTree
    // Preconditions:  Passed tree is not empty and there's enough memory
    // Postconditions:  other is copied into *this with the same structure
    SearchTree(const SearchTree& st);

    //---------------------------- Destructor ---------------------------------
    // Destructor for class SearchTree
    // Preconditions:   There's something in the heap
    // Postconditions: SearchTree is completely deallocated, Nodenums is 0
    ~SearchTree();
    //*************************************************************************

    //***************** Overloaded Operators **********************************

    //-----------------------------  =  ---------------------------------------
    // Overloaded assignment operator
    // Preconditions:   right is not empty and there's enough memory
    // Postconditions: right is copied into *this. *This is then returned
    const SearchTree& operator=(const SearchTree& right);

    //------------------------------  ==  -------------------------------------
    // Determine if two SearchTrees are equal.
    // Preconditions:  Right is not empty
    // Postconditions:  true is returned if SearchTrees have the same data,
    //                  structure and frequencies.
    bool operator==(const SearchTree& right) const;

    //--------------------------------  !=  -----------------------------------
    // Determine if two SearchTrees are not equal.
    // Preconditions:  Right is not empty
    // Postconditions:  true is returned if SearchTrees don't have the same data,
    //                 structure and frequencies.
    bool operator!=(const SearchTree& right) const;
    //*************************************************************************

    //******************* Mutator Functions ***********************************

    //--------------------------------  Insert  -------------------------------
    // Inserts a Comparable item into SearchTree.
    // Preconditions:  Comparable is not a nullptr.
    // Postconditions:  true is returned if Object is stored for the first time.
    //          Returns false if item already existed
    bool insert(Comparable* newItem);

    //---------------------------- Remove -------------------------------------
    // Removes an occurance of a Comparable item in SearchTree.
    // Preconditions:  Comparable is not empty.
    // Postconditions: True is returned if occurrence is removed. False if
    //              item is not in Searchtree.
    bool remove(const Comparable& comp);

    //--------------------------MakeEmpty----------------------------------
    // Removes and deallocates memory.
    // Preconditions: None.
    // Postconditions: Everything is deleted and memory is free again.

    void makeEmpty();
    //*************************************************************************

    //******************* Mutator Functions ***********************************

    //-------------------------Retrieve ---------------------------------------
    // Retrieves Comparable pointer stored in the Node that contains
    // the Comparable item.
    // Preconditions: None
    // Postconditions: Comparable pointer is returned.
    const Comparable* retrieve(const Comparable& item) const;

    //------------------------  height ----------------------------------------
    // Gives the height of Node where item is located at.
    // Preconditions:  None
    // Postconditions: The heigh of the node where item is located at is returned.
    //               If not found, -1 is returned.
    int height(const Comparable& comp) const;

    //*************************************************************************

private:
    struct Node{
        //kind of like int data or char data
        Comparable* dataPtr; //pointer to comparible
        Node* rightPtr; //right child
        Node* leftPtr; //left child
        int frequency; //keep track of nodes
    };

    Node* root; //pointer to root

    int Nodenums; //helps keep track of nodes

    //********************** Private Methods **********************************

    //---------------------------- Insert  Helper -----------------------------
    // Recursively inserts a Comparable item into SearchTree.
    // Preconditions:  Comparable and curr are not a nullptrs.
    // Postconditions:  true is returned if Object is stored for the first time.
    //          Returns false if item already existed.
    bool insertHelper(Node* curr, Comparable* newItem);

    //--------------------------- copyHelper ----------------------------------
    // Copies otherRoot into thisRoot
    // Preconditions:   Nodes are not nullptrs and there's enough memory
    // Postconditions:  thisRoot is exactly like otherRoot.
    void copyHelper(Node* otherRoot, Node* &thisRoot) const;

    ///------------------------- comparingHelper ------------------------------
    // Compares two SearchTree Objects
    // Preconditions:   otherRoot and thisRoot are comparable
    // Postconditions: Return true is trees have the same structure, data, and
    //            frequency. Otherwise, returns false.
    bool comparingHelper(Node* otherRoot, Node* thisRoot) const;

    //-------------------------Retrieve Helper ------------------------------
    // Retrieves Comparable pointer stored in the Node that contains
    // the Comparable item.
    // Preconditions: None
    // Postconditions: Comparable pointer is returned.
    const Comparable* retrieveHelper(Node* curr, const Comparable& item) const;

    //--------------------------Clear----------------------------------
    // Removes and deallocates memory.
    // Preconditions: None.
    // Postconditions: Everything is deleted and memory is free again.
    void clear(Node* curr);

    //------------------------heightAddition --------------------------------------
    // Adds the number of children node each side has
    // Preconditions:   Tree is not empty
    // Postconditions:  Max total of children nodes is returned; if leaf then it is 0.
    int heightAddition(Node* curr) const;

    //---------------------- positionFinder --------------------------------------
    // Finds the position of where the item is located at
    // Preconditions:   Tree is not empty
    // Postconditions:  newPtr is set with position if item is in the tree.
    void positionFinder(Node*& newPtr, Node* curr, const Comparable& item) const;

    //---------------------------Remove Recursive ---------------------------------
    // Recursively removes an occurance of a Comparable item in SearchTree.
    // Preconditions:  Comparable is not empty and curr is not a nullptr.
    // Postconditions: True is returned if occurrence is removed. False if
    //              item is not in Searchtree.
    bool removeRecursive(Node*& curr, const Comparable& item);

    //-------------------------- DeleteNode -------------------------------------
    // Checks if curr has any children to delete appropriately .
    // Preconditions:  Curr is not a nullptr.
    // Postconditions: Old data ptr is deleted and set to smallest item.
    void deleteNode(Node*& curr);

    //--------------------------replaceWithSmallest-----------------------------
    // Goes to the smallest value, deletes node, and returns data
    // Preconditions:  Curr is not a nullptr.
    // Postconditions: Node is delete and smallest item is returned.
    Comparable* replaceWithSmallest(Node*& curr);

    //--------------------------- displayHelper --------------------------------------
    // Overloaded output operator for class Binary; outputs binary number
    // Preconditions:   curr is not a nullptr.
    // Postconditions:  Data is displayed with frequency
    void displayHelper(ostream& output,Node* curr) const;

    //This function also works
    //----------------------------displaying ---------------------------------------
    // Overloaded output operator for class Binary; outputs binary number
    // Preconditions:   curr is not a nullptr.
    // Postconditions:  Data is displayed with frequency
   //ostream& displaying(ostream& output, Node* curr) const;

};

#endif //SEARCHTREE_H
