//
//  0002_add_two_numbers.hpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 1/10/2025.
//

#ifndef _002_add_two_numbers_hpp
#define _002_add_two_numbers_hpp

struct ListNode
{
	int			val;
	ListNode	*next;
	ListNode();
	ListNode(int x);
	ListNode(int x, ListNode *next);
};

ListNode::ListNode() : val(0), next(nullptr) {}
ListNode::ListNode(int x) : val(x), next(nullptr) {};
ListNode::ListNode(int x, ListNode *next) : val(x), next(next) {};

class Solution
{
public:
	ListNode	*addTwoNumbers(ListNode* l1, ListNode* l2);
};

#endif /* _002_add_two_numbers_hpp */
