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
        for (ListNode** p_head = &head; NULL != *p_head; p_head = &(*p_head)->next) {
            ListNode* next_node = (*p_head)->next;
            while (NULL != next_node && (*p_head)->val == next_node->val) {
                (*p_head)->next = next_node->next;
                delete next_node;
                next_node = (*p_head)->next;
            }
        }
        return head;
    }
};