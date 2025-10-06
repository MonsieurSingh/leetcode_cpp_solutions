//
//  0778_swim_in_rising_water.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#include "0778_swim_in_rising_water.hpp"

const int Solution::dirs[4][2] =
{
	{1, 0}, {-1, 0}, {0, 1}, {0, -1}
};

static bool	in_bounds(int x, int y, int n)
{
	return (x >= 0 && y >= 0 && x < n && y < n);
}

static vector<tuple<int, int, int>>
build_heights(const vector<vector<int>>& grid)
{
	int							n;
	vector<tuple<int,int,int>>	heights;

	n = (int)grid.size();
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			heights.push_back({grid[i][j], i, j});
	sort(heights.begin(), heights.end());
	return (heights);
}


bool	Solution::flood_connect(t_union_find *uf, vector<vector<bool>> &flooded,
int i, int j, int n)
{
	flooded[i][j] = true;
	for (auto &d : dirs)
	{
		int	x = i + d[0];
		int	y = j + d[1];
		if (in_bounds(x, y, n) && flooded[x][y])
			uf_union(uf, i * n + j, x * n + y);
	}
	return (uf_find(uf, 0) == uf_find(uf, (n - 1) * n + (n - 1)));
}

int Solution::swimInWater(vector<vector<int>>& grid)
{
	int								n;
	vector<tuple<int, int, int>>	heights;
	t_union_find					*uf;
	vector<vector<bool>>			flooded;

	n = (int)grid.size();
	heights = build_heights(grid);
	uf = uf_create(n * n);
	flooded.resize(n, vector<bool>(n, false));
	for (auto &[height, i, j] : heights)
	{
		if (flood_connect(uf, flooded, i, j, n))
			return (height);
	}
	return (-1);
}
