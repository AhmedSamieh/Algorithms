class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        const char alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                                 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                 'w', 'x', 'y', 'z'
                                };
        unordered_set<char> good(alphabet, alphabet + size(alphabet));
        unordered_set<string> s(banned.begin(), banned.end());
        map<string, int> m;

        for (int i = 0; i < paragraph.size(); ++i) {
            int j;

            for (j = i; j < paragraph.size() && good.find(tolower(paragraph[j])) != good.end(); ++j);

            if (j == paragraph.size() || i < j) {
                string word = paragraph.substr(i, j - i);
                for_each(word.begin(), word.end(), [](char &c) {
                    c = tolower(c);
                });

                if (s.find(word) == s.end()) {
                    m[word]++;
                }
            }

            i = j;
        }

        int max = 0;
        string ret;

        for (auto &i : m) {
            if (i.second > max) {
                max = i.second;
                ret = i.first;
            }
        }

        return ret;
    }
};
