//
//  test_input.cpp
//  cpp_tests
//
//  Created by Teghjyot Singh on 28/9/2025.
//

#include <cctype>
#include <sstream>
#include <stdexcept>
#include "nlohmann/json.hpp"
#include "test_input.hpp"
using json = nlohmann::json;

TestInput::TestInput(void)
{
}

TestInput::TestInput(const vector<int> &ints, const string &str)
{
	set_inputs(ints, str);
}

void
TestInput::set_inputs(const vector<int> &ints, const string &str)
{
	input_ints = ints;
	raw_arrays = split_top_level_arrays(str);
}

const vector<int> &
TestInput::ints(void) const
{
	return (input_ints);
}

size_t
TestInput::array_count(void) const
{
	return (raw_arrays.size());
}

const string &
TestInput::raw_array(size_t idx) const
{
	return (raw_arrays.at(idx));
}

vector<string>
TestInput::split_top_level_arrays(const string &s)
{
	vector<string>	out;
	string			cur;
	int				depth;

	depth = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (c == '[')
		{
			depth++;
			cur += c;
		}
		else if (c == ']')
		{
			depth--;
			cur += c;
			if (depth == 0)
			{
				out.push_back(cur);
				cur.clear();
			}
		}
		else
		{
			if (depth == 0)
			{
				if (isspace(static_cast<unsigned char>(c)) ||
					c == ',')
					continue;
			}
			cur += c;
		}
	}
	return (out);
}

vector<int>
TestInput::parse_vector_int(const string &s)
{
	vector<int>	res;
	size_t		i;
	size_t		j;

	i = 0;
	while (i < s.size() && s[i] != '[')
		i++;
	j = s.find_last_of(']');
	if (j == string::npos || j <= i)
		return (res);
	string inside = s.substr(i + 1, j - i - 1);
	stringstream ss(inside);
	string token;
	
	while (getline(ss, token, ','))
	{
		size_t a = token.find_first_not_of(" \t\n\r");
		if (a == string::npos)
			continue;
		size_t b = token.find_last_not_of(" \t\n\r");
		string tok = token.substr(a, b - a + 1);
		if (!tok.empty())
			res.push_back(stoi(tok));
	}
	return (res);
}

vector<vector<int>>
TestInput::parse_matrix_int(const string &s)
{
	vector<vector<int>> out;
	int                           depth = 0;
	string                   cur;
	size_t                   i;
	
	for (i = 0; i < s.size(); ++i)
	{
		char c = s[i];
		if (c == '[')
		{
			depth++;
			if (depth >= 2)
				cur += c;
		}
		else if (c == ']')
		{
			if (depth >= 2)
				cur += c;
			depth--;
			if (depth == 1 && !cur.empty())
			{
				out.push_back(parse_vector_int(cur));
				cur.clear();
			}
		}
		else
		{
			if (depth >= 2)
				cur += c;
		}
	}
	return (out);
}

template<>
vector<int>
TestInput::get_array<vector<int>>(size_t idx) const
{
	json	j;

	j = json::parse(raw_arrays.at(idx));
	return (j.get<vector<int>>());
}

template<>
vector<vector<int>>
TestInput::get_array<vector<vector<int>>>(size_t idx) const
{
	json	j;

	j = json::parse(raw_arrays.at(idx));
	return (j.get<vector<vector<int>>>());
}
