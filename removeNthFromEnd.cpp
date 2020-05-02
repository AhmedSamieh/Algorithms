/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/*[1 2 3 4 5], 2
5 - 2 = 3
0 - > pp 1
1 - > pp 2
2 - > pp 3
3 - > pp 4

*/

class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        int count = 0;

        for (ListNode *iter = head; NULL != iter; ++count, iter = iter->next);

        if (count == n) {
            ListNode *new_head = head->next;
            delete head;
            return new_head;
        } else if (count > n) {
            count = count - n;
            int i;
            ListNode **iter;

            for (iter = &head, i = 0; i < count; ++i, iter = &(*iter)->next);

            ListNode *node_to_delete = *iter;
            *iter = (*iter)->next;
            delete node_to_delete;
        }

        return head;
    }
};