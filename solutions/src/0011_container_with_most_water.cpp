//
//  0011_container_with_most_water.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#include "0011_container_with_most_water.hpp"

using namespace std;

int	Solution::maxArea(vector<int> &height)
{
	int	max_area;
	int	i;
	int	j;
	int	area;
	int	majorant_height;

	i = 0;
	j = (int)height.size() - 1;
	max_area = 0;
	while (i < j)
	{
		majorant_height = min(height[i], height[j]);
		area = majorant_height * (j - i);
		if (area > max_area)
			max_area = area;
		while(i < j && height[i] <= majorant_height)
			i++;
		while(i < j && height[j] <= majorant_height)
			j--;
	}
	return (max_area);
}
