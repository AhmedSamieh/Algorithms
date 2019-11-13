// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
bool isListPalindrome(ListNode<int> * l) {
    std::list<int> rev_list;
    ListNode<int> *fast = l, *slow = l;
    while (fast)
    {
        if (fast->next != nullptr)
        {
            fast = fast->next->next;
        }
        else
        {
            fast = fast->next;
        }
        slow = slow->next;
    }
    while (slow)
    {
        rev_list.push_front(slow->value);
        slow = slow->next;
    }
    slow = l;
    for (std::list<int>::iterator iter = rev_list.begin();
         iter != rev_list.end();
         iter++, slow = slow->next)
    {
        if (slow->value != *iter)
        {
            return false;
        }
    }
    return true;
}