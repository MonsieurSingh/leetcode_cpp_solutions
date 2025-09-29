//
//  0797_all_paths_from_source_to_target.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 29/9/2025.
//

#include "0797_all_paths_from_source_to_target.hpp"

void	Solution::dfs(int u, vector<int> &st, vector<vector<int>> &graph,
					  vector<vector<int>> &res)
{
	st.push_back(u);
	if (u == graph.size() - 1)
		res.push_back(st);
	else
	{
		for (int v = 0; v < graph[u].size(); v++)
			dfs(graph[u][v], st, graph, res);
	}
	st.pop_back();
}

vector<vector<int>>	Solution::allPathsSourceTarget(vector<vector<int>> &graph)
{
	vector<vector<int>>	res;
	vector<int>         st;

	dfs(0, st, graph, res);
	return (res);
}
