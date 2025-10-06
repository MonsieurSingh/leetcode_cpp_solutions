//
//  0407_trapping_rain_water_II.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#include "0407_trapping_rain_water_II.hpp"

using namespace std;

bool Solution::s_cell::operator>(const s_cell& other) const
{
	return height > other.height;
}

const int Solution::directions[4][2] =
{
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

bool
Solution::is_valid_cell(int x, int y, int m, int n,
						   const vector<vector<bool>> &visited)
{
	return x >= 0 && y >= 0 && x < m && y < n && !visited[x][y];
}

void
Solution::push_boundary(const std::vector<std::vector<int>>& height_map,
								 std::vector<std::vector<bool>>& visited,
								 std::priority_queue<t_cell, std::vector<t_cell>,
								 std::greater<t_cell>>& pq)
{
	int n;
	int m;

	m = (int)height_map.size();
	n = (int)height_map[0].size();
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i == 0 || j == 0 || i == m - 1 || j == n - 1)
			{
				pq.push({height_map[i][j], i, j});
				visited[i][j] = true;
			}
		}
	}
}

int	Solution::process_cell(std::priority_queue<t_cell, std::vector<t_cell>,
						  std::greater<t_cell>>& pq,
						  std::vector<std::vector<int>>& height_map,
						  std::vector<std::vector<bool>>& visited)
{
	int 	n;
	int		m;
	t_cell	current;
	int		volume;

	current = pq.top();
	pq.pop();
	m = (int)height_map.size();
	n = (int)height_map[0].size();
	volume = 0;
	for (auto &d : directions)
	{
		int new_x = current.x + d[0];
		int new_y = current.y + d[1];
		if (!is_valid_cell(new_x, new_y, m, n, visited))
			continue;
		visited[new_x][new_y] = true;
		int new_height = height_map[new_x][new_y];
		if (new_height < current.height)
			volume += current.height - new_height;
		int effective_height = max(current.height, new_height);
		pq.push({effective_height, new_x, new_y});
	}
	return (volume);
}

int	Solution::trapRainWater(vector<vector<int>> &height_map)
{
	int 													n;
	int														m;
	priority_queue<t_cell, vector<t_cell>, greater<t_cell>> pq;
	vector<vector<bool>>									visited;
	int														volume;

	m = (int)height_map.size();
	n = (int)height_map[0].size();
	visited.resize(m, std::vector<bool>(n, false));
	push_boundary(height_map, visited, pq);
	volume = 0;
	while (!pq.empty())
		volume += process_cell(pq, height_map, visited);
	return (volume);
}
