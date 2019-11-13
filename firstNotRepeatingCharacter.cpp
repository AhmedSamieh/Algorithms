char firstNotRepeatingCharacter(std::string s) {
    std:map<char, int> first_time;
    std::set<char> repeated;
    int index = -1;
    for (int i = 0; i < s.size(); i++)
    {
        if (first_time.find(s[i]) != first_time.end())
        {
            first_time.erase(s[i]);
            repeated.insert(s[i]);
        }
        else if (repeated.find(s[i]) == repeated.end())
        {
            first_time.insert(make_pair(s[i], i));
        }
    }
    for (std::map<char, int>::iterator iter = first_time.begin();
         iter != first_time.end();
         iter++)
    {
        if (index > iter->second || index == -1)
        {
            index = iter->second;
        }
    }
    return (index == -1) ? '_' : s[index];
}