//
//  3100_water_bottles_II.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 2/10/2025.
//

#include "3100_water_bottles_II.hpp"

int	Solution::maxBottlesDrunk(int num_bottles, int num_exchange)
{
	int	b;
	
	b = (2 * num_exchange) - 3;
	return (num_bottles + (int)floor((-b + sqrt((double)b * b + 8.0 * num_bottles)) / (2.0)));
}
