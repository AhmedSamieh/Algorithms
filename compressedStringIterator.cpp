class StringIterator
{
    vector<pair<char, int>> st;
    size_t index;
public:
    StringIterator(string compressedString) : index(0)
    {
        bool hasNewChar = false;
        char newChar;
        string length;

        for (char c : compressedString) {
            if (c >= '0' && c <= '9') {
                length += c;
            } else {
                if (hasNewChar) {
                    st.emplace_back(newChar, stoi(length));
                }

                hasNewChar = true;
                newChar = c;
                length.clear();
            }
        }

        if (hasNewChar) {
            st.emplace_back(newChar, stoi(length));
        }

        while (index < st.size() && st[index].second <= 0) {
            ++index;
        }
    }
    char next()
    {
        if (!hasNext()) {
            return ' ';
        } else {
            char c = st[index].first;
            st[index].second--;

            while (index < st.size() && st[index].second == 0) {
                ++index;
            }

            return c;
        }
    }
    bool hasNext()
    {
        return index < st.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */