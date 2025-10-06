//
//  0417_pacific_atlantic_water_flow.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#ifndef _417_pacific_atlantic_water_flow_hpp
#define _417_pacific_atlantic_water_flow_hpp

#include <vector>

class Solution
{
private:
	static const int 	directions[4][2];
	void				dfs(int i, int j,
							std::vector<std::vector<int>>& heights,
							std::vector<std::vector<bool>>& visited);
public:
	std::vector<std::vector<int>>
	pacificAtlantic(std::vector<std::vector<int>> &heights);
};


#endif /* _417_pacific_atlantic_water_flow_hpp */
