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
    bool isPalindrome(ListNode* head) {
        // get length O(N)
        // inverse length/2 of the lined list O(N)
        // compare O(N)
        int length = 0;
        for (ListNode* iter = head; NULL != iter; iter = iter->next, ++length);
        int to_be_inverted = length / 2;
        ListNode* iter = head;
        ListNode* next = NULL;
        ListNode* riter = NULL;
        int i = 0;
        while (i < to_be_inverted) {
            ++i;
            next = iter->next;
            iter->next = riter;
            riter = iter;
            iter = next;
        }
        if (length & 1) {
            iter = iter->next;
        }
        while (NULL != iter && NULL != riter) {
            if (iter->val != riter->val) {
                return false;
            }
            iter = iter->next;
            riter = riter->next;
        }
        return true;
    }
};