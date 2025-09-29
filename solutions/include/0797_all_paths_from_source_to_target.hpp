//
//  0797_all_paths_from_source_to_target.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 29/9/2025.
//

#ifndef _797_all_paths_from_source_to_target_hpp
#define _797_all_paths_from_source_to_target_hpp

#include <vector>

using namespace std;

class Solution
{
public:
	void    dfs(int u, vector<int> &st, vector<vector<int>> &graph,
				vector<vector<int>> &res);
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph);
};

#endif /* _797_all_paths_from_source_to_target_hpp */
