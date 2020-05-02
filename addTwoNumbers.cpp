/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
    ListNode *addTwoNumbersHelper(ListNode *l1, ListNode *l2, int c)
    {
        int result;
        ListNode *node = NULL;

        if (NULL != l1 && NULL != l2) {
            result = l1->val + l2->val + c;
            node = new ListNode(result % 10);
            node->next = addTwoNumbersHelper(l1->next, l2->next, result / 10);
        } else if (NULL != l1) {
            result = l1->val + c;
            node = new ListNode(result % 10);
            node->next = addTwoNumbersHelper(l1->next, NULL, result / 10);
        } else if (NULL != l2) {
            result = l2->val + c;
            node = new ListNode(result % 10);
            node->next = addTwoNumbersHelper(NULL, l2->next, result / 10);
        } else {
            if (c > 0) {
                node = new ListNode(c);
            }
        }

        return node;
    }
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        return addTwoNumbersHelper(l1, l2, 0);
    }
};