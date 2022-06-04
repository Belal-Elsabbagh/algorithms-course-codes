#pragma once
#include<iostream>
#include <vector>
using namespace std;

class GraphColoring
{
public:
	bool color(vector<vector<bool>> graph, int numOfColors, int i, vector<int> color);
private:
	void printSolution(vector<int> color);
	bool isSafe(vector<vector<bool>> graph, vector<int> color);
};
bool GraphColoring::color(vector<vector<bool>> graph, int numOfColors, int i, vector<int> color)
{
	if (!isSafe(graph, color)) return false;
	if (i == graph.size())
	{
		printSolution(color);
		return true;
	}
	for (int j = 1; j <= numOfColors; j++)
	{
		color[i] = j;
		if (this->color(graph, numOfColors, i + 1, color)) return true;
	}
	return false;
}

void GraphColoring::printSolution(vector<int> color)
{
	for (int i = 0; i < color.size(); i++)
		cout << " " << color[i];
	cout << "\n";
}

inline bool GraphColoring::isSafe(vector<vector<bool>> graph, vector<int> color)
{
	for (int i = 0; i < graph.size(); i++)
		for (int j = i + 1; j < graph[i].size(); j++)
			if (graph[i][j] && color[j] == color[i]) return false;
	return true;
}

void test_coloring()
{
	vector<vector<bool>> graph =
	{
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 },
	};

	vector<vector<bool>> bigGraph =
	{
		//1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0
		{ 0, 1, 0, 0, 1, 1, 0, 0, 0, 0},
		{ 1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
		{ 0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
		{ 0, 0, 1, 0, 1, 0, 0, 0, 1, 0},
		{ 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},
		{ 1, 0, 0, 0, 0, 0, 0, 1, 1, 0},
		{ 0, 1, 0, 0, 0, 0, 0, 0, 1, 1},
		{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
		{ 0, 0, 0, 1, 0, 1, 1, 0, 0, 0},
		{ 0, 0, 0, 0, 1, 0, 1, 1, 0, 0},
	};
	GraphColoring g;
	int m = 4;
	vector<int> coloring(bigGraph.size());
	for (int i = 0; i < bigGraph.size(); i++)
		coloring[i] = 0;

	if (!g.color(bigGraph, m, 0, coloring))
		cout << "Solution does not exist";
}