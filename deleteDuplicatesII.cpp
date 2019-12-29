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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode** p_head = &head;
        while (NULL != *p_head) {
            ListNode** p_tail = &(*p_head)->next;
            while (NULL != *p_tail && (*p_head)->val == (*p_tail)->val) {
                p_tail = &(*p_tail)->next;
            }
            if ((*p_head)->next != *p_tail) {
                *p_head = *p_tail;
            }
            else {
                 p_head = &(*p_head)->next;
            }
        }
        return head;
    }
};
