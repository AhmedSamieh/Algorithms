char firstNotRepeatingCharacter(string s)
{
    unordered_map<char, int> first_time; // character, index
    unordered_set<char> repeated; // character
    int index = s.size();

    for (int i = 0; i < s.size(); i++) {
        if (first_time.find(s[i]) != first_time.end()) {
            first_time.erase(s[i]);
            repeated.insert(s[i]);
        } else if (repeated.find(s[i]) == repeated.end()) {
            first_time.emplace(s[i], i);
        }
    }

    for (auto iter = first_time.begin();
         iter != first_time.end();
         iter++) {
        if (iter->second < index) {
            index = iter->second;
        }
    }

    return (index == s.size()) ? '_' : s[index];
}