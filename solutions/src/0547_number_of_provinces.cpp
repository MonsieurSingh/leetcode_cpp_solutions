//
//  0547_number_of_provinces.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#include "0547_number_of_provinces.hpp"

void	Solution::dfs(int v, vector<bool> &visited,
			const vector<vector<int>>& graph)
{
	visited[v] = true;
	for (int i = 0; i < graph.size(); i++)
	{
		if (graph[v][i] && !visited[i])
			dfs(i, visited, graph);
	}
}

int	Solution::findCircleNum(vector<vector<int>>& is_connected)
{
	vector<bool>		visited;
	int					count;
	size_t				n;
	
	n = is_connected.size();
	visited.resize(n, false);
	count = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			dfs(i, visited, is_connected);
			count++;
		}
	}
	return (count);
}
