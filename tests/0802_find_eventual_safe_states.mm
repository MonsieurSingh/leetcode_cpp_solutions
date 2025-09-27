//
//  0802_find_eventual_safe_states.mm
//  cpp_tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "../cpp_solutions/include/0802_find_eventual_safe_states.hpp"

@interface test_0802_find_eventual_safe_states : XCTestCase
{
	vector<vector<int>> test_1;
	vector<vector<int>> test_2;
	vector<int>			expected_1;
	vector<int>			expected_2;
}

@end

@implementation test_0802_find_eventual_safe_states

- (void)setUp
{
	test_1 =
	{
		{1, 2},
		{2, 3},
		{5},
		{0},
		{5},
		{},
		{}
	};
	test_2 =
	{
		{1, 2, 3, 4},
		{1, 2},
		{3, 4},
		{0, 4},
		{}
	};
	expected_1 = {2, 4, 5, 6};
	expected_2 = {4};
}

- (void)tearDown
{
}

- (void)test_graphs
{
	vector<int>	result;
	Solution	solution;

	result = solution.eventualSafeNodes(test_1);
	XCTAssertEqual(result, expected_1, @"Expected [2,4,5,6]");
	result = solution.eventualSafeNodes(test_2);
	XCTAssertEqual(result, expected_2, @"Expected [4]");
}

- (void)testPerformanceExample {
    [self measureBlock:^{
		vector<int>	result;
		Solution	solution;

		result = solution.eventualSafeNodes(test_1);
		XCTAssert(result[0] >= 0);
    }];
}

@end
