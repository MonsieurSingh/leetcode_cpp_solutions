//
//  0407_trapping_rain_water_II.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 6/10/2025.
//

#ifndef _407_trapping_rain_water_II_hpp
#define _407_trapping_rain_water_II_hpp

#include <vector>
#include <queue>

class Solution
{
private:
	static const int 	directions[4][2];
	typedef struct		s_cell
	{
		int	height;
		int	x;
		int	y;
		bool operator>(const s_cell& other) const;
	}	t_cell;
	bool				is_valid_cell(int x, int y, int m, int n, const
									  std::vector<std::vector<bool>> &visited);
	void	push_boundary(const std::vector<std::vector<int>>& height_map,
						  std::vector<std::vector<bool>>& visited,
						  std::priority_queue<t_cell, std::vector<t_cell>,
						  std::greater<t_cell>>& pq);
	int		process_cell(std::priority_queue<t_cell, std::vector<t_cell>,
						 std::greater<t_cell>>& pq,
						 std::vector<std::vector<int>>& height_map,
						 std::vector<std::vector<bool>>& visited);
	
public:
	int	trapRainWater(std::vector<std::vector<int>>& height_map);
};

#include <stdio.h>

#endif /* _407_trapping_rain_water_II_hpp */
