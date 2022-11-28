struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
	
};
ListNode* reserve(ListNode* head)
{
	if (head == nullptr) return head;
	ListNode*last = nullptr;
	ListNode* cur = head;
	ListNode* pre = head->next;
	while (cur)
	{
		cur->next = last;
		last = cur;
		cur = pre;
		if (pre) pre = pre->next;
	}
	return last;
}
bool isPalindrome(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	while (fast && fast->next)
	{
		fast = fast->next->next;
		slow = slow->next;
	}
	ListNode* R = reserve(slow);
	while (head && R)
	{
		if (head->val != R->val) return false;
		head = head->next;
		R = R->next;
	}
	return true;
}
