//
//  1129_shortest_path_with_alternating_colors.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 27/9/2025.
//

#include "1129_shortest_path_with_alternating_colors.hpp"
#include <queue>
#include <algorithm>

vector<int>
Solution::shortestAlternatingPaths(int n, vector<vector<int>> &red_edges,
								   vector<vector<int>> &blue_edges)
{
	vector<vector<int>>		distance;
	vector<vector<int>>		red;
	vector<vector<int>>		blue;
	queue<pair<int, int>>	q;
	vector<int>				path;

	red.resize(n);
	blue.resize(n);
	path.resize(n, -1);
	distance.resize(n, vector<int>(2, INT_MAX));
	q.push({0, 0});
	q.push({0, 1});
	distance[0][0] = 0;
	distance[0][1] = 0;
	path[0] = 0;
	for (auto edge : red_edges)
		red[edge[0]].push_back(edge[1]);
	for (auto edge : blue_edges)
		blue[edge[0]].push_back(edge[1]);
	while (!q.empty())
	{
		int u = q.front().first;
		int color = q.front().second;
		q.pop();
		int d = distance[u][color];
		if (color == 0)
		{
			for (int v : blue[u])
			{
				if (distance[v][1] == INT_MAX)
				{
					distance[v][1] = d + 1;
					q.push({v, 1});
				}
			}
		}
		else
		{
			for (int v : red[u])
			{
				if (distance[v][0] == INT_MAX)
				{
					distance[v][0] = d + 1;
					q.push({v, 0});
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		int	best = min(distance[i][0], distance[i][1]);
		if (best == INT_MAX)
			path[i] = -1;
		else
			path[i] = best;
	}
	return (path);
}
