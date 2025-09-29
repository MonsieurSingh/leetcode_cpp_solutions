//
//  1039_minimum_score_triangulation_of_polygon.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 29/9/2025.
//

#include "1039_minimum_score_triangulation_of_polygon.hpp"

int	Solution::minScoreTriangulation(vector<int> &values)
{
	vector<vector<int>>	dp;
	int					n;

	n = (int)values.size();
	dp.resize(n, vector<int>(n, 0));
	for (int len = 2; len < n; len++)
	{
		for (int i = 0; i + len < n; i++)
		{
			int j = i + len;
			dp[i][j] = INT_MAX;
			for (int k = i + 1; k < j; k++)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] +
							   values[i] * values[j] * values[k]);
		}
	}
	return dp[0][n - 1];
}
