//
//  0547_number_of_provinces.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#ifndef _547_number_of_provinces_hpp
#define _547_number_of_provinces_hpp

#include <vector>

using namespace std;

class Solution
{
public:
	void	dfs(int v, vector<bool> &visited,
				const vector<vector<int>>& graph);
	int		findCircleNum(vector<vector<int>>& is_connected);
};

#endif /* _547_number_of_provinces_hpp */
