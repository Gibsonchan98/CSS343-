//
// Graph.cpp
// Member function definitions for class Graph
// Created by Melanie Palomino on 4/25/20.
//---------------------------------------------------------------------------
// Graph class:  Creates a graph implemented with an adjacency list.
//   This program allows:
//   -- allows inserting a edge or replacing an edge
//   -- allows removing an edge
//   -- allows displaying all vertices & shortest paths
//   -- allows displaying of shortest path between two vertices
//   -- allows finding the shortest path using Dijstra's algorithm
//
// Assumptions:
//   -- All input is valid
//   -- There is enough space for copies
//   -- The graph only has up to 100 vertices
//---------------------------------------------------------------------------

#include <fstream>
#include <string>
#include <iomanip>
#include "Graph.h"

using namespace std;

//****************** Constructor & Destructor *********************************

//--------------------------- Deafult Constructor -----------------------------
// Default constructor. Creates an empty graph
// Preconditions:  none
// Postconditions: Graph is constructed with default values.
Graph::Graph() {
    this->size = 0;

}

//--------------------------- Copy Constructor -----------------------------
// Copy constructor. Creates a new graph by copying another graph.
// Preconditions: There is enough space for copy. Other is not empty
// Postconditions: Graph is constructed with copied values.
Graph::Graph(const Graph &other) {
    *this = other;
    this->setTable();
}

Graph::~Graph() {

}
//*****************************************************************************

//---------------------------------  =  ---------------------------------------
// Assignment operator overload. Copies all values from other.
// Copies size, table, and adjacency list.
// Preconditions: There is enough space for copy. Other is not empty.
// Postconditions: Graph copies all the values of other.
const Graph& Graph::operator=(const Graph &other) {
    //if it is empty
    if(other.isEmpty()){
        this->clear(); //clear graph
    }
    else{
        this->size = other.size;
        this->clear(); //delete everything and copy again

        EdgeNode *otherTemp = nullptr, *temp = nullptr; //initialize everything


        for(int i = 1; i <= other.size; i++){
            //create new object
            vertices[i].data = new Vertex;
            //copy description
            vertices[i].data = other.vertices[i].data;   //copy address
            *vertices[i].data = *other.vertices[i].data; //copy object

            //copy head of list to initalize vertixnode
            if(other.vertices[i].edgeHead){
                vertices[i].edgeHead = new EdgeNode;
                vertices[i].edgeHead->adjVertex = other.vertices[i].edgeHead->adjVertex;
                vertices[i].edgeHead->weight = other.vertices[i].edgeHead->weight;
                vertices[i].edgeHead->nextEdge = nullptr;
                temp = vertices[i].edgeHead;
                otherTemp = other.vertices[i].edgeHead->nextEdge;
            }

            //recursion
            while(otherTemp){
                //copy Edgenode
                temp->nextEdge = new EdgeNode;
                temp->nextEdge->weight = otherTemp->weight;
                temp->nextEdge->adjVertex =  otherTemp->adjVertex;
                temp->nextEdge->nextEdge = nullptr;

                temp = temp->nextEdge;
                otherTemp = otherTemp->nextEdge;
            }
        }


        this->setTable();
        for(int i = 1; i <= this->size; i++){
            for(int j = 1; j <= this->size; j++){
                this->T[i][j].visited = other.T[i][j].visited;
                this->T[i][j].dist = other.T[i][j].dist;
                this->T[i][j].path = other.T[i][j].path;
            }
        }
    }
    return *this;
}

//-------------------------- setTable ---------------------------
// Sets all values of table to false, 0, or infinity.
// Preconditions: Table exists
// Postconditions: Table is set to false, 0, or infinity.
void Graph::setTable(){
    for(int i = 1; i < MAX_VERTICES; i++){
        for(int j = 1; j < MAX_VERTICES; j++){
            T[i][i].visited = false;
            T[i][i].path = 0;
            T[i][i].dist = INT_MAX; //set to infinity
        }
    }
}

//-------------------------------- buildGraph ---------------------------------
// Builds a graph by reading data from an ifstream
// Preconditions:  infile has been successfully opened and the file contains
//                 properly formated data (according to the program specs)
// Postconditions: One graph is read from infile and stored in the object
void Graph::buildGraph(ifstream& infile) {

    infile >> size;						// data member stores array size
    if (infile.eof())
        return;
    infile.ignore();					// throw away '\n' to go to next line

    // get descriptions of vertices
    for (int v = 1; v <= size; v++) {
        vertices[v].data = new Vertex;
        infile >> *vertices[v].data;	// use Vertex::operator>> to read descriptions
        vertices[v].edgeHead = nullptr; //initialize edgeHead
    }

    // fill cost edge array
    int src = 1, dest = 1, weight = 1;
    for (;;) {
        infile >> src >> dest >> weight;
        if (src == 0 || infile.eof())
            break;
        insertEdge(src, dest, weight); //inserts edge to arraylist
    }
}

