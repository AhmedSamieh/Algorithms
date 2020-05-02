class Trie
{
    set<string> s;
public:
    /** Initialize your data structure here. */
    Trie()
    {

    }

    /** Inserts a word into the trie. */
    void insert(string word)
    {
        s.insert(word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word)
    {
        return s.find(word) != s.end();
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix)
    {
        auto iter = s.lower_bound(prefix);

        if (iter == s.end() || iter->rfind(prefix, 0) != 0) {
            return false;
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */