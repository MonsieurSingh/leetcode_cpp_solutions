//
//  0802_find_eventual_safe_states.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 27/9/2025.
//

#ifndef _802_find_eventual_safe_states_hpp
#define _802_find_eventual_safe_states_hpp

#include <vector>

using namespace std;

class Solution
{
public:
	bool		dfs(int v, vector<int> &state,
				const vector<vector<int>>& graph);
	vector<int>	eventualSafeNodes(vector<vector<int>>& graph);
};


#endif /* _802_find_eventual_safe_states_hpp */
