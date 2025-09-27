//
//  cpp_tests.m
//  cpp_tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "../cpp_solutions/include/0547_number_of_provinces.hpp"

@interface number_of_provinces_test : XCTestCase {
	std::vector<std::vector<int>> test_1;
	std::vector<std::vector<int>> test_2;
}

@end

@implementation number_of_provinces_test

- (void)setUp
{
	test_1 =
	{
		{1, 1, 0},
		{1, 1, 0},
		{0, 0, 1}
	};
	test_2 =
	{
		{1, 0, 0},
		{0, 1, 0},
		{0, 0, 1}
	};
}

- (void)tearDown
{
}

- (void)test_graphs
{
	int			result;
	Solution	solution;

	result = solution.findCircleNum(test_1);
	XCTAssertEqual(result, 2, @"Expected 2 provinces");
	result = solution.findCircleNum(test_2);
	XCTAssertEqual(result, 3, @"Expected 2 provinces");
}

- (void)testPerformanceExample {
    [self measureBlock:^{
		int 		result;
		Solution	solution;

		result = solution.findCircleNum(test_1);
		XCTAssert(result >= 0);
    }];
}

@end
