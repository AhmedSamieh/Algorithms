class Solution {
public:
    string reverseWords(string s) {
        string rs;
        string word;
        for (auto &c : s)
        {
            if (c == ' ')
            {
                if (word.size() > 0)
                {
                    rs = (rs.size() > 0) ? word + " " + rs : word;
                    word.clear();
                }
            }
            else
            {
                word.push_back(c);
            }
        }
        if (word.size() > 0)
        {
            rs = (rs.size() > 0) ? word + " " + rs : word;
        }
        return rs;
    }
};
