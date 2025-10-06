//
//  0417_pacific_atlantic_water_flow.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#include "0417_pacific_atlantic_water_flow.hpp"

using namespace std;

const int Solution::directions[4][2] =
{
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

vector<vector<int>>
Solution::pacificAtlantic(vector<vector<int>> &heights)
{
	int						n;
	int						m;
	vector<vector<bool>>	pacific;
	vector<vector<bool>>	atlantic;
	vector<vector<int>>		result;

	m = (int)heights.size();
	n = (int)heights[0].size();
	pacific.resize(m, vector<bool>(n, false));
	atlantic.resize(m, vector<bool>(n, false));
	for (int j = 0; j < n; j++)
		dfs(0, j, heights, pacific);
	for (int i = 0; i < m; i++)
		dfs(i, 0, heights, pacific);
	for (int j = 0; j < n; j++)
		dfs(m - 1, j, heights, atlantic);
	for (int i = 0; i < m; i++)
		dfs(i, n - 1, heights, atlantic);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (pacific[i][j] && atlantic[i][j])
				result.push_back({i, j});
		}
	}
	return (result);
}

void
Solution::dfs(int i, int j, vector<vector<int>> &heights, vector<vector<bool>>& visited)
{
	int	x;
	int	y;
	int	n;
	int	m;

	visited[i][j] = true;
	m = (int)visited.size();
	n = (int)visited[0].size();
	for (auto &d : directions)
	{
		x = i + d[0];
		y = j + d[1];
		if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y])
			continue;
		if (heights[x][y] < heights[i][j])
			continue;
		dfs(x, y, heights, visited);
	}
}
