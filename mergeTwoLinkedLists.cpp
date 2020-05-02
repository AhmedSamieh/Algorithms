// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> *mergeTwoLinkedLists(ListNode<int> *l1, ListNode<int> *l2)
{
    ListNode<int> *l3;
    ListNode<int> **l3_ptr = &l3;

    while (l1 != nullptr || l2 != nullptr) {
        (*l3_ptr) = new ListNode<int>;

        if (l1 != nullptr && l2 != nullptr) {
            if (l1->value < l2->value) {
                (*l3_ptr)->value = l1->value;
                l1 = l1->next;
            } else {
                (*l3_ptr)->value = l2->value;
                l2 = l2->next;
            }
        } else if (l1 != nullptr) {
            (*l3_ptr)->value = l1->value;
            l1 = l1->next;
        } else {
            (*l3_ptr)->value = l2->value;
            l2 = l2->next;
        }

        l3_ptr = &((*l3_ptr)->next);
    }

    (*l3_ptr) = NULL;
    return l3;
}
