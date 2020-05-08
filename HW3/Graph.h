//
// Graph.h
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

#ifndef GRAPH_H
#define GRAPH_H

#include <fstream>

#include "Vertex.h"

using namespace std;

class Graph {
public:

    //********* Constructor & Destructor **************************

    //--------------------------- Deafult Constructor -----------------------------
    // Default constructor. Creates an empty graph
    // Preconditions:  none
    // Postconditions: Graph is constructed with default values.
    Graph();

    //--------------------------- Copy Constructor -----------------------------
    // Copy constructor. Creates a new graph by copying another graph.
    // Preconditions: There is enough space for copy. Other is not empty
    // Postconditions: Graph is constructed with copied values.
    Graph(const Graph& other);

    //---------------------------   Destructor  -----------------------------
    // Deallocates all memory
    // Preconditions: None
    // Postconditions: All memory is deallocated
    virtual ~Graph();
    //*************************************************************


    //-------------------------------- buildGraph ---------------------------------
    // Builds a graph by reading data from an ifstream
    // Preconditions:  infile has been successfully opened and the file contains
    //                 properly formated data (according to the program specs)
    // Postconditions: One graph is read from infile and stored in the object
    void buildGraph(ifstream& infile);

    //--------------------------- display ----------------------------------
    // Displays shortest path and cost from one source to a specific vertix
    // Preconditions:  Both vertices exist
    // Postconditions: Path and cost is displayed.
    void display(int start, int end);

    //--------------------------- displayAll -------------------------------
    // Displays all vertices, their description, paths, and cost
    // Preconditions:  Graph is not empty
    // Postconditions: Descriptions are displayed for all vertices
    void displayAll();

    //------------------------ insertEdege ------------------------
    //Inserts edge between vertices, or replaces it if one already
    // exists.
    //Precondtions: Vertices must exist and cost is not negative
    //Postcontion: New edge is inserted.
    bool insertEdge(int from, int to, int cost);

    ///------------------------ removeEdge ----------------------------------
    //removes edge between to vertices
    //Precondtions: Edge must exist and vertices must exist
    //Postcontion: If edge is removed returns true else false.
    bool removeEdge(int from, int to);

    //------------------------ findShortestPath ----------------------------
    // Finds the shortestPath from every vertix to all vertices
    // Preconditions: Graph is not empty
    // Postconditions: Table is updated with new costs
    void findShortestPath();


    //*************** operator overload ****************************

    //---------------------------------  =  ---------------------------------------
    // Assignment operator overload. Copies all values from other.
    // Copies size, table, and adjacency list.
    // Preconditions: There is enough space for copy. Other is not empty.
    // Postconditions: Graph copies all the values of other.
    const Graph& operator=(const Graph& other);
    //**************************************************************
private:
    static const int MAX_VERTICES = 101; //max amount of vertices a graph will have

    struct EdgeNode {
        int adjVertex;			// subscript of the adjacent vertex
        int weight;				// weight of edge
        EdgeNode* nextEdge;
    };

    struct VertexNode {
        EdgeNode* edgeHead;		// head of the list of edges
        Vertex* data;			// store vertex data here
    };

    // array of VertexNodes
    VertexNode vertices[MAX_VERTICES]{}; //adjacency list to store shortest path?

    // table of information for Dijkstra's algorithm
    struct Table {
        bool visited;			// whether vertex has been visited
        int dist;				// shortest known distance from source
        int path;				// previous vertex in path of min dist
    };

    int size;					// number of vertices in the graph

    // Table stores visited, distance, path - two dimensional in order to solve for all sources
    Table T[MAX_VERTICES][MAX_VERTICES]{};

    //--------------------------- clear -------------------------
    // Clears all vertices' allocated memory
    // Preconditions: Graph is not empty
    // Postconditions: All memory is deallocated.
    void clear();

    //--------------------------- pathPrinter ------------------------------
    // Displays vertix's shortest path
    // Preconditions:  Vertix must exist
    // Postconditions: Shortest path is printed for every vertex
    void pathPrinter(int start, int next);

    //--------------------------- dataPrinter ------------------------------
    // Displays vertix's description recursively
    // Preconditions:  Vertix must exist
    // Postconditions: Description is printed for every vertix
    void dataPrinter(int start, int next);

    //-------------------------- removeHelper --------------------------
    // Removes existing edge
    // Preconditions: Graph is not empty and edge exists
    // Postconditions: Returns true if success, otherwise false
    bool removeHelper(EdgeNode*& curr, EdgeNode*& prev, int to);

    //-------------------------- setTable ---------------------------
    // Sets all values of table to null or false.
    // Preconditions: Table exists
    // Postconditions: Table is set to null or false values.
    void setTable();

    //--------------------------- lowestCost ------------------------------
    // Finds the path with the lowest cost
    // Preconditions: Verices are not yet visited
    // Postconditions: Int with lowest cost stored is returned
    int lowestCost(int vertex) const;

    //-------------------------- copyHelper --------------------------
    // Copy helper. Copies all values from other object to this
    // Preconditions: Graph is not empty
    // Postconditions: Graph has the same values as other
    void copyHelper(const Graph& other);

    //--------------------------- isEmpty  ---------------------------------
    // Checks if Graph is empty
    // Preconditions:  none
    // Postconditions: True is returned if empty. False otherwise
    bool isEmpty() const;

};

#endif