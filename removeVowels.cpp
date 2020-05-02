class Solution
{
public:
    string removeVowels(string S)
    {
        const char vowels[] = {'a', 'e', 'i', 'o', 'u'};
        unordered_set<char> v(vowels, vowels + sizeof(vowels));
        string ret;

        for (auto &c : S) {
            if (v.find(c) == v.end()) {
                ret.push_back(c);
            }
        }

        return ret;
    }
};
