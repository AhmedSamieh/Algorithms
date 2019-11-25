/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    stack<int> x;
    stack<int> y;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = NULL;
        ListNode* node;
        int result = 0;
        for (auto iter = l1; iter != NULL; iter = iter->next)
        {
            x.push(iter->val);
        }
        for (auto iter = l2; iter != NULL; iter = iter->next)
        {
            y.push(iter->val);
        }
        while (!x.empty() && !y.empty())
        {
            result += x.top() + y.top();
            node = new ListNode(result % 10);
            node->next = head;
            head = node;
            result /= 10;
            x.pop();
            y.pop();
        }
        while (!x.empty())
        {
            result += x.top();
            node = new ListNode(result % 10);
            node->next = head;
            head = node;
            result /= 10;
            x.pop();
        }
        while (!y.empty())
        {
            result += y.top();
            node = new ListNode(result % 10);
            node->next = head;
            head = node;
            result /= 10;
            y.pop();
        }
        if (result > 0)
        {
            node = new ListNode(result);
            node->next = head;
            head = node;
        }
        return head;
    }
};