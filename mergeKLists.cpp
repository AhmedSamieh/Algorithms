/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == NULL)
        {
            return l2;
        }
        if (l2 == NULL)
        {
            return l1;
        }
        if (l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
        {
            return NULL;
        }
        else
        {
            ListNode* list =  lists[0];
            for (int i = 1; i < lists.size(); i++)
            {
                list = mergeTwoLists(list, lists[i]);
            }
            return list;
        }
    }
};