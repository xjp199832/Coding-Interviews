#include <vector>
#include <iostream>
#include <stack>
using namespace std;
/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/

//可以利用栈或者利用递归先打印下一个节点然后在打印本节点
class Solution {
public:

	//栈实现
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arr;
		if (head != NULL)
		{
			stack<int> s;
			while (head != NULL)
			{
				s.push(head->val);
				head = head->next;
			}

			while (!s.empty())
			{
				arr.push_back(s.top());
				s.pop();
			}
		}
		return arr;
	}

	//递归实现
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> arr;
		if (head != NULL)
		{
			if (head->next != NULL)
			{
				printListFromTailToHead(head->next);
			}
			arr.push_back(head->val);
		}
		return arr;
	}
};
