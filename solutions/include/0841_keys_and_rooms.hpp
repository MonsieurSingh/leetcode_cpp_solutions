//
//  0841_keys_and_rooms.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 27/9/2025.
//

#ifndef _841_keys_and_rooms_hpp
#define _841_keys_and_rooms_hpp

#include <vector>

using namespace std;

class Solution {
public:
	void	dfs(int room, vector<bool> &visited, int &count,
				vector<vector<int>>& adj_list);
	bool	canVisitAllRooms(vector<vector<int>> &rooms);
};

#endif /* _841_keys_and_rooms_hpp */
