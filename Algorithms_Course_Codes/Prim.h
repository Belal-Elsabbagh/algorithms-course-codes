#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX INT_MAX
using namespace std;
typedef vector<vector<int>> matrix;
class Prim
{
public:
    Prim(matrix graph);

    /**
     * @brief Get the minimum spanning tree for a graph using Prim's algorithm
     *
     *
     * @return The constructed minimum spanning tree.
     */
    matrix generate_mst();
private:
    matrix reference_graph;
    vector<int> mst_parents;
    vector<bool> visitedNodes;
    vector<int> cost;
    int numOfNodes;

    /**
     * @brief Pick the vertex with minimum edge weight and not already included in MST.
     *
     * @param visitedNodes The vertices that are already included in
     * @param cost
     * @return The vertex with minimum edge weight and not already included in MST.
     */
    size_t get_minimum_index();
    bool edge_exists_AND_vertex_not_visited_AND_minimum_edge_weight(int start, int end);
    void save_vertex_and_cost(int start, int end);
    matrix construct_mst_matrix();
};


/**
* @brief Get the minimum spanning tree for a graph using Prim's algorithm
*
*
* @return The constructed minimum spanning tree.
*/

Prim::Prim(matrix graph)
{
    int startIndex = 0;
    this->numOfNodes = graph.size();

    this->reference_graph = matrix(graph);
    this->mst_parents = vector<int>(numOfNodes);
    this->visitedNodes = vector<bool>(numOfNodes, false);
    this->cost = vector<int>(numOfNodes, MAX);

    this->cost[startIndex] = 0;
    this->mst_parents[startIndex] = -1;
}

inline matrix Prim::generate_mst()
{
    for (size_t i = 0; i < numOfNodes; i++)
    {
        int min_index = get_minimum_index();
        visitedNodes[min_index] = true;
        for (size_t j = 0; j < numOfNodes; j++)
            if (edge_exists_AND_vertex_not_visited_AND_minimum_edge_weight(min_index, j))
                save_vertex_and_cost(min_index, j);
    }
    return construct_mst_matrix();
}

size_t Prim::get_minimum_index()
{
    int min = MAX, min_index = 0;
    for (size_t j = 0; j < visitedNodes.size() - 1; j++)
    {
        if (!visitedNodes[j] && cost[j] < min)
            min = cost[j], min_index = j;
    }
    return min_index;
}

bool Prim::edge_exists_AND_vertex_not_visited_AND_minimum_edge_weight(int start, int end)
{
    return reference_graph[start][end] && !visitedNodes[end] && reference_graph[start][end] < cost[end];
}

inline void Prim::save_vertex_and_cost(int start, int end)
{
    mst_parents[end] = start, cost[end] = reference_graph[start][end];
}

inline matrix Prim::construct_mst_matrix()
{
    matrix mst(numOfNodes, vector<int>(numOfNodes, 0));
    for (int i = 1; i < numOfNodes; i++)
        mst[mst_parents[i]][i] = reference_graph[i][mst_parents[i]];
    return mst;
}

inline void print_matrix(matrix mat)
{
    for (size_t i = 0; i < mat.size(); i++)
    {
        for (size_t j = 0; j < mat[i].size(); j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "\n";
    }
}

void TEST_prim_algorithm()
{
    matrix graph =
    {
        { 0, 2, 0, 6, 0 },
        { 2, 0, 3, 8, 5 },
        { 0, 3, 0, 0, 7 },
        { 6, 8, 0, 0, 9 },
        { 0, 5, 7, 9, 0 }
    };
    matrix result = Prim(graph).generate_mst();
    print_matrix(result);
}