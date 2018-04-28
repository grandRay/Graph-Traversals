#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <list>
#include <queue>
using namespace std;

class Edge {
public:
	int vert1, vert2;
	Edge *next;
	bool directed;
	bool weighted;
	bool visited;
	double weight;
	
	Edge();
	Edge(int v1, int v2, int w);
};
#endif
