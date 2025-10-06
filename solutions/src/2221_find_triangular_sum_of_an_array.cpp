//
//  2221_find_triangular_sum_of_an_array.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 30/9/2025.
//

#include "2221_find_triangular_sum_of_an_array.hpp"

int	Solution::triangularSum(vector<int> &nums)
{
	vector<int>	temp;
	int			n;

	n = (int)nums.size();
	temp.resize(n);
	while (n-- > 1)
	{
		for (int i = 0; i < n; i++)
		{
			temp[i] = (nums[i] + nums[i + 1]) % 10;
			nums[i] = temp[i];
		}
	}
	return (nums[0]);
}
