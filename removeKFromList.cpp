// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> *removeKFromList(ListNode<int> *l, int k)
{
    ListNode<int> **item = &l;

    while (*item) {
        if ((*item)->value == k) {
            (*item) = (*item)->next;
        } else {
            item = &(*item)->next;
        }
    }

    return l;
}