bool Graph::insertEdge(int from, int to, int cost) {
    //check if valid input
    if (from > size || to > size || from < 1 || to < 1)
    {
        return false;
    }
  /*  if(from == to){
        return false;
    } */
    EdgeNode* newEdgeNode, *curr;

    if(vertices[from].edgeHead == nullptr){ //if it'sempty
        vertices[from].edgeHead = new EdgeNode; //initialize edge
        vertices[from].edgeHead->adjVertex = to;
        vertices[from].edgeHead->weight = cost;
        vertices[from].edgeHead-> nextEdge = nullptr;
        findShortestPath();
        return true;
    }
    else{
        curr = vertices[from].edgeHead; //start looking through array
        /*
         * if(!insertDuplicate(curr)){
         * newEdgeNode = new EdgeNode;
            newEdgeNode->adjVertex = to;
            newEdgeNode->weight = cost;
            newEdgeNode->nextEdge = vertices[from].edgeHead; //add to arraylist
            vertices[from].edgeHead = newEdgeNode;
            findShortestPath(); //update table
            return true;
         * } else{
                return true;}
         *
         * */
        while(curr != nullptr){
            if(curr->adjVertex == to){ //check if edge already exists
                curr->weight = cost;
                return true;
            }
            curr = curr->nextEdge; //keeps looking through list until nullptr
        }
        newEdgeNode = new EdgeNode;
        newEdgeNode->adjVertex = to;
        newEdgeNode->weight = cost;
        newEdgeNode->nextEdge = vertices[from].edgeHead; //add to arraylist
        vertices[from].edgeHead = newEdgeNode;
        findShortestPath(); //update table
        return true;
    }

}

//removes edge between to vertices
//pre: edge must exist
//post: edge is removed returns true else false
bool Graph::removeEdge(int from, int to) {
    if (from > size || to > size || from < 1 || to < 1)
    {
        return false;
    }
    EdgeNode* curr;
    EdgeNode* prev;
    prev = curr = vertices[from].edgeHead;
    /*
     * POSSIBLE RECURSION
     * return removeRecursive(curr,prev);
     *
     * removeRecursive(curr,prev){
     * if(curr != nullptr)
     * if(curr->adjVertex == to){ //base case
            prev->nextEdge = curr->nextEdge;
            delete curr; //removed edge
            findShortestPath();
            return true;
        } else{
        prev = curr;
        curr = curr->nextEdge;
                return removeRecursive(curr,prev);
        }
     * */
    while(curr != nullptr){
        if(curr->adjVertex == to){ //Found the edge //base case
            prev->nextEdge = curr->nextEdge;
            delete curr; //removed edge
            findShortestPath();
            return true;
        }
        prev = curr;
        curr = curr->nextEdge;
    }
    return false;
}



//finds shortest path from a source to a vertex
void Graph::findShortestPath() {
    int vertex = 1; //placeholder
    for(int i = 1; i <= size; i ++){

        T[i][i].dist = 0; //first value is always 0

        for(int j = 1; j < size; i++){ //must run through loop n-1 times

            vertex = lowestCost(i); //lowest cost found
            T[i][vertex].visited = true;

            if(vertex != 0){
                //Proceeds to analyze adjacent vertex
                for(int k = 1; k <= size; j++){
                    if(T[i][k].visited == false){

                    }
                }
            }
        }
    }
}

//returns vertex with lowest cost
int Graph::lowestCost(int vertex) const {

    int place = 0, max = INT_MAX;

    for(int i = 1; i <= size; i++){

        if (T[vertex][i].dist < max && T[vertex][i].visited == false){
            max = T[vertex][i].dist;
            place = i;
        }
    }
    return place;
}




void Graph::display(int start, int end) {

    int width = 6; //set width

    cout << setw(width) << start << setw(width) << end;
   if(start == end){
        dataPrinter(start,end);
        cout << endl;
        return; //terminates display
    }
    if (T[start][end].dist != INT_MAX){
        cout << setw(width) << T[start][end].dist << setw(width);
        pathPrinter(start,end);
        cout << endl;
        dataPrinter(start,end);
        cout << endl;
    }
    else {
        cout << setw(width) << "--" << endl;   //no path
    }
}

//Prints out every vertex to every vertex
void Graph::displayAll() {

    int lw = 20, w = 6, e = 27;

    if(size == 0){
        cout << "Nothing to see here " << endl;
        return;
    }
    cout << "Description" << setw(lw) << "From" << setw(w) << "To";
    cout << setw(w) << "Dist" << setw(w) << "Path" << endl;

    for(int i = 1; i <= size; i++){
        cout << *vertices[i].data << endl;
        for(int j = 1; j <= size; j++){

            if(i != j){
                cout << setw(e) << i << setw(w) << j;

                if(T[i][j].dist != INT_MAX){
                    cout << setw(w) << T[i][j].dist;
                    cout << setw(w);
                    pathPrinter(i,j);
                    cout << endl;
                 }
            }
        }
    }
}

void Graph::pathPrinter(int start, int next) {
    if(T[start][next].dist != INT_MAX){
        pathPrinter(start,T[start][next].path);
        cout << T[start][next].path;
    }
}

void Graph::dataPrinter(int start, int next) {
    if(T[start][next].dist != INT_MAX){
        dataPrinter(start,T[start][next].path);
        cout << *vertices[next].data;
    }
}

//--------------------------- isEmpty  ---------------------------------
// Checks if Graph is empty
// Preconditions:  none
// Postconditions: True is returned if empty. False otherwise
bool Graph::isEmpty() const {
    return this->size == 0; //nothing in there
}



