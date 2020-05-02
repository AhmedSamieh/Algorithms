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
    multimap<int, ListNode *> ds;
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *root = NULL;
        ListNode **p_root = &root;

        for (auto &i : lists) {
            if (NULL != i) {
                ds.emplace(i->val, i);
            }
        }

        while (!ds.empty()) {
            auto i = ds.begin();
            *p_root = i->second;
            ds.erase(i);

            if (NULL != (*p_root)->next) {
                ds.emplace((*p_root)->next->val, (*p_root)->next);
            }

            p_root = &(*p_root)->next;
        }

        *p_root = NULL;
        return root;
    }
};
