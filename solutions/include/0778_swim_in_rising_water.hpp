//
//  0778_swim_in_rising_water.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#ifndef _778_swim_in_rising_water_hpp
#define _778_swim_in_rising_water_hpp

#include <vector>
#include "union_find.hpp"

using namespace std;

class Solution
{
private:
	static const int dirs[4][2];
public:
	int swimInWater(vector<vector<int>>& grid);
	static bool	flood_connect(t_union_find *uf, vector<vector<bool>> &flooded,
							  int i, int j, int n);
};

#endif /* _778_swim_in_rising_water_hpp */
