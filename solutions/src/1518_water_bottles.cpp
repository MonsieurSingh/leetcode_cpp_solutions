//
//  1518_water_bottles.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 1/10/2025.
//

#include "1518_water_bottles.hpp"

int	Solution::numWaterBottles(int b, int n)
{
	return (b + ((b - 1) / (n - 1)));
}
