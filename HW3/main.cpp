#include <iostream> 
#include <fstream> 
#include <string> 

#include "Graph.h" 

using namespace std; 

int main() {

/*	ifstream file("HW3Test.txt"); 

	if (!file) {
		cout << "FILE COULD NOT BE OPENED" << endl; 
		return 1; 
	}

	for (;;) {
		Graph g;
		g.buildGraph(file);
		if (file.eof())
			break;
		g.findShortestPath();
		g.display(2, 3);
		g.displayAll();	
	}
	*/

	Graph G; 
	//G.displayAll();
	G.tempBuild(4); 
	G.displayAll(); 
	cout << "GOOD JOB! DONE!" << endl; 

	return 0;



}