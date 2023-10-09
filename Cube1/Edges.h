#include <vector>
#pragma once

using std::vector;
class Edges
{
private:
	vector<vector<int>> edges;
	int size;

public:
	Edges();

	Edges(vector<vector<int>> edges);

	Edges(int size);

	vector<int> getEdge(int index);

	void addEdge(vector<int> edge);

	int getSize();
};

