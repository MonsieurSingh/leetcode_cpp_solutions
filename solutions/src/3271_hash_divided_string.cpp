//
//  3271_hash_divided_string.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 1/10/2025.
//

#include "3271_hash_divided_string.hpp"

string
Solution::stringHash(string s, int k)
{
	int		n;
	int		hash;
	string	result;

	n = (int)s.length();
	result.resize(n / k);
	hash = 0;
	for (int i = 0; i < n; i++)
	{
		hash += s[i] - 'a';
		if (i && (i + 1) % k == 0)
		{
			result[i / k] = (hash % 26) + 'a';
			hash = 0;
		}
	}
	return (result);
}
