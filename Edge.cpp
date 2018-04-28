#include "Edge.h"

Edge::Edge(){
	vert1 = 0;
	vert2 = 0;
	directed = false;
	weighted = false;
	visited = false;
	next = nullptr;
	weight = 0;
}

Edge::Edge(int v1, int v2, int w){
	vert1 = v1;
	vert2 = v2;
	directed = false;
	visited = false;
	next = nullptr;
	
	if (w > 0) {
		weighted = true;
		weight = w;
	}

	else {
		weighted = false;
		weight = 0;
	}
		
}

