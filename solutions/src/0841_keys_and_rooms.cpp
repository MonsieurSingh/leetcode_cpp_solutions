//
//  0841_keys_and_rooms.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 27/9/2025.
//

#include "0841_keys_and_rooms.hpp"

void	Solution::dfs(int room, vector<bool> &visited, int &count,
					  vector<vector<int>> &adj_list)
{
	visited[room] = true;
	count++;
	for (int j = 0; j < adj_list[room].size(); j++)
	{
		if (!visited[adj_list[room][j]])
			dfs(adj_list[room][j], visited, count, adj_list);
	}
}

bool	Solution::canVisitAllRooms(vector<vector<int>> &rooms)
{
	vector<bool>	visited;
	size_t			n;
	int				count;

	n = rooms.size();
	visited.resize(n, false);
	count = 0;
	dfs(0, visited, count, rooms);
	return (count == n);
}
