// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * addTwoHugeNumbers(ListNode<int> * a, ListNode<int> * b) {
    std::list<int> rev_a;
    std::list<int> rev_b;
    std::list<int> rev_c;
    std::list<int>::iterator iter_a;
    std::list<int>::iterator iter_b;
    ListNode<int> *c;
    ListNode<int> **c_ptr = &c;
    int carry_in = 0;
    for (ListNode<int> *item = a; item != nullptr; item = item->next)
    {
        rev_a.push_front(item->value);
    }
    //printf("%d ", rev_a.size());
    for (ListNode<int> *item = b; item != nullptr; item = item->next)
    {
        rev_b.push_front(item->value);
    }
    //printf("%d ", rev_b.size());
    for (iter_a = rev_a.begin(), iter_b = rev_b.begin();
         iter_a != rev_a.end() || iter_b != rev_b.end();)
    {
        if (iter_a != rev_a.end())
        {
            carry_in += *iter_a;
            iter_a++;
        }
        if (iter_b != rev_b.end())
        {
            carry_in += *iter_b;
            iter_b++;
        }
        rev_c.push_front(carry_in % 10000);
        carry_in /= 10000;
    }
    if (carry_in > 0 || rev_c.size() == 0)
    {
        rev_c.push_front(carry_in);
    }
    //printf("%d ", rev_c.size());
    for (std::list<int>::iterator iter = rev_c.begin();
         iter != rev_c.end();
         iter++)
    {
        //printf("%d ", *iter);
        *c_ptr = new ListNode<int>;
        (*c_ptr)->value = *iter;
        c_ptr = &((*c_ptr)->next);
    }
    *c_ptr = NULL;
    /*for (ListNode<int> *item = c; item != NULL; item = item->next)
    {
        printf("%d ", item->value);
    }*/
    return c;
}