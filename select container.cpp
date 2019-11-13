enum {
    LAST_IN_FIRST_OUT,
    FIRST_IN_FIRST_OUT,
    LARGEST_ELEMENT_FIRST_OUT,
    ANY
};
string select_container(uint32_t order,
                        bool sortByKey,
                        bool searchByKey,
                        bool duplicatesIsAllowed,
                        bool storeKeySeparateToValue,
                        bool middleInsertErase,
                        bool mergeRequired,
                        bool frontInsertErase,
                        bool bothDirectionsIterate)
{
    string best_option;
    if (LAST_IN_FIRST_OUT  == order)
    {
        best_option = "stack";
    }
    else if (FIRST_IN_FIRST_OUT == order)
    {
        best_option = "queue";
    }
    else if (LARGEST_ELEMENT_FIRST_OUT == order)
    {
        best_option = "priority_queue";
    }
    else if (sortByKey || searchByKey)
    {
        if (duplicatesIsAllowed)
        {
            best_option = storeKeySeparateToValue ? "multimap" : "multiset";
        }
        else
        {
            best_option = storeKeySeparateToValue ? "map" : "set";
        }
    }
    else if (middleInsertErase || mergeRequired)
    {
        best_option = bothDirectionsIterate ? "list" : "forward_list";
    }
    else
    {
        best_option = frontInsertErase ? "deque" : "vector";
    }
    return best_option;
}