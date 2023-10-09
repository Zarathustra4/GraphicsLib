#include <vector>
#pragma once

using std::vector;
class Edges
{
private:
	vector<vector<int>> edges;
	int edgesNumber;

public:
	Edges(vector<vector<int>> edges);

	Edges(int edgesNumber);

	vector<int> getEdge(int index);

	void addEdge(vector<int> edge);
};

