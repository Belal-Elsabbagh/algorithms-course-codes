#pragma once
#include<iostream>
#include <vector>
#define NO_COLOR -1
using namespace std;

class GraphColoring
{
public:
	void color(vector<vector<bool>> graph, int numOfColors, int i, vector<int> color);
private:
	void printSolution(vector<int> color);
	bool isSafe(vector<vector<bool>> graph, vector<int> color);
	bool edge_exists(vector<vector<bool>> graph, int node1, int node2) { return graph[node1][node2]; }
	bool adjacent_nodes_same_color(vector<vector<bool>> graph, vector<int> color, int node1, int node2) {
		return edge_exists(graph, node1, node2) 
			&& (color[node1] == color[node2]) 
			&& color[node1] != NO_COLOR 
			&& color[node2] != NO_COLOR;
	}
};
void GraphColoring::color(vector<vector<bool>> graph, int numOfColors, int current_node, vector<int> colors)
{
	if (!isSafe(graph, colors)) return;
	if (current_node == graph.size())
	{
		printSolution(colors);
		return;
	}
	for (int color_number = 1; color_number <= numOfColors; color_number++)
	{
		colors[current_node] = color_number;
		color(graph, numOfColors, current_node + 1, colors);
	}
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
			if (adjacent_nodes_same_color(graph, color, i, j)) return false;
	return true;
}

void test_coloring()
{
	vector<vector<bool>> graph =
	{
		{ 0, 1, 1, 1 },
		{ 1, 0, 1, 0 },
		{ 1, 1, 0, 1 },
		{ 1, 0, 1, 0 }
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
	vector<int> coloring(bigGraph.size(), NO_COLOR);

	g.color(bigGraph, m, 0, coloring);
}