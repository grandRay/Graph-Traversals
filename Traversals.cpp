#include "Traversals.h"


void Traversals::BFS(Graph *graph, int s) {
	int V = graph->getNumVertices();
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;

	queue<int> queue;

	visited[s] = true;
	queue.push(s);
	
	list<Edge>::iterator i;
	while (!queue.empty()) {
		s = queue.front();

		cout << s << " ";
		queue.pop();

		list<Edge> that = graph->getAdjacentList(s);

		for (i = that.begin(); i != that.end(); ++i) {
			if (!visited[i->vert1]) {
				visited[i->vert1] = true;
				queue.push(i->vert1);
			}
			else if(!visited[i->vert2]) {
				visited[i->vert2] = true;
				queue.push(i->vert2);
			}
		}
	}

	cout << endl;
}

void Traversals::DFS(Graph *graph, int s){
	int v = graph->getNumVertices();
	bool *visited = new bool[v];
	for (int i = 0; i < v; i++)
		visited[i] = false;
	RDFS(*graph, s, visited);
}

void Traversals::RDFS(Graph graph, int s, bool visited[]){
	visited[s] = true;
	
	cout << s << " ";

	list<Edge>::iterator i;
	list<Edge> that = graph.getAdjacentList(s);
	for (i = that.begin(); i != that.end(); ++i) {
		if (!visited[i->vert1])
			RDFS(graph, i->vert1, visited);

		else if (!visited[i->vert2])
			RDFS(graph, i->vert2, visited);
	}
}


