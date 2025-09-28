//
//  1129_shortest_path_with_alternating_colors.mm
//  tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "1129_shortest_path_with_alternating_colors.hpp"
#include "test_input.hpp"


@interface test_1129_shortest_path_with_alternating_colors : XCTestCase
{
	TestInput			input1;
	TestInput			input2;
	TestInput			input3;
	vector<vector<int>>	expected;
}

@end

@implementation test_1129_shortest_path_with_alternating_colors

- (void)setUp
{
	input1.set_inputs({3}, "[[0,1],[1,2]],[]");
	input2.set_inputs({3}, "[[0,1]],[[2,1]]");
	input3.set_inputs({5}, "[[0,1],[1,2],[2,3],[3,4]],[[1,2],[2,3],[3,1]]");
	expected = {
		{0, 1, -1},
		{0, 1, -1},
		{0, 1, 2, 3, 7}
	};
}

- (void)tearDown
{
}

- (void)test_1129
{
	Solution	solution;
	auto n1 = (int)input1.ints().at(0);
	auto red1 = input1.get_array<vector<vector<int>>>(0);
	auto blue1 = input1.get_array<vector<vector<int>>>(1);
	auto result1 = solution.shortestAlternatingPaths(n1, red1, blue1);
	XCTAssertEqual(result1, expected[0]);
	auto n2 = (int)input2.ints().at(0);
	auto red2 = input2.get_array<vector<vector<int>>>(0);
	auto blue2 = input2.get_array<vector<vector<int>>>(1);
	auto result2 = solution.shortestAlternatingPaths(n2, red2, blue2);
	XCTAssertEqual(result2, expected[1]);
	auto n3 = (int)input3.ints().at(0);
	auto red3 = input3.get_array<vector<vector<int>>>(0);
	auto blue3 = input3.get_array<vector<vector<int>>>(1);
	auto result3 = solution.shortestAlternatingPaths(n3, red3, blue3);
	XCTAssertEqual(result3, expected[2]);
}

@end
