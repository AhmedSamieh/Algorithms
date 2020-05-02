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
    unordered_set<ListNode *> setA;
    unordered_set<ListNode *> setB;
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        while (headA != NULL && headB != NULL) {
            setA.insert(headA);
            setB.insert(headB);

            if (setB.find(headA) != setB.end()) {
                return headA;
            }

            if (setA.find(headB) != setA.end()) {
                return headB;
            }

            headA = headA->next;
            headB = headB->next;
        }

        while (headA != NULL) {
            setA.insert(headA);

            if (setB.find(headA) != setB.end()) {
                return headA;
            }

            headA = headA->next;
        }

        while (headB != NULL) {
            setB.insert(headB);

            if (setA.find(headB) != setA.end()) {
                return headB;
            }

            headB = headB->next;
        }

        return NULL;
    }
};