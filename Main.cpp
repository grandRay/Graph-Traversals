#include "Graph.h"
#include "Edge.h"
#include "Traversals.h"
#include <fstream>

int main(){
	ifstream inFile;
	Graph *myGraph;
	vector <int> v1, v2;
	int vert1, vert2, numVert = 0, weight = 0;
	char dummy, dummy2;
	bool directed, weighted;

	inFile.open("myFile.txt");

	if (!inFile) {
		cout << "Unable to open myFile.txt";
		exit(1);
	}

	else {
		inFile >> numVert >> dummy >> dummy2;

		if (dummy == 'U')
			directed = 0;
		else
			directed = 1;

		if (dummy2 == 'N')
			weighted = 0;
		else
			weighted = 1;

		myGraph = new Graph(numVert, directed, weighted);
		while (inFile >> vert1 >> vert2) {
			Edge Edge(vert1, vert2, 0);
			myGraph->addEdge(Edge);
		}
	}

	cout << "Number of vertices: " << myGraph->getNumVertices() << endl;
	cout << "Number of edges: " << myGraph->getNumEdges() << endl;
	cout << "Is the graph directed? ";
	if (myGraph->isDirected())
		cout << "Yes\n";
	else
		cout << "No\n";

	cout << "Is the graph weighted? ";
	if (myGraph->isWeighted())
		cout << "Yes\n";
	else
		cout << "No\n";
	
	Traversals T;
	cout << "Breadth-First Traversal (starting at vertex 0): ";
	T.BFS(myGraph, 0);

	cout << "Depth-First Traversal (starting at vertex 0): ";
	T.DFS(myGraph, 0);
	
	cout << endl;

	inFile.close();
    return 0;
}

