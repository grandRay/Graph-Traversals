#include "Graph.h"

Graph::Graph(int n, bool directed, bool weighted){
	numVert = n;
	this->directed = directed;
	this->weighted = weighted;
	numEdges = 0;
	myEdges = new list<Edge>[n];
}

void Graph::addEdge(Edge e) {
	if (directed) {
		myEdges[e.vert1].push_back(e);
		numEdges++;
	}

	else {
		myEdges[e.vert1].push_back(e);
		myEdges[e.vert2].push_back(e);
		numEdges++;
	}
}

list<Edge> Graph::getAdjacentList(int v) {
	list<Edge> retEdge;
	list<Edge>::iterator i;

	if (v >= numVert) {
		Edge empty;
		retEdge.push_back(empty);
		return retEdge;
	}

	for (i = myEdges[v].begin(); i != myEdges[v].end(); ++i) {
		retEdge.push_back(*i);
	}

	return retEdge;
}

Edge Graph::getEdge(int v1, int v2) const{
	list<Edge>::iterator i = myEdges[v1].begin();
	for (; i != myEdges[v1].end(); ++i) {
		if (i->vert1 == v1 && i->vert2 == v2) {
			return *i;
		}
	}

	Edge dummy(0, 0, 0);
	return dummy;
}

int Graph::getNumVertices() const{
	return numVert;
}

int Graph::getNumEdges() const{
	return numEdges;
}

bool Graph::isDirected() const{
	return directed;
}

bool Graph::isWeighted() const{
	return weighted;
}

list<Edge> Graph::getList(){
	return *myEdges;
}
