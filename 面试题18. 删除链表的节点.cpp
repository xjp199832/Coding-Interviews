//给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
//返回删除后的链表的头节点。

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        if (head->val == val)
            return head->next;
        ListNode* p = head;
        ListNode* pre = head;
        while (p != nullptr && p->val != val)
        {
            pre = p;
            p = p->next;
        }

        if (p->next == NULL)
        {
            pre->next = pre->next->next;
        }
        else {
            p->val = p->next->val;
            p->next = p->next->next;
        }
        return head;
    }
};