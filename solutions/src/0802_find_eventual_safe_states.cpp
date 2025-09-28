//
//  0802_find_eventual_safe_states.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 27/9/2025.
//

#include "0802_find_eventual_safe_states.hpp"

bool	Solution::dfs(int v, vector<int> &state,
					  const vector<vector<int>>& graph)
{
	if (v >= graph.size() || state[v] == 1)
		return (false);
	if (state[v] == 2)
		return (true);
	state[v] = 1;
	for (int neighbor : graph[v])
	{
		if (!dfs(neighbor, state, graph))
			return (false);
	}
	state[v] = 2;
	return (true);
}

vector<int>	Solution::eventualSafeNodes(vector<vector<int>>& graph)
{
	vector<int>	state;
	vector<int>	stack;
	size_t		n;

	n = graph.size();
	state.resize(n, 0);
	for (int i = 0; i < n; i++)
	{
		if (dfs(i, state, graph))
			stack.push_back(i);
	}
	return (stack);
}
