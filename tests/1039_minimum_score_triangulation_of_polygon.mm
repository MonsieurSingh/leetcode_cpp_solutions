//
//  1039_minimum_score_triangulation_of_polygon.mm
//  tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "1039_minimum_score_triangulation_of_polygon.hpp"
#include "test_input.hpp"


@interface test_1039_minimum_score_triangulation_of_polygon : XCTestCase
{
	TestInput			input1;
	TestInput			input2;
	TestInput			input3;
	vector<int>			expected;
}

@end

@implementation test_1039_minimum_score_triangulation_of_polygon

- (void)setUp
{
	input1.set_inputs({3}, "[1,2,3]");
	input2.set_inputs({4}, "[3,7,4,5]");
	input3.set_inputs({6}, "[1,3,1,4,1,5]");
	expected = {6, 144, 13};
}

- (void)tearDown
{
}

- (void)test_1039
{
	Solution	solution;
	auto i1 = input1.get_array<vector<int>>(0);
	auto result1 = solution.minScoreTriangulation(i1);
	XCTAssertEqual(result1, expected[0]);
	auto i2 = input2.get_array<vector<int>>(0);
	auto result2 = solution.minScoreTriangulation(i2);
	XCTAssertEqual(result2, expected[1]);
	auto i3 = input3.get_array<vector<int>>(0);
	auto result3 = solution.minScoreTriangulation(i3);
	XCTAssertEqual(result3, expected[2]);
}

@end
