//
//  0785_is_graph_bipartite.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 29/9/2025.
//

#include "0785_is_graph_bipartite.hpp"

bool	dfs(int vertex, int color, vector<int> &colored,
			vector<vector<int>> &graph)
{
	colored[vertex] = color;
	for (int i = 0; i < graph[vertex].size(); i++)
	{
		int v = graph[vertex][i];
		if (colored[v] == -1)
		{
			if (!dfs(v, 1 - color, colored, graph))
				return (false);
		}
		else if (colored[v] == color)
			return (false);
	}
	return (true);
}

bool	Solution::isBipartite(vector<vector<int>> &graph)
{
	int			vertices;
	vector<int>	colored;

	vertices = (int)graph.size();
	colored.resize(vertices, -1);
	for (int vertex = 0; vertex < vertices; vertex++)
	{
		if (colored[vertex] == -1)
		{
			if (!dfs(vertex, 0, colored, graph))
				return (false);
		}
	}
	return (true);
}
