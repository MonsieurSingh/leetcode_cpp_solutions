//
//  test_input.hpp
//  cpp_tests
//
//  Created by Teghjyot Singh on 28/9/2025.
//

#ifndef TestInput_hpp
#define TestInput_hpp

#include <string>
#include <vector>

using namespace std;

class TestInput
{
	vector<int>					input_ints;
	vector<string>				raw_arrays;
	static vector<string>		split_top_level_arrays(const string &str);
	static vector<int>			parse_vector_int(const string &str);
	static vector<vector<int>>	parse_matrix_int(const string &str);

public:
	TestInput(void);
	TestInput(const vector<int> &ints, const string &str);
	void				set_inputs(const vector<int> &ints,
								   const string &str);
	const vector<int>	&ints(void) const;
	size_t				array_count(void) const;
	const string		&raw_array(size_t idx) const;
	template<typename T>
	T					get_array(size_t idx) const;
};

template<>
vector<int>
TestInput::get_array<vector<int>>(size_t idx) const;

template<>
vector<vector<int>>
TestInput::get_array<vector<vector<int>>>(size_t idx) const;


#endif /* TestInput_hpp */
