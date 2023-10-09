#include "Edges.h"
#include <vector>
#include <iostream>

Edges::Edges(int edgesNumber):
	edgesNumber(edgesNumber),
	edges(vector<vector<int>>(edgesNumber, vector<int>(2)))
{}

Edges::Edges(vector<vector<int>> edges):
	edges(edges),
	edgesNumber(edges.size())
{}

void Edges::addEdge(vector<int> edge) {
	if (edge.size() != 2) {
		std::cerr << "The size of the edge is not 2!" << std::endl;
		return;
	}

	edges.push_back(edge);
}

vector<int> Edges::getEdge(int index) {
	if (index < 0 or index >= edges.size()) {
		std::cerr << "The index is incorrect!" << std::endl;
		return;
	}

	return edges[index];
}