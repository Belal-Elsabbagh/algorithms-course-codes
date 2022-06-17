#pragma once
#include<iostream>
#include <vector>
#include "DirectedWeightedGraph.h"
#define NO_COLOR -1
using namespace std;

class GraphColoring
{
public:
	void color(DirectedWeightedGraph<int> adjacency_matrix, int numOfColors, int i, vector<int> color);
private:
	void printSolution(vector<int> color);
	bool isSafe(DirectedWeightedGraph<int> adjacency_matrix, vector<int> color);
	bool adjacent_colors(DirectedWeightedGraph<int> adjacency_matrix, vector<int> color, int node1, int node2) {
		return adjacency_matrix.edge_exists(node1, node2)
			&& (color[node1] == color[node2]) 
			&& color[node1] != NO_COLOR && color[node2] != NO_COLOR;
	}
};
void GraphColoring::color(DirectedWeightedGraph<int> adjacency_matrix, int numOfColors, int current_node, vector<int> colors)
{
	if (!isSafe(adjacency_matrix, colors)) return;
	if (current_node == adjacency_matrix.get_number_of_nodes())
	{
		printSolution(colors);
		return;
	}
	for (int color_number = 1; color_number <= numOfColors; color_number++)
	{
		colors[current_node] = color_number;
		color(adjacency_matrix, numOfColors, current_node + 1, colors);
	}
}

void GraphColoring::printSolution(vector<int> color)
{
	for (int i = 0; i < color.size(); i++)
		cout << " " << color[i];
	cout << "\n";
}

inline bool GraphColoring::isSafe(DirectedWeightedGraph<int> adjacency_matrix, vector<int> color)
{
	for (int i = 0; i < adjacency_matrix.get_number_of_nodes(); i++)
		for (int j = i + 1; j < adjacency_matrix.get_number_of_nodes(); j++)
			if (adjacent_colors(adjacency_matrix, color, i, j)) return false;
	return true;
}

void TEST_coloring()
{
	DirectedWeightedGraph<int> graph({
		{ NULL_EDGE, 1, 1, 1 },
		{ 1, NULL_EDGE, 1, NULL_EDGE },
		{ 1, 1, NULL_EDGE, 1 },
		{ 1, NULL_EDGE, 1, NULL_EDGE }
		});

	DirectedWeightedGraph<int> bigGraph (
	{
		//1, 2, 3, 4, 5, 6, 7, 8, 9, NULL_EDGE, 1, 2, 3, 4, 5, 6, 7, 8, 9, NULL_EDGE
		{ NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, 1, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE},
		{ 1, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE},
		{ NULL_EDGE, 1, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE},
		{ NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE},
		{ 1, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1},
		{ 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, 1, NULL_EDGE},
		{ NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, 1},
		{ NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1},
		{ NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, 1, 1, NULL_EDGE, NULL_EDGE, NULL_EDGE},
		{ NULL_EDGE, NULL_EDGE, NULL_EDGE, NULL_EDGE, 1, NULL_EDGE, 1, 1, NULL_EDGE, NULL_EDGE},
	});
	GraphColoring g;
	int m = 3;
	vector<int> coloring(graph.get_number_of_nodes(), NO_COLOR);

	g.color(graph, m, 0, coloring);
}