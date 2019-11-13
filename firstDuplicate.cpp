int firstDuplicate(vector<int> a) {
    unordered_set<int> old;
    for (auto iter = a.begin();
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