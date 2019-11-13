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
    bool hasCycle(ListNode *head) {
        // Cycle detection using Floyd's cycle-finding algorithm (Tortoise and hare)
        if (head != NULL)
        {
            ListNode *tortoise = head, *hare = head->next;
            while (hare != NULL && hare->next != NULL)
            {
                tortoise = tortoise->next;
                hare = hare->next->next;
                if (tortoise == hare)
                {
                    return true;
                }
            }
        }
        return false;
    }
};
