int firstDuplicate(std::vector<int> a) {
    std::set<int> old;
    for (std::vector<int>::iterator iter = a.begin();
        iter != a.end();
        iter++)
    {
        if (old.find(*iter) != old.end())
        {
            return *iter;
        }
        else
        {
            old.insert(*iter);
        }
    }
    return -1;
}