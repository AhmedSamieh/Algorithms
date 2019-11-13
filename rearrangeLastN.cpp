//#define PRINTF printf
#define PRINTF(...)
// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * rearrangeLastN(ListNode<int> * l, int n) {
    if (n > 0)
    {
        ListNode<int> **last = &l, **pre_first = &l;
        ListNode<int> *new_head;
        int i = 0;
        for (i = 0; i < n && (*last) != nullptr; i++)
        {
            last = &((*last)->next);
        if ((*last) != nullptr)
        {
                PRINTF(" %d ... (*last)->value = %d, ->next = %p\n", i, (*last)->value, (*last)->next);
        }
        else
        {
        PRINTF("nullptr\n");
        }
        }
        if ((*last) == nullptr)
        {
            PRINTF("nullptr\n");
            return l;
        }
        PRINTF("(*last)->value = %d\n", (*last)->value);
        while ((*last)->next != nullptr)
        {
            last  = &((*last)->next);
            pre_first = &((*pre_first)->next);
        }
        PRINTF("(*last)->value = %d, ->next = %p\n", (*last)->value, (*last)->next);
        (*last)->next = l;
        PRINTF("(*pre_first)->value = %d\n", (*pre_first)->value);
        new_head = (*pre_first)->next;
        PRINTF("new_head->value = %d\n", new_head->value);
        (*pre_first)->next = nullptr;
        return new_head;
    }
    else
    {
        return l;
    }
}