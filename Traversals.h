#ifndef TRAVERSAL_H
#define TRAVERSAL_H
#include "Graph.h"

class Traversals {
public:
	void BFS(Graph *graph, int s);
	void DFS(Graph *graph, int s);
	void RDFS(Graph graph, int v, bool visited[]);
};
#endif
