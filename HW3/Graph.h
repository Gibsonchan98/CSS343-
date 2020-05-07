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

//#ifdef GRAPH_H
//#define GRAPH.H
#include <fstream>

#include "Vertex.h"

using namespace std;

class Graph {
public:

    //********* Constructor & Destructor **************************
    //default constructor
    Graph();
    //copy constructor
    Graph(const Graph& other);
    //destructor
    virtual ~Graph();
    //*************************************************************
    //takes file and builds a graph
    void buildGraph(ifstream& infile);
    //displays selected vertices and weight
    void display(int start, int end);
    //displays all vertices and paths
    void displayAll();

    //inserts edge and replaces any existing edge
    bool insertEdge(int from, int to, int cost);

    //removes edge
    bool removeEdge(int from, int to);

    //finds shortest path
    void findShortestPath();

    bool isEmpty() const;

    //*************** operator overload ****************************
    const Graph& operator=(const Graph& other);
    //**************************************************************
private:
    static const int MAX_VERTICES = 101; //max amount of vertices a graph will have

    struct EdgeNode {
        int adjVertex;			// subscript of the adjacent vertex
        int weight;				// weight of edge
        EdgeNode *nextEdge;
    };

    struct VertexNode {
        EdgeNode *edgeHead;		// head of the list of edges
        Vertex *data;			// store vertex data here
    };

    // array of VertexNodes
    VertexNode vertices[MAX_VERTICES]; //adjacency list to store shortest path?

    // table of information for Dijkstra's algorithm
    struct Table {
        bool visited;			// whether vertex has been visited
        int dist;				// shortest known distance from source
        int path;				// previous vertex in path of min dist
    };

    int size;					// number of vertices in the graph

    // Table stores visited, distance, path - two dimensional in order to solve for all sources
    Table T[MAX_VERTICES][MAX_VERTICES];

    //destructor helper
    void clear();

    void pathPrinter(int start, int next);

    void dataPrinter(int start, int next);

    bool removeHelper(EdgeNode* curr, EdgeNode* prev);

    //-------------------------- setTable ---------------------------
    // Sets all values of table to null or false.
    // Preconditions: Table exists
    // Postconditions: Table is set to null or false values.
    void setTable();

    bool inserDuplicate(EdgeNode* curr);

    int lowestCost(int vertex) const;

    int costReturn(int vertex) const;

};

