// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
#define PRINTF(...)
//#define PRINTF printf
ListNode<int> * reverseNodesInKGroups(ListNode<int> * l, int k) {
    if (k > 1)
    {
        ListNode<int> **pp = &l;
        ListNode<int> *prev, *current, *next, *new_prev;
        int groups = 0;
        for (current = l; current != nullptr; current = current->next)
        {
            groups++;
        }
        groups /= k;
        for (int group = 0; group < groups; group++)
        {
            prev = (*pp);
            PRINTF("[prev] %d\n", prev->value);
            current = prev->next;
            PRINTF("[current] %d\n", current->value);
            next = current->next;
            if (next != nullptr)
            {
                PRINTF("[next] %d\n", next->value);
            }
            for (int i = 0; i < (k - 1) && current != nullptr; i++)
            {
                PRINTF("..\n");
                current->next = prev;
                PRINTF("[current] %d will point to [prev] %d\n", current->value, prev->value);
                prev = current;
                PRINTF("[current] %d will be [prev]\n", current->value);
                current = next;
                if (current != nullptr)
                {
                    PRINTF("[next] %d will be [current] 0x%p\n", next->value, next->next);
                    next = current->next;
                    if (next != nullptr)
                    {
                        PRINTF("new [next] %d\n", next->value);
                    }
                    else
                    {
                        PRINTF("nullptr\n");
                    }
                }
            }
            (*pp)->next = current;
            if (current != nullptr)
            {
                PRINTF("fix the first element [head] %d to point to next [head] %d\n", (*pp)->value, current->value);
            }
            else
            {
                PRINTF("fix the first element [head] %d to point to nullptr\n", (*pp)->value);
            }
            new_prev = (*pp);
            PRINTF("save current [head] %d, from now will be current [tail]\n", new_prev->value);
            (*pp) = prev;
            PRINTF("current [head] replaced with fixed [head] %d\n", (*pp)->value);
            prev = new_prev;
            if (prev != nullptr)
            {
                PRINTF("restore current [tail] to [prev] %d\n", prev->value);
                pp = &(prev->next);
                if ((*pp) != nullptr)
                {
                    PRINTF("move [head] to the next group [head] %d\n", (*pp)->value);
                }
            }
            PRINTF("----------------------------------------\n");
        }
    }
    return l;
}