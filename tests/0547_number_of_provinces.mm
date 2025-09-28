//
//  0547_number_of_provinces.mm
//  tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "0547_number_of_provinces.hpp"

@interface test_0547_number_of_provinces : XCTestCase {
	std::vector<std::vector<int>> test_1;
	std::vector<std::vector<int>> test_2;
}

@end

@implementation test_0547_number_of_provinces

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

- (void)test_0547
{
	int			result;
	Solution	solution;

	result = solution.findCircleNum(test_1);
	XCTAssertEqual(result, 2, @"Expected 2 provinces");
	result = solution.findCircleNum(test_2);
	XCTAssertEqual(result, 3, @"Expected 2 provinces");
}

@end
