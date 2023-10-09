#include "Edges.h"
#include <vector>
#include <iostream>

Edges::Edges():
	size(0),
	edges(vector<vector<int>>(0, vector<int>(2)))
{}

Edges::Edges(int edgesNumber):
	size(edgesNumber),
	edges(vector<vector<int>>(edgesNumber, vector<int>(2)))
{}

Edges::Edges(vector<vector<int>> edges):
	edges(edges),
	size(edges.size())
{}

void Edges::addEdge(vector<int> edge) {
	if (edge.size() != 2) {
		std::cerr << "The size of the edge is not 2!" << std::endl;
		return;
	}

	edges.push_back(edge);
	size++;
}

vector<int> Edges::getEdge(int index) {
	if (index < 0 or index >= edges.size()) {
		std::cerr << "The index is incorrect!" << std::endl;
		return vector<int>();
	}

	return edges[index];
}

int Edges::getSize() {
	return size;
}