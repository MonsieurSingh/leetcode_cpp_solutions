//
//  0841_keys_and_rooms.mm
//  tests
//
//  Created by Teghjyot Singh on 25/9/2025.
//

#import <XCTest/XCTest.h>
#include "0841_keys_and_rooms.hpp"

@interface test_0841_keys_and_rooms : XCTestCase
{
	vector<vector<int>> test_1;
	vector<vector<int>> test_2;
	bool				expected_1;
	bool				expected_2;
}

@end

@implementation test_0841_keys_and_rooms

- (void)setUp
{
	test_1 =
	{
		{1},
		{2},
		{3},
		{}
	};
	test_2 =
	{
		{1, 3},
		{3, 0, 1},
		{2},
		{0}
	};
	expected_1 = true;
	expected_2 = false;
}

- (void)tearDown
{
}

- (void)test_0841
{
	bool		result;
	Solution	solution;

	result = solution.canVisitAllRooms(test_1);
	XCTAssertTrue(result);
	result = solution.canVisitAllRooms(test_2);
	XCTAssertFalse(result);
}

@end
