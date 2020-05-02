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
    ListNode *reverseListHelper(ListNode *node, ListNode *prev)
    {
        ListNode *next = node->next;
        node->next = prev;

        if (NULL == next) {
            return node;
        } else {
            return reverseListHelper(next, node);
        }
    }
public:
    ListNode *reverseList(ListNode *head)
    {
        if (NULL == head) {
            return NULL;
        }

        return reverseListHelper(head, NULL);
    }
};