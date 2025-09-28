//
//  976_largest_perimeter_triangle.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 28/9/2025.
//

#include "976_largest_perimeter_triangle.hpp"

int	Solution::largestPerimeter(vector<int> &nums)
{
	sort(nums.begin(), nums.end());
	for (size_t i = nums.size() - 1; i > 1; i--)
	{
		if (nums[i] < nums[i - 1] + nums[i - 2])
			return (nums[i] + nums[i - 1] + nums[i - 2]);
	}
	return (0);
}
