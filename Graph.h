#ifndef GRAPH_H
#define GRAPH_H
#include "Edge.h"

class Graph {
private:
	int numVert, numEdges;
	bool directed;
	bool weighted;
	Edge *root;
	
public:	
	list<Edge> *myEdges;
	Graph(int n, bool directed, bool weighted);
	void addEdge(Edge e);
	list<Edge> getAdjacentList(int v);
	Edge getEdge(int v1, int v2) const;
	int getNumVertices() const;
	int getNumEdges() const;
	bool isDirected() const;
	bool isWeighted() const;
	list<Edge> getList();
};
#endif
