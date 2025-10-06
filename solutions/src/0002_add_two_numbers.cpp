//
//  0002_add_two_numbers.cpp
//  cpp_solutions
//
//  Created by Teghjyot Singh on 1/10/2025.
//

#include "0002_add_two_numbers.hpp"

ListNode	*Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode	*head;
	ListNode	*current;
	int			carry;

	head = new ListNode(0);
	current = head;
	carry = 0;
	while (l1 || l2 || carry)
	{
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		int sum = val1 + val2 + carry;

		carry = sum / 10;
		current->next = new ListNode(sum % 10);
		current = current->next;
		if (l1)
			l1 = l1->next;
		if (l2)
			l2 = l2->next;
	}
	return (head->next);
}
